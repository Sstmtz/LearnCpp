
// Class Template Argument Kinds

// Template argument kind must match template parameter kind

#include <cstddef>

// template <class T, std::size_t N>
// class std::array;

template <class T>
struct A {};

template <int N>
struct B {};

template <template <class> class X>
struct C {};

int main() {
    std::array<int, double> b; // Note: expected a constant of type 'long unsigned int', got 'double'
    std::array<1, 2>        c; // Note: expected a type, got '1'

    C<int> wrong_kind;         // Note: expected a class template, got 'int'

    C<B> no_match;             // Note: expected a template for type 'template<class> class X', got 'template<int N> struct B'
}
