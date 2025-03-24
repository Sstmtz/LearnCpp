#include <algorithm>
#include <iterator>
#include <ranges>
#include <string>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> data = {11, 22, 33};
    // use std::sort
    std::sort(std::begin(data), std::end(data));
    // use ranges
    std::ranges::sort(data);

    // chaining views: can transform, filter, drop, reverse...
    std::vector<int> data2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto result{data2 | std::views::filter([](auto const &value) { return value % 2 == 0; }) /* 2 4 6 8 10*/
                | std::views::transform([](auto const &value) { return value * 2; })         /* 4 8 12 16 20 */
                | std::views::drop(2)                                                        /* 12 16 20 */
                | std::views::reverse                                                        /* 20 16 12 */
                | std::views::transform([](int i) { return std::to_string(i); })};           /* "20" "16" "12" */

    // (!!check!!)
    if (!result.empty()) {
        for (auto const &element : result) {
            std::cout << element << " ";
        }
    } else {
        std::cout << "Result is empty." << std::endl;
    }
    std::cout << '\n';

    return 0;
}
