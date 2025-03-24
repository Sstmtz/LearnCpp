// before C++17:
#include <cstddef>

template <typename T, T... Elements>
struct sequence {};

using idxs = sequence<int, 0, 1, 2>;
using str = sequence<char, 'a', 'b', 'c'>;

// since C++17:
template <auto... Elements>
struct sequence_ {};

using idxs_ = sequence_<0, 1, 2>;
using str_ = sequence_<'a', 'b', 'c'>;

// before C++17:
template <typename T, std::size_t Extent>
struct span {};

constexpr std::size_t dyn = -1;

// since C++17:
template <typename T, auto Extent>
struct span_ {};

struct dynamic_extent {};

constexpr dynamic_extent dyn_ = {};

int main() {
    span<double, 64> d;
    span<int, dyn> i;

    span_<double, 64> d_;
    span_<int, dyn_> i_;
}
