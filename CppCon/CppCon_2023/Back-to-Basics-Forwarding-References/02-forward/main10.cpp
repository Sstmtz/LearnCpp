#include <cassert>
#include <concepts>
#include <type_traits>
#include <utility>

class int_or_empty {
    int  value_ = 0;
    bool empty_ = true;

public:
    int_or_empty() = default;

    // int_or_empty(int_or_empty const &) = default;

    template <std::convertible_to<int> T>
        requires(! std::same_as<std::remove_cvref_t<T>, int_or_empty>) // *
    constexpr int_or_empty(T &&v) : value_ {std::forward<T>(v)}
                                  , empty_(false) {}

    constexpr bool empty() const {
        return empty_;
    }

    constexpr operator int() const {
        return value_;
    }
};

int main() {
    int_or_empty empty;
    assert(empty.empty());

    int_or_empty one {1};
    assert(! one.empty());
    assert(one == 1);

    int_or_empty empty2 {empty};
    // assert(empty2.empty()); // Assertion failed
    assert(empty2.empty());
}
