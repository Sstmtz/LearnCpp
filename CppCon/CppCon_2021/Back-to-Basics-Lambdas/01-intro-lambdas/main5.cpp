// C++14: Named Generic Lambdas

#include <iostream>
#include <string>
#include <vector>

int main() {
    // define a generic lambda object:
    auto twice = [](auto const &x) {
        return x + x;
    };

    // and call/use it:
    // Lambda is compiled for different parameter types
    auto i = twice(3);                  // `i` is int => 6
    auto d = twice(1.7);                // `d` is double => 3.14
    auto s = twice(std::string {"hi"}); // `s` is std::string => "hihi"
    // auto t = twice("hi");               // ERROR: const char[3] + const char[3]

    std::vector<std::string> coll {
      "Here", "are", "some", "cities", "Berlin", "LA", "London", "Cologne"};

    // print all elements of any kind:
    for (auto const &elem : coll) {
        std::cout << "- " << twice(elem) << '\n';
    }
}
