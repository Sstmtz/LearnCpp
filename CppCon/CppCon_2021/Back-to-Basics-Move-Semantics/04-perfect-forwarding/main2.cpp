// Motivation for Perfect Forwarding 2/2

// - Forward move semantics in helper functions:

#include <utility>

class C {
    // ...
};

void foo(C const &); // read-only access (binds to all values)
void foo(C &);       // write access (binds to non-const lvalues)
void foo(C &&);      // move access (binds to non-const rvalues)

void callFoo(C const &x) {
    foo(x); // x is const lvalue => calls foo(C const&)
}

void callFoo(C &x) {
    foo(x); // x is non-const lvalue => calls foo(C&)
}

void callFoo(C &&x) {
    foo(std::move(x)); // x is non-const lvalue => needs std::move() to calls foo(C&&)
}

// C v;
// C const c;
// callFoo(v);            // calls foo(C&)
// callFoo(c);            // calls foo(const C&)
// callFoo(C {});         // calls foo(C&&)
// callFoo(std::move(v)); // calls foo(C&&)
