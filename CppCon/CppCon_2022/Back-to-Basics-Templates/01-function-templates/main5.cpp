#include <atomic>
#include <complex>
#include <iostream>
#include <string>

// C++98: Function Template Requirements
//
// Template require that all operations are supported

template <typename T>
T mymax(T a, T b) {
    return b < a ? a : b;
}

int main() {
    int i1 = 42, i2 = 77;
    std::cout << mymax(i1, i2) << '\n';
    std::cout << mymax(7, 33.4);         // ERROR: can't decude T (int or double)
    std::cout << mymax<double>(7, 33.4); // OK: T is double

    std::complex<double> c1, c2;
    std::cout << mymax(c1, c2); // ERROR: decudes T as complex<>, but no < supported

    std::atomic<int> a1 {8}, a2 {15};
    std::cout << mymax(a1, a2); // ERROR: decudes T as atomic<>, but copying disabled
}
