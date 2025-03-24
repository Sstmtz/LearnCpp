#include <bit>
#include <bitset>
#include <cstdint>
#include <iostream>

int main() {
    using bin = std::bitset<8>;
    std::uint8_t const x {0b0001'1101};
    std::cout << std::popcount(x) << '\n';
    std::cout << bin(x) << " <- x\n";
    for (int const s : {0, 1, 4, 9, -1}) {
        std::cout << bin(std::rotl(x, s)) << " <- rotl(x, " << s << ")\n";
    }
}
