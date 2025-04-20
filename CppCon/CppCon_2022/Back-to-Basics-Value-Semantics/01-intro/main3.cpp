// Reference Semantics: std::span

#include <cstdlib>
#include <iostream>
#include <span>
#include <vector>

void print(std::vector<int> const &vec);

int main() {
    std::vector<int> v {1, 2, 3, 5};

    std::vector<int> const w {v};
    std::span<int> const s {v}; // -> std::span<int const> const

    // w[2] = 99; // ERROR -> Value Semantics
    s[2] = 99; // OK -> Reference Semantics

    print(v);  // prints: 1 2 99 4

    return EXIT_SUCCESS;
}

void print(std::vector<int> const &vec) {
    for (int const &v : vec) {
        std::cout << v << ' ';
    }
    std::cout << '\n';
}
