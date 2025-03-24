#include <iostream>
#include <utility>

template <typename... Ts>
void print(Ts &&...ts) {
    (std::cout << ... << std::forward<Ts>(ts)) << '\n';
}

// unary right hold over the comma operator (,)
template <typename F, typename... Args>
void for_each_arg(F f, Args &&...args) {
    (f(std::forward<Args>(args)), ...);
}
