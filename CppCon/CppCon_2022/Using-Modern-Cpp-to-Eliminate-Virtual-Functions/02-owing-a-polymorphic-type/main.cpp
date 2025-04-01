#include <memory>

struct FooInterface {
    FooInterface() = default;
    FooInterface(FooInterface const &) = default;
    FooInterface(FooInterface &&) = default;
    FooInterface &operator=(FooInterface const &) = default;
    FooInterface &operator=(FooInterface &&) = default;
    virtual ~FooInterface() = default;

    [[nodiscard]] virtual auto func() const -> int = 0;
};

class Bar {
public:
    constexpr Bar(std::unique_ptr<FooInterface> input_foo) : foo(std::move(input_foo)) {}

private:
    std::unique_ptr<FooInterface> foo {};
};

int main() {
    return 0;
}
