#include <array>
#include <benchmark/benchmark.h>
#include <iostream>
#include <random>
#include <vector>
#include <queue>

template <typename T>
static int binary_search(const T *data, int len, const T &x) {
  long lo = 0, hi = len - 1, mid;
  while (lo <= hi) {
    mid = (lo + hi) >> 1;
    if (data[mid] == x) {
      return mid;
    } else if (data[mid] < x) {
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }
  return -1;
}

template <typename T>
static int lower_bound_v1(const T *data, int len, const T &x) {
  if (!len || x > data[len - 1])
    return len;

  const T *base = data;
  while (len > 1) {
    int half = (len >> 1);
    if (base[half - 1] < x) {
      base += half;
      len -= half;
    } else {
      len -= half;
    }
  }

  return base - data;
}

template <typename T>
static int binary_search_v1(const T *data, int len, const T &x) {
  int i = lower_bound_v1(data, len, x);
  return (i == len || data[i] != x) ? -1 : i;
}

template <typename T>
static int lower_bound_v2(const T *data, int len, const T &x) {
  if (!len || x > data[len - 1])
    return len;

  const T *base = data;
  while (len > 1) {
    int half = (len >> 1);
    base += half * (base[half - 1] < x);
    len -= half;
  }

  return base - data;
}

template <typename T>
static int binary_search_v2(const T *data, int len, const T &x) {
  int i = lower_bound_v2(data, len, x);
  return (i == len || data[i] != x) ? -1 : i;
}

template <typename T>
static int lower_bound_v3(const T *data, int len, const T &x) {
  if (!len || x > data[len - 1])
    return len;

  const T *base = data;
  while (len > 1) {
    int half = (len >> 1);
    __builtin_prefetch(base + (half >> 1) - 1);
    __builtin_prefetch(base + half + (half >> 1) - 1);
    base += half * (base[half - 1] < x);
    len -= half;
  }

  return base - data;
}

template <typename T>
static int binary_search_v3(const T *data, int len, const T &x) {
  int i = lower_bound_v3(data, len, x);
  return (i == len || data[i] != x) ? -1 : i;
}

using BinarySearcher = int (*)(const int *, int, const int &);

std::array<BinarySearcher, 4> binary_searchers{
    binary_search<int>, binary_search_v1<int>, binary_search_v2<int>,
    binary_search_v3<int>};

class Eytzinger {
public:
  struct zpair {
    int val = -1;
    int idx = -1;
  };

  static constexpr int block_size = 64 / sizeof(zpair);

  Eytzinger(const std::vector<int> &vec) : z_(vec.size() + 1) { build(vec); }

  int search(int target) {
    auto zp = search_(target);
    return (zp.val == target) ? zp.idx : -1;
  }

private:
  void build(const std::vector<int> &vec) {
    int i = 1;
    std::queue<std::pair<int, int>> q;
    q.push({0, vec.size()});

    while (!q.empty()) {
      auto pair = q.front();
      q.pop();
      long lo = pair.first, hi = pair.second;
      if (lo < hi) {
        int mid = (lo + hi) >> 1;
        z_[i].idx = mid;
        z_[i].val = vec[mid];
        ++i;

        q.push({lo, mid});
        q.push({mid + 1, hi});
      }
    }
  }

  inline zpair search_(int target) {
    long k = 1;
    while (k < (int)z_.size()) {
      __builtin_prefetch(z_.data() + k * block_size);
      k = (k << 1) + (z_[k].val < target);
    }
    k >>= __builtin_ffs(~k);
    return z_[k];
  }

private:
  alignas(64) std::vector<zpair> z_;
};

static void BM_eytzinger_binary_search(benchmark::State &state) {
  std::random_device rd;
  std::mt19937 gen(rd());
  auto len = state.range(0);
  std::uniform_int_distribution<long> dist(-1024, len << 1);
  std::vector<int> arr(state.range(0));
  std::iota(arr.begin(), arr.end(), 0);
  Eytzinger earr(arr);

  int sum = 0;
  for (auto _ : state) {
    int x = dist(gen);
    sum += earr.search(x);
  }
  benchmark::DoNotOptimize(sum);
}

BENCHMARK(BM_eytzinger_binary_search)->RangeMultiplier(2)->Range(2, 1 << 30);

static void BM_binary_search(benchmark::State &state) {
  std::random_device rd;
  std::mt19937 gen(rd());
  auto binary_search = binary_searchers[state.range(0)];
  auto len = state.range(1);
  std::uniform_int_distribution<long> dist(-1024, len << 1);
  std::vector<int> arr(state.range(1));
  std::iota(arr.begin(), arr.end(), 0);

  int sum = 0;
  for (auto _ : state) {
    int x = dist(gen);
    sum += binary_search(arr.data(), arr.size(), x);
  }
  benchmark::DoNotOptimize(sum);
}

BENCHMARK(BM_binary_search)
    ->ArgsProduct({benchmark::CreateDenseRange(0, 3, /*step*/ 1), benchmark::CreateRange(2, 1 << 30, /*multi=*/2)});

int main(int argc, char **argv) {
  std::vector<int> nums{1, 3, 5, 7, 9, 10};
  Eytzinger earr(nums);

  for (int i = -1; i < 13; ++i) {
    int a = binary_search(nums.data(), nums.size(), i);
    int b = binary_search_v1(nums.data(), nums.size(), i);
    int c = binary_search_v2(nums.data(), nums.size(), i);
    int d = binary_search_v3(nums.data(), nums.size(), i);
    int e = earr.search(i);
    assert(a == b);
    assert(b == c);
    assert(c == d);
    assert(d == e);
  }

  benchmark::Initialize(&argc, argv);
  benchmark::RunSpecifiedBenchmarks();

  return 0;
}
