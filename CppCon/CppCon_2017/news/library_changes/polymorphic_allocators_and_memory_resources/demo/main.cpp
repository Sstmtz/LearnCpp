#include <memory>
#include <memory_resource> // *
#include <vector>

// before C++17:
std::vector<int, std::allocator<int>>          a;
std::vector<int, my_memory_pool<int>>          b;
std::vector<int, my_slab_allocator<int, 1024>> c;
std::vector<int, my_slab_allocator<int, 4096>> d;

// since C++17:
std::vector<int, std::pmr::allocator<int>> a;
std::pmr::unsynchronized_pool_resource     p;
std::vector<int, std::pmr::allocator<int>> b(&p);
my_slab_allocator<1024>                    s1k;
std::vector<int, std::pmr::allocator<int>> c(&s1k);
my_slab_allocator<4096>                    s4k;
std::vector<int, std::pmr::allocator<int>> d(&s4k);
