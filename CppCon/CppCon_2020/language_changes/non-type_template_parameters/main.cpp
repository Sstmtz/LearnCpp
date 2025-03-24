// #include "ctre-unicode.hpp"
// #include "unicode-db.hpp"
#include "ctre.hpp"
#include <iostream>
#include <string_view>

// Non-type template parameters had limitations, e.g. no string literals
// C++20 relaxes these limitations:
// 1. allow floating-point types.
// 2. allow class types (but with some restrictions)

// E.g. use-case: pass string literals as non-type template parameters
// The CTRE library: compile-time string literals to create regular expression
// parsers at compile time instead of at run time

using namespace std::string_view_literals;

int main() {
    auto input = "123,456,768"sv;

    for (auto match : ctre::search_all<"([0-9]+),?">(input)) {
        std::cout << std::string_view {match.get<0>()} << "\n";
    }
}
