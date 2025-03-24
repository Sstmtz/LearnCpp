#include <span>

int main() {
    int                data[42];
    std::span<int, 42> a {data}; // fixed-size(compile-time): 42 ints
    std::span<int>     b {data}; // dynamic-size(run-time): 42 ints
    // std::span<int, 50> c{data}; // compilation error
    std::span<int const> d {data}; // dynamic-size(run-rime): 42 ints (readonly span)
}
