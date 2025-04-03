#include <string>
#include <type_traits>

// C++20: Only concept constraints are checked for subsumption

template <typename T>
concept BigType = sizeof(T) > 8;

template <typename T>
concept BigClassType0 = sizeof(T) > 8 && std::is_class_v<T>; // does not subsume concept BigType

void foo1(BigType auto) { /*... */ }

void foo1(BigClassType0 auto) { /*... */ }

template <typename T>
concept BigClassType = BigType<T> && std::is_class_v<T>; // does subsume concept BigType

void foo2(BigType auto) { /*... */ }

void foo2(BigClassType auto) { /*... */ }

int main() {
    std::string s;
    foo1(s); // ERROR: ambiguous
    foo2(s); // OK: calls foo2(BigClassType)
}
