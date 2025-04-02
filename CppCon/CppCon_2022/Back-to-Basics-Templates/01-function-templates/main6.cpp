#include <atomic>
#include <complex>
#include <concepts>
#include <iostream>

// C++20: Concepts
//
// To formulate formal constraints for generic code

template <typename T>
concept SupportsLessThan = requires(T x) { x < x; }; // Concepts: named requirements

template <typename T>
    requires std::copyable<T> && SupportsLessThan<T>
// Explict constraint for T:
// 1. operator < (return bool)
// 2. copy/move constructor
T mymax(T a, T b) {
    return b < a ? a : b;
}

int main() {
    int i1 = 42, i2 = 77;
    std::cout << mymax(i1, i2) << '\n';

    std::complex<double> c1, c2;
    std::cout << mymax(c1, c2); // ERROR: concept SupportsLessThan not supported

    std::atomic<int> a1 {8}, a2 {15};
    std::cout << mymax(a1, a2); // ERROR: concept std::copyable not supported
}
