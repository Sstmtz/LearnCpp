#include <type_traits> // *

// template <...>
// bool constexpr trait_v = trait<...>::value;

// before C++17:
template <typename T>
std::enable_if_t<std::is_integral<T>::value, T> sqrt(T t);

template <typename T>
std::enable_if_t<std::is_floating_point<T>::value, T> sqrt(T t);

// since C++17:
template <typename T>
std::enable_if_t<std::is_integral_v<T>, T> sqrt(T t);

template <typename T>
std::enable_if_t<std::is_floating_point_v<T>, T> sqrt(T t);

// before C++17:
template <typename... Ts>
struct all_integral;

template <>
struct all_integral<> : std::true_type {};

template <typename T0, typename... Ts>
struct all_integral<T0, Ts...> : std::integral_constant<bool, std::is_integral<T0>::value && all_integral<Ts...>::value> {};

// since C++17:
template <typename... Ts>
struct all_integral : std::bool_constant<(... && std::is_integral_v<Ts>)> {};

int main() {
    return 0;
}
