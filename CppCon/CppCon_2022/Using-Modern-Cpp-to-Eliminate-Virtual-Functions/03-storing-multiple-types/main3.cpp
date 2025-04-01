#include <concepts>
#include <memory>
#include <tuple>
#include <vector>

template <typename T, typename... Ts>
concept same_as_any = (... or std::same_as<T, Ts>);

template <typename T>
concept CFoo = requires(T foo) {
    { foo.func() } -> std::integral;
};

template <CFoo... TFoos>
class Baz {
public:
    template <same_as_any<TFoos...> T>
    auto store(T value) {
        return std::get<std::vector<T>>(data).push_back(value);
    }

private:
    std::tuple<std::vector<TFoos>...> data {};
};

int main() {
    return 0;
}

// with virtual
// Baz baz {};
// baz.store(std::make_unique<Foo1>());
// baz.store(std::make_unique<Foo2>());

// without virtual
// Baz<Foo1, Foo2> baz {};
//
// using foo_storage_t = Baz<Foo1, Foo2>;
// foo_storage_t baz{};
//
// baz.store(Foo1 {});
// baz.store(Foo2 {});
