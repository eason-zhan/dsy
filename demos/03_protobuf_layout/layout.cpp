#include "proto/stats.pb.h"
#include <iostream>

void test_ad_stat() {

  std::cout << " sizeof(::proto::ad::Stats) : " << sizeof(::proto::ad::Stats)
            << std::endl;
  std::cout << " sizeof(::proto::ad::Stats::Impl_) : "
            << sizeof(::proto::ad::Stats::Impl_) << std::endl;

  std::cout << "bucket " << offsetof(::proto::ad::Stats::Impl_, bucket_)
            << std::endl;
  std::cout << "bucket_cache_atomic "
            << offsetof(::proto::ad::Stats::Impl_, _bucket_cached_byte_size_)
            << std::endl;
  std::cout << "hour_bucket "
            << offsetof(::proto::ad::Stats::Impl_, hour_bucket_) << std::endl;
  std::cout << "hour_bucket_cache_atomic "
            << offsetof(::proto::ad::Stats::Impl_,
                        _hour_bucket_cached_byte_size_)
            << std::endl;
  std::cout << "acc_bucket " << offsetof(::proto::ad::Stats::Impl_, acc_bucket_)
            << std::endl;
  std::cout << "acc_bucket_cache_atomic "
            << offsetof(::proto::ad::Stats::Impl_,
                        _acc_bucket_cached_byte_size_)
            << std::endl;
  std::cout << "ts_ " << offsetof(::proto::ad::Stats::Impl_, ts_) << std::endl;
  std::cout << "show " << offsetof(::proto::ad::Stats::Impl_, show_)
            << std::endl;
  std::cout << "click " << offsetof(::proto::ad::Stats::Impl_, click_)
            << std::endl;
  std::cout << "cost " << offsetof(::proto::ad::Stats::Impl_, cost_)
            << std::endl;
}

void test_ad_stat_opt() {
  std::cout << " sizeof(::proto::ad::StatsOpt) : "
            << sizeof(::proto::ad::StatsOpt) << std::endl;
  std::cout << " sizeof(::proto::ad::StatsOpt::Impl_) : "
            << sizeof(::proto::ad::StatsOpt::Impl_) << std::endl;

  std::cout << "bucket " << offsetof(::proto::ad::StatsOpt::Impl_, bucket_)
            << std::endl;
  std::cout << "bucket_cache_atomic "
            << offsetof(::proto::ad::StatsOpt::Impl_, _bucket_cached_byte_size_)
            << std::endl;
  std::cout << "hour_bucket "
            << offsetof(::proto::ad::StatsOpt::Impl_, hour_bucket_)
            << std::endl;
  std::cout << "hour_bucket_cache_atomic "
            << offsetof(::proto::ad::StatsOpt::Impl_,
                        _hour_bucket_cached_byte_size_)
            << std::endl;
  std::cout << "ts_ " << offsetof(::proto::ad::StatsOpt::Impl_, ts_)
            << std::endl;
  std::cout << "show " << offsetof(::proto::ad::StatsOpt::Impl_, show_)
            << std::endl;
  std::cout << "click " << offsetof(::proto::ad::StatsOpt::Impl_, click_)
            << std::endl;
  std::cout << "cost " << offsetof(::proto::ad::StatsOpt::Impl_, cost_)
            << std::endl;
}

int main() {
  test_ad_stat();
  test_ad_stat_opt();
  return 0;
}
