#include <concepts>
#include <type_traits>

// Constraints

template <class T>
typename std::enable_if<std::is_integral<T>::value, int>::type count_one_bits(T arg);

template <class T, class = typename std::enable_if<std::is_integral<T>::value>::type>
int count_one_bits(T arg);

// C++20 concepts
template <class T>
    requires std::is_integral<T>::value
int count_one_bits(T arg);

template <class T>
    requires std::integral<T>
int count_one_bits(T arg);

// or
// template <class T>
// int count_one_bits(T arg)
//     requires std::is_integral<T>::value;

template <std::integral T>
int count_one_bits(T arg);

// C++20 concepts + auto
int count_one_bits(std::integral auto arg);

// C++26 reflection
// template <class T>
//     requires(type_is_integral(^^T))
// int count_one_bits(T arg);

int main() {
    return 0;
}
