// before C++17:
template <typename T>
auto add(T x, T y) {
    static_assert(is_addable_v<T>, "");
    return x + y;
}

// since C++17:
template <typename T>
auto add(T x, T y) {
    static_assert(is_addable_v<T>);
    return x + y;
}
