#include <iostream>
#include <optional>
#include <print>
#include <string>

// transform(F)
// and_then(F)
// or_else(F)

std::optional<int> Parse(std::string const &s) {
    try {
        return std::stoi(s);
    } catch (...) {
        return {};
    }
}

int main() {
    while (true) {
        std::string s;
        std::getline(std::cin, s);
        auto result = Parse(s)
                          .and_then([](int value) -> std::optional<int> {
                              return value * 2;
                          })
                          .transform([](int value) {
                              return std::to_string(value);
                          })
                          .or_else([] {
                              return std::optional<std::string>("No Integer");
                          });
        std::println("{}", *result);
    }
}
