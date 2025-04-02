
// C++11/17: Dealing with Variadic Templates

#include <iostream>

// Note that the following code does not compile:
// template <typename T, typename... Types>
// void print(T firstArg, Types... args) {
//     std::cout << firstArg << '\n';
//
//     if (sizeof...(args) > 0) { // if args is not empty
//         print(args...);        // ERROR: if no print() for no arguments declared
//     }
// }

// since C++17:
template <typename T, typename... Types>
void print(T firstArg, Types... args) {
    std::cout << firstArg << '\n';

    if constexpr (sizeof...(args) > 0) { // if args is not empty
        print(args...);                  // OK: if no print() for no arguments declared
    }
}
