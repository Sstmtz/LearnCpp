#include <iostream>
#include <utility>

// before C++17:
template <typename T0>
void print(T0 &&t0) {
    std::cout << std::forward<T0>(t0) << '\n';
}

template <typename T0, typename... Ts>
void print(T0 &&t0, Ts &&...ts) {
    print(std::forward<T0>(t0));
    print(std::forward<Ts>(ts)...);
}

// since C++17:
template <typename T0, typename... Ts>
void print1(T0 &&t0, Ts &&...ts) {
    std::cout << std::forward<T0>(t0) << '\n';

    if constexpr (sizeof...(ts)) {
        print(std::forward<Ts>(ts)...);
    }
}

int main() {
    print(1, 2, 3, 4);
    print1(1, 2, 3, 4);
}
