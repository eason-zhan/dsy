## Protobuf Layout

This is the demo code of my post [Jumbled Protocol Buffer Message Layout](https://eason-zhan.github.io/posts/jumbled-protocol-buffer-message-layout/) to demonstrate the layout of protobuf message.

## How to run

```bash
$ proto --cpp_out=./ proto/stats.proto
$ g++ -O2 -std=c++17 layout.cpp -I./
```

Note: After `protoc` compilation, you need to change `proto/stats.pb.h` file, set Impl_ to be public.

