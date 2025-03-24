#include <concepts>
#include <cstddef>

// a concept definition:
template <typename T>
concept Incrementable = requires(T x) {
    x++;
    ++x;
};

template <typename T>
concept Decrementable = requires(T x) {
    x--;
    --x;
};

// use this concept:
// 1. replace `typename T`
template <Incrementable T>
void foo(T t);
// 2. use requires, before function signature
template <typename T>
    requires Incrementable<T>
void foo(T t);
// 3.use requires, but after function signature
template <typename T>
void foo(T t)
    requires Incrementable<T>;
// 4. combine with abbreviated function template
void foo(Incrementable auto t);

// compound requirements
// for example,
// 1. requires a non-throwing swap() method, and
// 2. requires a size() method return a size_t
template <typename T>
concept C = requires(T &x, T &y) {
    { x.swap(y) } noexcept;
    { x.size() } -> std::convertible_to<std::size_t>;
    // ...
};

// combining concepts
// directly use requires
template <typename T>
    requires Incrementable<T> && Decrementable<T>
void Foo(T t);
// or definit a concept to use
template <typename T>
concept C2 = Incrementable<T> && Decrementable<T>;
void Foo(C2 auto t);

int main() {
    return 0;
}
