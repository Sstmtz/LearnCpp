#include <iostream>
#include <utility>

// Forwarding function parameters

void f(int &) {
    std::cout << "lvalue\n";
}

void f(int const &) {
    std::cout << "const lvalue\n";
}

void f(int &&) {
    std::cout << "rvalue\n";
}

void wrapper(int &v) {
    // do_something();
    f(v);
}

void wrapper(int const &v) {
    // do_something();
    f(v);
}

void wrapper(int &&v) {
    // do_something();
    f(std::move(v));
}
