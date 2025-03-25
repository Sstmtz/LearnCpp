#include <algorithm>
#include <print>
#include <ranges>
#include <vector>

// Several folding algorithm:
// ranges::fold_left()
// ranges::fold_left_first()
// ranges::fold_right
// ranges::fold_right_last()
// ranges::left_with_iter()
// ranges::left_first_with_iter()

int main() {
    std::vector v {11, 22, 33, 44};
    std::println("{}", std::ranges::fold_left(v, 0, std::plus())); // 110
}
