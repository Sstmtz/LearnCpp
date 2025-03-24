#include <array>
#include <string>
#include <string_view>
#include <type_traits>
#include <variant>

template <unsigned N>
std::string repeat(std::string_view s) {
    std::string tmp;
    for (unsigned i = 0; i != N; ++i) {
        tmp += s;
    }
    return tmp;
}

template <unsigned N>
struct multiplier_visitor {
    void operator()(std::string &t) const {
        t = repeat<N>(t);
    }

    void operator()(int &t) const {
        t = t * N;
    }

    void operator()(std::array<int, 2> &t) const {
        t = {
          {static_cast<int>(t[0] * N), static_cast<int>(t[1] * N)}
        };
    }
};

template <typename... Ts>
struct overloaded : Ts... {
    using Ts::operator()...;
};

template <typename... Ts>
overloaded(Ts...) -> overloaded<Ts...>;

int main() {
    // default state is the first type, e.g. std::string
    std::variant<std::string, int, std::array<int, 2>> v;

    v = 21;
    std::visit(multiplier_visitor<2> {}, v); // v == 42

    v = "Ha";
    std::visit(multiplier_visitor<3> {}, v); // v == "HaHaHa"

    // use std::visit + if constexpr:
    std::visit(
        [](auto &t) {
            constexpr unsigned N = 10;

            using T = std::decay_t<decltype(t)>;

            if constexpr (std::is_same_v<T, std::string>) {
                t = repeat<N>(t);
            } else if constexpr (std::is_same_v<T, int>) {
                t = t * N;
            } else if constexpr (std::is_same_v<T, std::array<int, 2>>) {
                t = {
                  {static_cast<int>(t[0] * N), static_cast<int>(t[1] * N)}
                };
            } else {
                static_assert(false);
            }
        },
        v);

    // use std::visit + overloaded
    constexpr unsigned N = 10;
    std::visit(overloaded {[=](std::string &t) {
                               t = repeat<N>(t);
                           },
                           [=](int &t) {
                               t = t * N;
                           },
                           [=](std::array<int, 2> &t) {
                               t = {
                                 {static_cast<int>(t[0] * N), static_cast<int>(t[1] * N)}
                               };
                           }},
               v);
}
