#include <concepts>

template <typename T>
concept CFoo = requires(T foo) {
    // { foo.func() } -> std::same_as<int>;
    { foo.func() } -> std::integral;
};

struct Foo {
    [[nodiscard]] auto func() const -> int {
        return 42;
    }
};

static_assert(CFoo<Foo>);

int main() {
    return 0;
}
