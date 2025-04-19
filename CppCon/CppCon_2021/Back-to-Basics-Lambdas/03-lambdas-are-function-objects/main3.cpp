// Generic Functions vs. Generic Lambdas

#include <iostream>
#include <string>
#include <vector>

// Generic lambdas since C++14:
auto printLmbd = [](auto const &coll) { // Function object with generic operator()
    for (auto const &elem : coll) {
        std::cout << elem << '\n';
    }
};

// Generic functions since C++14:
// template <typename T>
// void printFunc(T const &coll) { // Function template (generic before the call)
//     for (auto const &elem : coll) {
//         std::cout << elem << '\n';
//     }
// }

// Generic functions since C++20:
void printFunc(auto const &coll) { // Function template (generic before the call)
    for (auto const &elem : coll) {
        std::cout << elem << '\n';
    }
}

int main() {
    std::vector<int> v;

    printFunc(v);
    printLmbd(v);

    printFunc<std::string>("hello"); // OK
    // printLmbd<std::string>("hello"); // ERROR: lambda is not a function template

    // call(printFunc, v);              // ERROR: we don't know the type until we call
    // call(printFunc<decltype(v)>, v); // OK: explicitly tell the type
    // call(printLmbd, v);              // OK
}
