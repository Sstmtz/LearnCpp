
// Capturing the argument
//
// Coroutine state stores coroutine parameters
// - by-value parameters are moved or copied
// - by-reference parameters remain references

#include <utility>

template <typename T>
task<void> foo(T &&t) {
    // ...
}

template <typename U>
task<void> foo(U &&u) {
    return foo(std::forward<U>(u));
}

int main() {
    int i = 123;
    co_await boo(i);  // T -> int&; t -> int&
    co_await boo(42); // T -> int; t -> int&&
}

template <typename T>
task<void> foo(T t) {
    // ...
}

template <typename U>
task<void> foo(U &&u) {
    return foo<U>(std::forward<U>(u));
}

int main() {
    int i = 123;
    co_await boo(i);  // T -> int&; t -> int&
    co_await boo(42); // T -> int; t -> int
}
