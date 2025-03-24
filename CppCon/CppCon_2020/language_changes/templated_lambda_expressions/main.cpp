#include <functional>
#include <iterator>
#include <type_traits>

// templated lambda expression

// example 1: generic lambda accepting a vector<T>; you want know T (pre C++20)
auto fn = [](auto const &vec) {
    using V = std::decay_t<decltype(vec)>;
    using T = typename V::value_type;
    T x {};
    T::static_function();
    // ...
};

// with C++20:
auto fn2 = []<typename T>(auto const &vec) {
    T x {};
    T::static_function();
    // ...
};

void foo(int);

// example 2: Perfect forwarding (pre C++20)
auto fn3 = [](auto &&...args) {
    return foo(std::forward<decltype(args)>(args)...);
};
// with C++20:
auto fn4 = []<typename T>(auto &&...args) {
    return foo(std::forward<T>(args)...);
};

int main() {
    return 0;
}
