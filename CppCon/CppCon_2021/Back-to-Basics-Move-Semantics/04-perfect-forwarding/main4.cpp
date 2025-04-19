// The Two Meaning of && Declarations

// - && declares
//   - For types:           raw rvalue references
//   - For template params: universal/forwarding references

#include <type_traits>
#include <utility>

// class Type {
//     // ...
// };
//
// void foo(Type &&x)              // rvalue reference
// {
//     std::is_const<Type>::value; // always false
//     // ...
//     // perfectly forward x:
//     bar(std::move(x));
//     // x has valid but unspecified state
// }
//
// Type v;
// Type const c;
// foo(v);            // ERROR
// foo(c);            // ERROR
// foo(Type {});      // OK
// foo(std::move(v)); // OK

// class Type {
//     // ...
// };
//
// template <typename T>
// void foo(T &&x)                 // universal reference
// {
//     std::is_const<Type>::value; // maybe true or false
//     // ...
//     // perfectly forward x:
//     bar(std::forward<T>(x));
//     // x has valid but unspecified state
// }
//
// Type v;
// Type const c;
// foo(v);            // OK, x is non-const
// foo(c);            // OK, x is const
// foo(Type {});      // OK, x is non-const
// foo(std::move(v)); // OK, x is non-const
