#include <string>
#include <type_traits>

// C++20: Sunsumptions are checked logically and indirectly

template <typename T>
concept BigType = sizeof(T) > 8;

template <typename T>
concept ClassType = std::is_class_v<T>;

template <typename T>
concept BigOrClass = BigType<T> || ClassType<T>;

template <typename T>
concept BigAndClass = BigType<T> && ClassType<T>; // does subsume concept BigOrClass

void foo3(BigOrClass auto) { /* ... */ }

void foo3(BigAndClass auto) { /* ... */ }

int main() {
    std::string s;
    foo3(s); // OK: calls foo3(BigOrClass) because it subsumes foo3(BigClass)
}
