#include <concepts>
#include <memory>
#include <variant>

template <typename T>
concept CFoo = requires(T foo) {
    { foo.func() } -> std::integral;
};

// template <CFoo TFoo>
template <CFoo... TFoos>
class Bar {
public:
    // constexpr Bar(TFoo input_foo) : foo(input_foo) {}
    // constexpr Bar(auto input_foo) : foo(input_foo) {}
    constexpr Bar(CFoo auto input_foo) : foo(input_foo) {}

    // constexpr auto set_foo(auto input_foo) -> void {
    //     foo = input_foo;
    // }
    constexpr auto set_foo(CFoo auto input_foo) -> void {
        foo = input_foo;
    }

private:
    // TFoo foo {};
    std::variant<TFoos...> foo {};
};

int main() {
    return 0;
}
