#include <cstddef>

// a example:
template <typename... Xs>
constexpr auto make_storage(Xs... xs) {
    auto storage = [=](auto f) { return f(xs...); };
    return storage;
}

template <typename... Xs>
struct tuple {
    explicit constexpr tuple(Xs... xs) : storage{make_storage(xs...)} {}

    decltype(make_storage(declval<Xs>()...)) storage;
};

template <size_t N, typename... T>
constexpr decltype(auto) get(tuple<T...> &t) {
    return t.storage([](auto &&...xs) { /* ... */ });
}

int main() {
    auto add = [](int n, int m) { return n + m; };

    // before C++17, compile error: the lambda's call operator is not constexpr
    // since C++17, don't have this restriction
    constexpr int i = add(5, 6);

    constexpr auto add_ = [](int n, int m) { return n + m; };
}
