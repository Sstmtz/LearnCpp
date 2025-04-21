// Aggregates in C++20

// Originally, using direct-initialization meant that `std::make_unique` couldn't easily initialize
// aggregates

// However, as of C++20, aggregates can also be initialized with parentheses:
#include <cstddef>

class demo_str {
private:
    std::size_t stored_length;
    char *actual_str;
};

struct S {
    int x;
    double y;
    demo_str ds;
};

S obj(5, 6.7, "LaForge");
