#include <print>
#include <string>

// check if a string contains another string

int main() {
    std::string haystack {"Hello World!"};
    std::println("{}", haystack.contains("World"));   // true
    std::println("{}", haystack.contains("!"));       // true
    using namespace std::string_view_literals;
    std::println("{}", haystack.contains("Hello"sv)); // true
}
