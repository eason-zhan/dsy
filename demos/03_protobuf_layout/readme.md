## How to run

```bash
$ proto --cpp_out=./ proto/stats.proto
$ g++ -O2 -std=c++17 layout.cpp -I./
```

Note: After `protoc` compilation, you need to change `proto/stats.pb.h` file, set Impl_ to be public.

