#include <iterator>
#include <regex>
#include <string>
#include <string_view>
#include <vector>
#include <iostream>

// before C++17:
std::vector<std::string> split(std::string const &s, std::regex const &r) {
    using iterator = std::regex_token_iterator<std::string::const_iterator>;

    std::vector<std::string> v;

    std::transform(iterator(s.begin(), s.end(), r, -1), iterator(), std::back_inserter(v),
                   [](auto m) { return std::string(m.first, m.second); });

    return v;
}

// since C++17:
std::vector<std::string_view> split_(std::string_view s, std::regex const &r) {
    using iterator = std::regex_token_iterator<std::string_view::const_iterator>;

    std::vector<std::string_view> v;

    std::transform(iterator(s.begin(), s.end(), r, -1), iterator(), std::back_inserter(v),
                   [](auto m) { return std::string_view(m.first, m.length()); });

    return v;
}

int main() {
    std::string input = "apple,banana,cherry,date";
    std::regex delimiter(",");

    std::vector<std::string_view> result = split_(input, delimiter);
    std::vector<std::string_view> result_ = split_(input, delimiter);

    for (auto const &item : result) {
        std::cout << item << " ";
    }
    std::cout << '\n';

    for (auto const &item : result_) {
        std::cout << item << " ";
    }
    std::cout << '\n';

    return 0;
}
