#include <memory>
#include <vector>

struct FooInterface {
    FooInterface() = default;
    FooInterface(FooInterface const &) = default;
    FooInterface(FooInterface &&) = default;
    FooInterface &operator=(FooInterface const &) = default;
    FooInterface &operator=(FooInterface &&) = default;
    virtual ~FooInterface() = default;

    [[nodiscard]] virtual auto func() const -> int = 0;
};

class Baz {
public:
    auto store(std::unique_ptr<FooInterface> value) -> void {
        data.push_back(std::move(value));
    }

private:
    std::vector<std::unique_ptr<FooInterface>> data {};
};

int main() {
    return 0;
}
