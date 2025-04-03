
// foo(42); // param(42) is rvalue/prvalue

// int i = 42;
// foo(i); // param(i) is lvalue/glvalue

// int i = 42;
// foo(std::move(i)); // param(std::move(i)) is glvalue/rvalue/xvalue

// int make_int() {
//     return 42;
// }
//
// foo(make_int()); // param(make_int()) is rvalue/prvalue
