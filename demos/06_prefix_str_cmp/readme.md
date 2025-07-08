## Compiler not good at ?

I just want to optimize this code below. The reverse matching pattern springs to my mind at first. Then I thougth leverage the SIMD maybe be a better way. After watched the Mat GodBolt Video about "Compiler are good at", I want to give the compiler a try, to let it to trigger the vectorizaiton automaically. But it seems like the compiler just can't aware this pattern.

```c++
bool is_citadel_node_zone(std::string_view name)
{
    return name == "citadel_node"sv || name == "citadel_node_int64"sv ||
           name == "citadel_node_blob"sv || name == "citadel_node_float"sv;
}
```

Detail Compiler Explorer.

https://godbolt.org/z/71r5qdxjP


With the bench code.
