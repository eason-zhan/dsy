#include <chrono>
#include <iostream>
#include <random>
#include <array>
#include <iomanip>
#include <string_view>
#include <vector>

// ─────────────────────────────────────────────────────────────
// 1. helpers
// ─────────────────────────────────────────────────────────────
constexpr uint64_t fnv1a64(std::string_view s) {
    uint64_t h = 0xcbf29ce484222325ull;
    for (unsigned char c : s) {
        h ^= c;
        h *= 0x100000001b3ull;
    }
    return h;
}
constexpr uint32_t fnv1a32(std::string_view s) {
    uint32_t h = 0x811c9dc5u;
    for (unsigned char c : s) {
        h ^= c;
        h *= 0x01000193u;
    }
    return h;
}


// 2. constants (64-bit + 32-bit)
alignas(64) static constexpr std::array<uint64_t, 4> ZONES64{
    fnv1a64("query_container"),
    fnv1a64("query_container_int64"),
    fnv1a64("query_container_blob"),
    fnv1a64("query_container_float")
};

alignas(64) static constexpr std::array<uint32_t, 4> ZONES32{
    fnv1a32("query_container"),
    fnv1a32("query_container_int64"),
    fnv1a32("query_container_blob"),
    fnv1a32("query_container_float")
};

// ─────────────────────────────────────────────────────────────
// 3. four candidate implementations
// ─────────────────────────────────────────────────────────────
[[gnu::always_inline]] inline
bool is_query_container_zone_linear(uint64_t k) {
    return k == ZONES64[0] || k == ZONES64[1] ||
           k == ZONES64[2] || k == ZONES64[3];
}

// [[gnu::target("avx2")]]
// [[gnu::optimize("unroll-loops")]]
// bool is_query_container_zone_simd_intrin(uint64_t k) {
//     __m256i key  = _mm256_set1_epi64x(static_cast<long long>(k));
//     __m256i vals = _mm256_load_si256(reinterpret_cast<const __m256i*>(ZONES64.data()));
//     __m256i cmp  = _mm256_cmpeq_epi64(key, vals);
//     return !_mm256_testz_si256(cmp, cmp);        // vptest
// }
//
bool is_query_container_zone_no_early(uint32_t k) {
    bool found = false;
    for (std::size_t i = 0; i < ZONES32.size(); ++i)
        found |= (ZONES32[i] == k);
    return found;
}

// branch-free scalar (32-bit) using std::array
bool is_query_container_zone_branchless(uint32_t k) {
    uint32_t acc = 0;
    for (uint32_t v : ZONES32)
        acc |= (v & k);
    return acc == 0;
}

// ─────────────────────────────────────────────────────────────
// 4. timing harness
// ─────────────────────────────────────────────────────────────
template <class F> static
double bench(const std::vector<uint64_t>& keys, F&& fn) {
    auto start = std::chrono::high_resolution_clock::now();
    std::size_t dummy = 0;
    for (uint64_t k : keys) dummy += fn(k);
    auto end = std::chrono::high_resolution_clock::now();
    volatile std::size_t blackhole = dummy; (void)blackhole;
    auto elapsed_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    return elapsed_ns.count();
}

int main(int argc, char** argv) {
    std::size_t N = (argc > 1) ? std::stoull(argv[1]) : 5'000'000ULL;

    // build a 50/50 hit/miss workload
    std::mt19937_64 rng(42);
    std::uniform_int_distribution<int> pick(0, 5);
    std::vector<uint64_t> keys;
    keys.reserve(N);
    for (std::size_t i = 0; i < N; ++i) {
        int p = pick(rng);
        if (p < 4) keys.push_back(ZONES64[p]);          // guaranteed hit
        else       keys.push_back(rng());               // random miss
    }

    std::cout << "Probes: " << N/1e6 << " M\n";
    std::cout << std::fixed << std::setprecision(3);

    std::cout << " linear          : " << bench(keys, is_query_container_zone_linear)      << " ns\n";
    // std::cout << " simd intrinsics : " << bench(keys, is_query_container_zone_simd_intrin) << " s\n";
    std::cout << " no-early (32)   : " << bench(keys, [](uint64_t k){return is_query_container_zone_no_early(static_cast<uint32_t>(k));}) << " ns\n";
    std::cout << " branchless (32) : " << bench(keys, [](uint64_t k){return is_query_container_zone_branchless(static_cast<uint32_t>(k));}) << " ns\n";
}


