#include <cstddef>

// Partial Specialization (3)

template <class T>
constexpr std::size_t safe_sizeof = 0;

template <class T>
    requires(sizeof(T) > 0)
constexpr std::size_t safe_sizeof<T> = sizeof(T);

int main() {
    return 0;
}
