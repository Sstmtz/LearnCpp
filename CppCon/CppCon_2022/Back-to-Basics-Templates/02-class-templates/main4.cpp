#include <cstddef>
#include <iostream>

// C++11: std::array<> is a Template Aggregate

// C-Style array
struct CArray {
    int elems[10];
};

// like std::array
template <typename T, size_t SZ>
struct array {
    T elems[SZ];

    size_t size() const {
        return SZ;
    }

    T &operator[](size_t idx) {
        return elems[idx];
    }

    T const &operator[](size_t idx) const {
        return elems[idx];
    }

    typedef T *iterator;

    T *begin() {
        return &elems[0];
    }

    T *end() {
        return &elems[0] + SZ;
    }

    //...
};

int main() {
    struct CArray ca = {1, 2, 3, 4};

    for (int i = 0; i < 10; ++i) {
        std::cout << ca.elems[i] << '\n';
    }

    for (int *p = ca.elems; p < ca.elems + 10; ++p) {
        std::cout << *p << '\n';
    }

    array<int, 10> a = {1, 2, 3, 4};
    std::cout << a.size() << " elements\n";

    for (size_t i = 0; i < a.size(); ++i) {
        std::cout << a[i] << '\n';
    }

    for (array<int, 10>::iterator p = a.begin(); p != a.end(); ++p) {
        std::cout << *p << '\n';
    }

    for (auto const &elem : a) {
        std::cout << elem << '\n';
    }
}
