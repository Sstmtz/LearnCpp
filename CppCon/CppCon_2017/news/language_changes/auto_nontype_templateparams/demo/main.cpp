// auto Non-Type Template Parameter
// template <auto parameter, ...>
// auto deduction rules(auto const, auto&, auto&&, etc)

// before C++17:
template <typename T, T v>
struct constant {
    static constexpr T value = v;
};

using i = constant<int, 2017>;
using c = constant<char, 'a'>;
using b = constant<bool, true>;

// using f = constant<decltype(F), F>;

// since C++17:
template <auto v>
struct constant_ {
    static constexpr auto value = v;
};

using i_ = constant_<2017>;
using c_ = constant_<'a'>;
using b_ = constant_<true>;

// using f = constant<F>;

int main() {
    return 0;
}
