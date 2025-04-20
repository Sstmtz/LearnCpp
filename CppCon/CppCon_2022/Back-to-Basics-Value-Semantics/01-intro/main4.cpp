// Reference Semantics: std::span

#include <cstdlib>
#include <iostream>
#include <span>
#include <vector>

void print(std::vector<int> const &vec);

// It is reasonable to have a std::span as function argument
void print(std::span<int> s);

int main() {
    std::vector<int> v {1, 2, 3, 5};

    // It is dangerous to keep a std::span around
    // for longer (also as data member)
    std::span<int> const s {v};

    v = {5, 6, 7, 8, 9}; //    -> Causes an internal reallocation
    s[2] = 99;           // OK -> but Triggers UB!

    print(s);            // maybe prints: 1 2 99 4

    return EXIT_SUCCESS;
}

void print(std::vector<int> const &vec) {
    for (int const &v : vec) {
        std::cout << v << ' ';
    }
    std::cout << '\n';
}

void print(std::span<int> spn) {
    for (int const s : spn) {
        std::cout << s << ' ';
    }
    std::cout << '\n';
}
