
// Objects of rvalue reference type

// rvalue reference variables are lvalues when used in expressions
#include <utility>

// void boo(int &&x);
//
// void foo(int &&x) {
//     boo(x); // ERROR
// }

void boo(int &&x);

void foo(int &&x) {
    boo(std::move(x)); // OK
}

// Note: std::move does not move! It is just a cast to an rvalue reference type
