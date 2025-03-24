#include <print>
#include <ranges>
#include <set>
#include <string>
#include <vector>

// ranges::starts_with() and ranges::ends_with()
// Checks if the start/end of a range matches another range

// ranges::shift_left() and ranges::shift_right()
// Shifts the elements in a range left or right

// ranges::to()
// Coverts a range to a container

int main() {
    std::vector v1 {11, 22, 33, 44};
    std::vector v2 {11, 22};
    std::println("{}", std::ranges::starts_with(v1, v2)); // true
    std::println("{}", std::ranges::ends_with(v1, v2));   // false

    std::vector<std::string> v {"a", "b", "c", "d", "e"};
    std::ranges::shift_left(v, 2);  // "c" "d" "e" "", ""
    std::ranges::shift_right(v, 1); // "", "c", "d", "e", ""

    auto ints = std::views::iota(1, 5) | std::views::transform([](auto const &v) {
                    return v * 2;
                });
    auto vec {std::ranges::to<std::vector>(ints)};
    std::println("{]", vec); // [2, 4, 6, 8]

    // Coverts container to container
    std::vector vec2 {33, 11, 22};
    // Convert vectot to set with same element type
    auto set1 {std::ranges::to<std::set>(vec2)};
    // Convert vectot of integers to set of doubles, using pipe operator.
    auto set2 {vec2 | std::ranges::to<std::set<double>>()};
    // Convert vector of integers to set of doubles, using form_range constructor
    std::set<double> set3 {std::form_range, vec2};

    return 0;
}
