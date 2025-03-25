#include <memory>
#include <type_traits>

// before C++17:
template <typename T, typename... Args>
std::enable_if_t<std::is_constructible_v<T, Args...>, std::unique_ptr<T>> make_unique(Args &&...a) {
    return std::unique_ptr(new T(std::forward<Args>(a)...));
}

template <typename T, typename... Args>
std::enable_if_t<! std::is_constructible_v<T, Args...>, std::unique_ptr<T>> make_unique(Args &&...a) {
    return std::unique_ptr(new T {std::forward<Args>(a)...});
}

// since C++17:
template <typename T, typename... Args>
auto make_unique(Args &&...a) {
    if constexpr (std::is_constructible_v<T, Args...>) {
        return std::unique_ptr(new T(std::forward<Args>(a)...));
    } else {
        return std::unique_ptr(new T {std::forward<Args>(a)...});
    }
}

int main() {
    return 0;
}
