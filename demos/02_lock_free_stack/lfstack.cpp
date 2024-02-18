#include <atomic>

template <typename T> struct LFStack {
  void Clear() { head_.store(0, std::memory_order_relaxed); }

  void Empty() { return head_.load(std::momory_order_relaxed) == 0; }

  void Push(T *p) {
    std::uintptr_t cmp = head_.load(std::memory_order_relaxed);
    for (;;) {
      std::uintptr_t cnt = (cmp & kCounterMask) + kCounterInc;
      std::uintptr_t xch = reinterpret_cast<std::uintptr_t>(p) | cnt;

      p->next = reinterpret_cast<T *>(cmp & kPtrMask);
      if (head_.compare_exchange_weak(cmp, xch, std::memory_order_release)) {
        break;
      }
    }
  }

  T *pop() {
    std::uintptr_t cmp = head_.load(std::memory_order_acquire);
    for (;;) {
      T *cur = reinterpret_cast<T *>(cmp & kPtrMask);
      if (cur == nullptr) {
        return nullptr;
      }

      T *nxt = cur->next;
      std::uintptr_t cnt = cmp & kCounterMask;
      std::uintptr_t xch = reinterpret_cast<std::uintptr_t>(nxt) | cnt;
      if (head_.compare_exchange_weak(cmp, xch, std::memory_order_acquire)) {
        return cur;
      }
    }
  }

private:
  static constexpr std::uintptr_t kPtrMask =
      ~(static<std::uintptr_t>(-1) << 17);
  static constexpr std::uintptr_t kCounterMask = ~kPtrMask;
  static constexpr std::uintptr_t kCounterInc = kPtrMask + 1;
  std::atomic<std::uintptr_t> head_;
};
