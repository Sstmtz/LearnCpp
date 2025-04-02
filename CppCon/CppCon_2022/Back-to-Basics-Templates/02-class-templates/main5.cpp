// C++11: Variadic Templates
//
// 1. Templates for a variable number of template arguments
//  - Type-Safe varargs interface
// 2. For functions and classes
// 3. Named parameter packs
//  - represent multiple arguments (types/objects)
//  - can be passed together to somewhere else

#include <iostream>
#include <string>

void print() {}

template <typename T, typename... Types>
void print(T firstArg, Types... args) {
    std::cout << firstArg << '\n'; // output first argument
    print(args...);                // call print() for all other arguments
}

int main() {
    std::string str = "world";
    print("hello", 7.5, str);

    std::cout << "hello" << '\n';
    std::cout << 7.5 << '\n';
    std::cout << str << '\n';
}
