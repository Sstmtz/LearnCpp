// Perfect Forward

// Perfect forwarding of parameters:
// 1. Tempalte parameters
// 2. Declaring the parameter as && of the template parameter
// 3. std::forward<>()

#include <utility>

class C {
    // ...
};

void foo(C const &); // read-only access (binds to all values)
void foo(C &);       // write access (binds to non-const lvalues)
void foo(C &&);      // move access (binds to non-const rvalues)

template <typename T>
void callFoo(T &&x) {        // x is universal (or forwarding) reference
    foo(std::forward<T>(x)); // perfectly forwards move semantics
}

// Universal/forwarding reference (community/C++ standard term)
// - Can refer to const and non-const
// - Can refer to rvalue and lvalue

// C v;
// C const c;
// callFoo(v);            // foo(std::forward<T>(x)) => foo(x)
// callFoo(c);            // foo(std::forward<T>(x)) => foo(x)
// callFoo(C {});         // foo(std::forward<T>(x)) => foo(std::move(x))
// callFoo(std::move(v)); // foo(std::forward<T>(x)) => foo(std::move(x))
