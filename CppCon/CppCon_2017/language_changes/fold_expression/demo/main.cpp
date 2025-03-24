#include <iostream>

// before C++17:
auto sum() {
    return 0;
}

template <typename N>
auto sum(N n) {
    return n;
}

template <typename N0, typename... Ns>
auto sum(N0 n0, Ns... ns) {
    return n0 + sum(ns...);
}

// since C++17:
template <typename... Ns>
auto sum(Ns... ns) {
    return (ns + ... + 0);
}

int main() {
    // right hold: 3.14 + (1e7 + (-42 + (17 + 0)))
    auto a = sum(3.14, 1e7, -42, 17);
    std::cout << a << '\n';
}
