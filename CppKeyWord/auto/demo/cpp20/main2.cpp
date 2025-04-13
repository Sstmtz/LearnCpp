#include <iostream>

void passByValue(auto x) { // int
    x = 42;
}

void passByRef(auto &x) { // int &
    x = 42;
}

void passByConstRef(auto const &x) { // int const &
    x = 42;                          // complie-time ERROR: const ref cannot assigned
}

void passByRef2(auto &x) {
    x = 42; // complie-time ERROR: const ref cannot assigned
}

void passByConstRef2(auto const &cref) {
    std::cout << cref;
}

int main() {

    int x = 1;
    passByValue(x);
    std::cout << x; // 1
    passByRef(x);
    std::cout << x; // 42

    // Due to the compatibility of `auto&` with `auto const&`,
    // calling `passByRef` will deduce the parameter type as `const int&`,
    // which will cause a compilation error for the statement `x = 42` inside the function!

    int const const_x = 1;
    passByRef2(x);       // auto = int
    passByRef2(const_x); // auto = int const

    passByConstRef(x);
    passByConstRef(42);
    // equivalent to:
    // {
    //     int const tmp = 42;
    //     passByConstRef(tmp);
    // }
}
