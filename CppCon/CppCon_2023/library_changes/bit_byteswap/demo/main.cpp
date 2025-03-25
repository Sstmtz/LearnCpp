#include <bit>
#include <cstdint>
#include <print>

// std::byteswap()
// Standard way to swap bytes of integral types

int main() {
    std::uint32_t a {0x12345678u};
    std::println("{:x}", a); // 12345678
    std::uint32_t b {std::byteswap(a)};
    std::println("{:x}", b); // 78563412
}
