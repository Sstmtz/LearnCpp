
// std::forward Implementation

#include <type_traits>

template <typename T>
[[nodiscard]] constexpr T &&forward(typename std::type_identity_t<T> &param) {
    return static_cast<std::type_identity_t<T> &&>(param);
}

// REFERENCE COLLAPSES
// It is permitted to form references to references through type manipulations in templates or typedefs
// 1. rvalue reference to rvalue reference collapses tp rvalue reference
// 2. all other combinations form lvalue reference

using lref = int &;
using rref = int &&;
int n;

lref  &r1 = n; // type of r1 is int&
lref &&r2 = n; // type of r2 is int&
rref  &r3 = n; // type of r3 is int&
rref &&r4 = 1; // type of r4 is int&&
