#include <iostream>

// since C++20:
// Has introduced template parameter deduction, allowing us to use `auto` in function parameters as
// well. Using `auto` in function parameters is essentially equivalent to declaring that parameter
// as a template parameter; it is simply a more convenient syntax.

void func1(auto x) {
    std::cout << x;
}

// equivalent to:
// template <typename T>
// void func1(T x) {
//     std::cout << x;
// }

void func2(auto const &x) {
    std::cout << x;
}

// equivalent to:
// template <typename T>
// void func2(T const &x) {
//     std::cout << x;
// }

void func3(auto &&x) {
    std::cout << x;
}

// equivalent to:
// template <typename T>
// void func3(T &&x) {
//     std::cout << x;
// }

int main() {
    func1(1);    // calls func<int>(1)
    func1(3.14); // calls func<double>(3.14)
}
