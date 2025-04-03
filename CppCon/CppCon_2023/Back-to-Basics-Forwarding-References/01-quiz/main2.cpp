// Pointers

#include <utility>

// void f(int *ptr);
// void f(int const *ptr);
//
// int       i = 42;
// int const ci = 42;
//
// int make_int() {
//     return 42;
// }
//
// f(i);             // ERROR
// f(ci);            // ERROR
// f(std::move(i));  // ERROR
// f(std::move(ci)); // ERROR
// f(42);            // ERROR
// f(make_int());    // ERROR
// In order to pass a variable to a function taking a pointer we need to pass its address.

// void f(int *ptr);
//
// int       i = 42;
// int const ci = 42;
//
// int make_int() {
//     return 42;
// }
//
// f(&i);             // OK
// f(&ci);            // ERROR
// f(&std::move(i));  // ERROR
// f(&std::move(ci)); // ERROR
// f(&42);            // ERROR
// f(&make_int());    // ERROR

// void f(int const *ptr);
//
// int       i = 42;
// int const ci = 42;
//
// int make_int() {
//     return 42;
// }
//
// f(&i);             // OK
// f(&ci);            // OK
// f(&std::move(i));  // ERROR
// f(&std::move(ci)); // ERROR
// f(&42);            // ERROR
// f(&make_int());    // ERROR
