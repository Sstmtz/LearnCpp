// References

// void f(int &ref);
//
// int       i = 42;
// int const ci = 42;
//
// int make_int() {
//     return 42;
// }
//
// f(i);             // OK
// f(ci);            // ERROR
// f(std::move(i));  // ERROR
// f(std::move(ci)); // ERROR
// f(42);            // ERROR
// f(make_int());    // ERROR

// void f(int const &ref);
//
// int       i = 42;
// int const ci = 42;
//
// int make_int() {
//     return 42;
// }
//
// f(i);             // OK
// f(ci);            // OK
// f(std::move(i));  // OK
// f(std::move(ci)); // OK
// f(42);            // OK
// f(make_int());    // OK
