#include <concepts>
#include <memory>
#include <variant>

template <typename T>
concept CFoo = requires(T foo) {
    { foo.func() } -> std::integral;
};

// add same_as_any concept
template <typename T, typename... Ts>
concept same_as_any = (... or std::same_as<T, Ts>);

// template <CFoo TFoo>
template <CFoo... TFoos>
class Bar {
public:
    // constexpr Bar(auto input_foo) : foo(input_foo) {}
    constexpr Bar(same_as_any<TFoos...> auto input_foo) : foo(input_foo) {}

    // constexpr auto set_foo(auto input_foo) -> void {
    //     foo = input_foo;
    // }
    constexpr auto set_foo(same_as_any<TFoos...> auto input_foo) -> void {
        foo = input_foo;
    }

private:
    // TFoo foo {};
    std::variant<TFoos...> foo {};
};

int main() {
    return 0;
}

// with virtual
// Bar bar {std::make_unique<Foo>()};

// without virtual
// Bar bar {Foo{}};
// Bar<Foo1, Foo2> bar{Foo1{}};
