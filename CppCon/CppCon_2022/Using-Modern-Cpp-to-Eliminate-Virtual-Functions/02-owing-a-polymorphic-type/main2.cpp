#include <concepts>

template <typename T>
concept CFoo = requires(T foo) {
    // { foo.func() } -> std::same_as<int>;
    { foo.func() } -> std::integral;
};

// template <typename TFoo>
template <CFoo TFoo>
class Bar {
public:
    constexpr Bar(TFoo input_foo) : foo(input_foo) {}

private:
    TFoo foo {};
};

int main() {
    return 0;
}
