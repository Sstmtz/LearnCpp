// since C++11
// `auto` can be used as a function return type, but it includes a trailing(->) return type
// At this point, `auto` serves only as a placeholder, simply placing the function return type at
// the end.
auto foo() -> int; // OK: foo returns int

// auto foo();     // ERROR: `auto` return without trailing return type

// It can also be used in conjunction with `decltype`
// to obtain the return type from the return value.
auto square(int x) -> decltype(x * x) {
    return x * x;
}

int main() {
    return 0;
}
