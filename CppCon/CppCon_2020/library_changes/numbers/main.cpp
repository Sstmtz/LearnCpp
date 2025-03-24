// https://en.cppreference.com/w/cpp/header/numbers

#include <iostream>
#include <numbers>

int main() {
    std::cout << "PI: " << std::numbers::pi << '\n';
    std::cout << "e: " << std::numbers::e << '\n';
    std::cout << "log2e: " << std::numbers::log2e << '\n';
    std::cout << "log10e: " << std::numbers::log10e << '\n';
    std::cout << "sqrt2: " << std::numbers::sqrt2 << '\n';
    std::cout << "sqrt3: " << std::numbers::sqrt3 << '\n';
    std::cout << "egamma: " << std::numbers::egamma << '\n';
    std::cout << "phi: " << std::numbers::phi << '\n';
}
