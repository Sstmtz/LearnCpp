#include <print>
#include <ranges>
#include <string>
#include <vector>

int main() {

    // Use views::split() and views::transform() to create a view
    // containing individual words of a string, and then convert
    // the resulting view to a vector of strings containing all the words
    std::string lorem {"Lorem ipsum dolor sit amet"};

    auto words {lorem | std::views::split(' ') | std::views::transform([](auto const &v) {
                    return std::string {std::from_range, v};
                })
                | std::ranges::to<std::vector>()};

    std::println("{:n:?}", words); // "Lorem", "ipsum", "dolor", "sit", "amet"
}
