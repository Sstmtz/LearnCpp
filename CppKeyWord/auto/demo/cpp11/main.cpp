// Variable declarations
// Function declarations
// Parameter declarations

#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {

    // since C++11
    // `auto` can deduce the type of a variable from the value on the right side of the `=`.

    auto x = 5;                // OK: x has type int
    auto const *z = &x, u = 6; // OK: v has type const int*, u has type const int
    static auto y = 0.0;       // OK: y has type double
    // auto i;                 // ERROR: deduced type with `auto` requires an initializer
    // auto f() -> int, i = 0; // ERROR: declares a function and a variable with `auto`
    // auto a = 5, b = {1, 2}; // ERROR: different types for `auto`

    // Typically, container types can be very long (especially when nested),
    // so declaring their type as `auto` can enhance readability."

    std::map<std::string, int> tab;
    // C++98
    // std::map<std::string, int>::iterator it = tab.find("key");
    // C++11
    auto it = tab.find("key");

    std::vector<int> v = {10, 20, 30, 40, 50};
    // C++98
    // for (std::vector<int>::iterator pos = v.begin(); pos < v.end(); ++pos) {
    //     std::cout << *pos << '\n';
    // }
    // C++11:
    for (auto pos = v.begin(); pos < v.end(); ++pos) {
        std::cout << *pos << '\n';
    }

    return 0;
}
