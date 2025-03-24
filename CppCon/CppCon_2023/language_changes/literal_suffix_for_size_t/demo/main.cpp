
// Existing interger literal suffixes: U, L, UL, LL, and ULL.
// New:
// uz or UZ: creates a std::size_t interger literal
// z or Z: creates a signed type corresponding to std::size_t

#include <vector>

int main() {
    std::vector data {11, 22, 33};

    // compile error: `i` is decuded as `int`, but `count` is `std::size_t`
    for (auto i = 0, count = data.size(); i < count; ++i) {
        /* ... */
    }
    // solution: use uz literal
    for (auto i = 0uz, count = data.size(); i < count; ++i) {
        /* ... */
    }
}
