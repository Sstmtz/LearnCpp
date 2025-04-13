// Return reference type
#include <string>

// 1. The return type declared as `auto` can automatically deduce the return type,
// but it will always deduce to a regular value type and will never include references or `const`
// qualifiers. If you need to return a reference and want to automatically deduce the type of the
// reference, you can write `auto &`.

int i = 0;
int &ref = i;

auto foo() { // int
    return i;
}

auto foo2() { // int
    return ref;
}

auto &foo3() { // int &
    return ref;
}

// auto &foo4() {
//     return 1;
// } // complie-time ERROR：1 is prvalue, and cannot be converted to an lvalue reference

// auto &foo5() {
//     int local = 42;
//     return local;
// } // run-time ERROR：UB(dangling reference)

// 2. `auto` can also be combined with the `const` qualifier,
// for example, `auto const &` allows the return type to become a constant reference.

auto getValue() { // int
    return i;
}

auto &getRef() { // int &
    return i;
}

auto const &getConstRef() { // int const &
    return i;
}

// 3. Interestingly, if `i` is of type `int const`,
// then `auto &` can also be automatically deduced as `int const &` without any errors.
// for example, `auto &` can be compatible with `auto const &` (similar to `T&`, T = const int),
// while `int &` cannot be compatible with `int const &`.

int const j = 0;

auto const &getConstRef2() { // int const & (auto = int)
    return j;
}

auto &getRef2() { // int const & (auto = int const)
    return j;
}

// int &getRef3() {
//     return j;
// } // ERROR

// 4. Universal reference (auto &&).
// `auto &&` can be compatible with `auto &`
// Therefore, `auto &&` actually supports not only rvalue references but also lvalue references,
// which is why it is referred to as "universal reference".
// It can be understood as a containment relationship: `auto && > auto & > auto const &`.

std::string str = "Hello World";

auto &&getRVRef() { // std::string &&
    return std::move(str);
}

auto &&getRef3() { // std::string &
    return str;
}

auto const &getConstRef3() { // std::string const &
    return str;
}

// 5. Reference Collapses (make std::forward possible)
// reference collapsing rules apply: rvalue reference to rvalue reference collapses to rvalue
// reference, all other combinations form lvalue reference:
// 1. & & = &
// 2. & && = &, && & = &
// 3. && && = &&

// Therefore, `auto &&` can be deduced not only as an rvalue reference but also as an lvalue
// reference, specifically a const lvalue reference. (rule 2 & 3)

using lref = int &;
using rref = int &&;
int n;

lref &r1 = n;  // type of r1 is int&  (rule 1)
lref &&r2 = n; // type of r2 is int&  (rule 2)
rref &r3 = n;  // type of r3 is int&  (rule 2)
rref &&r4 = 1; // type of r4 is int&& (rule 3)

int main() {
    return 0;
}
