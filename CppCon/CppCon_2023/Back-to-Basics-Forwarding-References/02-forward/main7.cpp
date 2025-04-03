#include <iostream>
#include <utility>

// Prefect Forwarding

// Forwarding reference preserve the value category. of a function arugment,
// making it possible to forward it by means of std::forward

void f(int &) {
    std::cout << "lvalue\n";
}

void f(int const &) {
    std::cout << "const lvalue\n";
}

void f(int &&) {
    std::cout << "rvalue\n";
}

template <typename T>
void wrapper(T &&v) {
    // do_something();
    f(std::forward<T>(v));
}

// std::forward<T>(t) converts t to rvalue reference only if rvalue.
