#ifndef TRACENEW_HPP_
#define TRACENEW_HPP_

#include<cstddef>
#include <cstdio>
#include <cstdlib>
#include <new>

class TrackNew {
public:
  TrackNew() {};
  TrackNew(TrackNew &&) = default;
  TrackNew(const TrackNew &) = default;
  TrackNew &operator=(TrackNew &&) = default;
  TrackNew &operator=(const TrackNew &) = default;
  ~TrackNew() {};

  static void reset() {
    n_malloc_call = 0;
    n_sum_byte = 0;
  }

  static void set_trace(bool b) {
    do_trace = b;
  }

  static void* allocate(std::size_t size, std::size_t align, const char* call) {
    ++n_malloc_call;
    n_sum_byte += size;

    void* p = nullptr;
    if (align == 0) {
      p = std::malloc(size);
    } else {
      p = std::aligned_alloc(align, size);
    }

    if (do_trace) {
      printf("#%d %s ", n_malloc_call, call);
      printf("%zu bytes,", size);
    }
    return p;
  }

  static void status() {
    printf("%d allocations for %zu bytes\n", n_malloc_call, n_sum_byte);
  }

private:
  static inline int n_malloc_call = 0;
  static inline size_t n_sum_byte = 0;
  static inline bool do_trace = false;
  static inline bool in_new = false; // don't trace output inside new overloads
};

[[nodiscard]]
void *operator new(std::size_t size) {
  return TrackNew::allocate(size, 0, "::new");
}

[[nodiscard]]
void *operator new(std::size_t size, std::align_val_t align) {
  return TrackNew::allocate(size, static_cast<size_t>(align), "::new aligned");
}

[[nodiscard]]
void* operator new[] (std::size_t size) {
  return TrackNew::allocate(size, 0, "::new[]");
}

[[nodiscard]]
void* operator new[] (std::size_t size, std::align_val_t align) {
  return TrackNew::allocate(size, static_cast<size_t>(align),
                            "::new[] aligned");
}

// ensure deallocations match:
void operator delete (void* p) noexcept {
  std::free(p);
}
void operator delete (void* p, std::size_t) noexcept {
  ::operator delete(p);
}
void operator delete (void* p, std::align_val_t) noexcept {
  std::free(p);
}
void operator delete (void* p, std::size_t,
                               std::align_val_t align) noexcept {
  ::operator delete(p, align);
}

#endif // !TRACENEW_HPP_
