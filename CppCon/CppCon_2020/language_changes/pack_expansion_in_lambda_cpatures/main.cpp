#include <functional>
#include <iterator>
#include <type_traits>

// example: a simple-capture followed by an ellipsis is a pack expansion:
template <class F, class... Args>
auto decay_invoke(F f, Args... args) {
    return [f, args...] {
        return std::invoke(f, args...);
    };
}

//  a init-capture followed by an ellipsis is ill-formed:
template <class F, class... Args>
auto decay_invoke2(F f, Args... args) {
    return [f = std::move(f), ... args = std::move(args)] {
        return std::invoke(f, args...);
    };
}

int main() {
    return 0;
}
