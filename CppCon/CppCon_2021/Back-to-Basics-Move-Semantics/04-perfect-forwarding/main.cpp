// Motivation for Perfect Forwarding 1/2

// - Overloading for const/non-const lvalues and rvalues:

#include <utility>

class C {
    // ...
};

void foo(C const &); // read-only access (binds to all values)
void foo(C &);       // write access (binds to non-const lvalues)
void foo(C &&);      // move access (binds to non-const rvalues)

// C v;
// C const c;
// foo(v);            // calls foo(C&)
// foo(c);            // calls foo(const C&)
// foo(C {});         // calls foo(C&&)
// foo(std::move(v)); // calls foo(C&&)
