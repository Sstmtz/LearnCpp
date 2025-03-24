#include <compare>
#include <iostream>

int main() {
    int                  i {42};
    std::strong_ordering result {i <=> 0};
    if (result == std::strong_ordering::less) {
        std::cout << "less" << '\n';
    }
    if (result == std::strong_ordering::greater) {
        std::cout << "greater" << '\n';
    }
    if (result == std::strong_ordering::equal) {
        std::cout << "equal" << '\n';
    }

    // or using named comparison functions:
    if (std::is_lt(result)) {

        std::cout << "less" << '\n';
    }
    if (std::is_gt(result)) {

        std::cout << "greater" << '\n';
    }
    if (std::is_eq(result)) {

        std::cout << "equal" << '\n';
    }
}

