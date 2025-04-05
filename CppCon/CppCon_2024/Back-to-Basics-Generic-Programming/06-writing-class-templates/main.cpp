#include <cstddef>

// Specialization

template <class T>
struct safe_sizeof {
    static constexpr std::size_t value = sizeof(T);
};

template <>
struct safe_sizeof<void> {
    static constexpr std::size_t value = 0;
};

int main() {
    return 0;
}
