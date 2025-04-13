#include <iostream>

// since C++14:
// Function return type deduction was introduced, which automatically deduces the return type of a
// function based on the return expression within the function, no longer enforcing the use of
// trailing(->) return types

auto square(int x) {
    return x * x;
}

// equivalent to:
// int square(int x) {
//     return x * x;
// }

// If there is no return statement in the function, `auto` will be automatically deduced as `void`.
auto print() {
    std::cout << "Hello World" << '\n';
}

// equivalent to:
// void print() {
//     std::cout << "Hello World" << '\n';
// }

// If there are multiple return statements, they must all return the same type;
// otherwise, an error will occur.
// auto f(int x) {
//     if (x > 0) {
//         return 1;    // int
//     } else {
//         return 3.14; // double
//     }
// } // Error: Ambiguous, unable to determine whether `auto` should be deduced as `int` or `double`.

// Another drawback of `auto` is that it cannot be used in cases of 'separate declaration and
// definition (similar to template functions). This is because deducing the `auto` type requires
// knowledge of the function body to determine the type of the return expression. Therefore, when
// the `auto` return type is used in a non-definition declaration of a function, it will result in a
// direct error."

// Therefore, `auto` is typically only suitable for 'in-place defined' `inline` functions in header
// files and is not suitable for functions that require 'separate .cpp files.'

int main() {
    return 0;
}
