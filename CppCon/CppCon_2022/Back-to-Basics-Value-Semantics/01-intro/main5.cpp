// Reference Semantics: Reference Parameter

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <span>
#include <vector>

void print(std::span<int const> s);

int main() {
    std::vector<int> vec = {1, -3, 27, 42, 4, -8, 22, 42, 37, 4, 18, 9};

    print(vec); // prints: 1 -3 27 42 4 -8 22 42 37 4 18 9

    // Determining the maximum element in the range 'vec'
    auto const pos = std::max_element(std::begin(vec), std::end(vec));

    // Removing all maximum elements
    vec.erase(std::remove(std::begin(vec), std::end(vec), *pos), std::end(vec));

    print(vec); // prints: 1 -3 27 4 -8 22 42 37 18 9 (delete 42 and 4)

    return EXIT_SUCCESS;
}

void print(std::span<int const> spn) {
    for (int const s : spn) {
        std::cout << s << ' ';
    }
    std::cout << '\n';
}
