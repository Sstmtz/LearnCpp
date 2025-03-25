#include <cstdint>
#include <type_traits>
#include <utility>

// std::to_underlying()
// Converts an enumerator to the underlying type
// Equivalent to
// static_assert<std::underlying_type<E>>(enum_value);

enum class Color : uint32_t {
    Red = 0xff0000,
    Green = 0x00ff00,
    Blue = 0x0000ff
};

int main() {
    Color r {Color::Red};
    auto  value1 {static_cast<std::underlying_type_t<Color>>(r)};
    auto  value2 {std::to_underlying(r)};
}
