#include <memory>

struct FooInterface {
    [[nodiscard]] virtual auto func() const -> int = 0;
};

struct Foo final : public FooInterface {
    [[nodiscard]] auto func() const -> int {
        return 42;
    }
};

// with virtual
std::unique_ptr<FooInterface> foo = std::make_unique<Foo>();

auto func(std::unique_ptr<FooInterface> foo2) {
    // implementation here
}

// --------------------------------------------------------------

template <typename T>
concept CFoo = requires(T foo) {
    // { foo.func() } -> std::same_as<int>;
    { foo.func() } -> std::integral;
};

struct Foo_ {
    [[nodiscard]] auto func() const -> int {
        return 42;
    }
};

// without virtual
Foo_ foo_();

auto func(CFoo auto &foo2) {
    // implementation here
}

int main() {
    return 0;
}
