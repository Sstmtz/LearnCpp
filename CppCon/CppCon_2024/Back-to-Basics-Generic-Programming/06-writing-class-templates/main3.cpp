#include <cstddef>

// Partial Specialization (2)

template <class T>
struct safe_sizeof { // default is 0
    static constexpr std::size_t value = 0;
};

template <class T>
    requires(sizeof(T) > 0)
struct safe_sizeof<T> {
    static constexpr std::size_t value = sizeof(T);
};

int main() {
    return 0;
}
