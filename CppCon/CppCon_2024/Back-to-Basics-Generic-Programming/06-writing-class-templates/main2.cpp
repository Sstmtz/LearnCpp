#include <cstddef>

// Partial Specialization (1)

template <class T>
struct safe_sizeof {
    static constexpr std::size_t value = sizeof(T);
};

template <>
struct safe_sizeof<void> {
    static constexpr std::size_t value = 0;
};

// Matches any array with unspecified bound
template <class T>
struct safe_sizeof<T[]> {
    static constexpr std::size_t value = 0;
};

// Matches any function type
template <class R, class... Args>
struct safe_sizeof<R(Args...)> {
    static constexpr std::size_t value = 0;
};

int main() {
    return 0;
}
