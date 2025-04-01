struct FooInterface {
    FooInterface() = default;
    FooInterface(FooInterface const &) = default;
    FooInterface(FooInterface &&) = default;
    FooInterface &operator=(FooInterface const &) = default;
    FooInterface &operator=(FooInterface &&) = default;
    virtual ~FooInterface() = default;

    [[nodiscard]] virtual auto func() const -> int = 0;
};

struct Foo final : public FooInterface {
    Foo() = default;
    Foo(Foo const &) = default;
    Foo(Foo &&) = default;
    Foo &operator=(Foo const &) = default;
    Foo &operator=(Foo &&) = default;
    virtual ~Foo() = default;

    [[nodiscard]] auto func() const -> int override {
        return 42;
    }
};

int main() {
    return 0;
}
