#include "tracknew.hpp"
#include <iostream>
#include <memory_resource>
#include <string>
#include <vector>

void raw_memory() {
  std::cout << "[+] Raw New:\n";
  TrackNew::reset();
  std::vector<std::string> vs;
  for (int i = 0; i < 1000; ++i) {
    vs.emplace_back("Just a non-SSO string");
  }
  TrackNew::status();
  std::cout << "vec_size = " << vs.size() << " ele size = " << sizeof(vs[0])
            << "\n\n";
}

void pmr_pool_1() {
  std::cout << "[+] PMR_1: \n";
  TrackNew::reset();

  // array memory is on the stack
  std::array<std::byte, 200'000> buf;
  std::pmr::monotonic_buffer_resource pmr_pool{buf.data(), buf.size()};
  std::pmr::vector<std::string> vs{&pmr_pool};

  for (int i = 0; i < 1000; ++i) {
    vs.emplace_back("Just a non-SSO string");
  }
  TrackNew::status();
  std::cout << "vec_size = " << vs.size() << " ele size = " << sizeof(vs[0])
            << "\n\n";
}

void pmr_pool_2_propagate() {
  std::cout << "[+] PMR_2: \n";
  TrackNew::reset();

  // array memory is on the stack
  std::array<std::byte, 200'000> buf;
  std::pmr::monotonic_buffer_resource pmr_pool{buf.data(), buf.size()};
  std::pmr::vector<std::pmr::string> vs{&pmr_pool};

  for (int i = 0; i < 1000; ++i) {
    vs.emplace_back("Just a non-SSO string");
  }
  TrackNew::status();
  std::cout << "vec_size = " << vs.size() << " ele size = " << sizeof(vs[0])
            << "\n\n";
}

void pmr_pool_3_variadic_size() {
  std::cout << "[+] PMR_3: \n";
  // allocate some memory on the stack
  std::array<std::byte, 200'000> buf;

  for (int num : {1000, 2000, 500, 2000, 3000, 50'000, 1000}) {

    TrackNew::reset();

    // array memory is on the stack
    std::pmr::monotonic_buffer_resource pmr_pool{buf.data(), buf.size()};
    std::pmr::vector<std::pmr::string> vs{&pmr_pool};

    for (int i = 0; i < num; ++i) {
      vs.emplace_back("Just a non-SSO string");
    }
    TrackNew::status();
    std::cout << "vec_size = " << vs.size() << " ele size = " << sizeof(vs[0])
              << "\n\n";
  }
}

int main(int argc, char *argv[]) {
  raw_memory();
  pmr_pool_1();
  pmr_pool_2_propagate();
  pmr_pool_3_variadic_size();
  return 0;
}
