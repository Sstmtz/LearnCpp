#include <iterator>
#include <type_traits>

// Class Template Definition
template <class T, class U>
class pair {
    T m0;
    U m1;

public:
    pair() {}

    pair(T v0, U v1) : m0(v0), m1(v1) {}

    T first() const {
        return m0;
    }

    T second() const {
        return m1;
    }
};

// Function Template Definition
template <class T>
void swap_pointed_to(T *a, T *b) {
    T temp = *a;
    *a = *b;
    *b = temp;
}

// Type Alias Template Definition
template <class T>
using prt = T *;

template <class Iter1, class Iter2>
using result_type =
    typename std::common_type<typename std::iterator_traits<Iter1>::value_type,
                              typename std::iterator_traits<Iter2>::value_type>::type;

// Variable Template Definition
template <class T>
constexpr bool is_big_and_trivial
    = sizeof(T) > 16
      && std::is_trivially_copyable<T>::value &&std::is_trivially_destructible<T>::value;

int main() {
    return 0;
}
