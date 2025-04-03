
// NOT A Forwarding reference

#include <vector>
template <class T>
int g(T const &&y);

template <class T>
struct A {
    template <class U, class Z = T>
    A(T &&t, U &&u, Z &&z); // only 'u' and 'z' are forwarding references
};

template <typename T>
void foo(std::vector<T> &&v);

auto &&z = {1, 2, 3}; // special case for initializer lists
