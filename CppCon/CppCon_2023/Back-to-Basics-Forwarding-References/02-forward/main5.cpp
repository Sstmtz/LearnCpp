
// A Universal Reference

#include <memory>

int       i = 42;
int const ci = 42;

int make_int() {
    return 42;
}

template <typename T>
void f(T &&t);

template <typename T>
void f(T const &t);

int main() {
    f(i);             // f<int&>(int&)
    f(ci);            // f<const int&>(const int&)
    f(std::move(i));  // f<int>(int&&)
    f(std::move(ci)); // f<const int>(const int&&)
    f(42);            // f<int>(int&&)
    f(make_int());    // f<int>(int&&)

    f(i);             // f<int>(const int&)
    f(ci);            // f<int>(const int&)
    f(std::move(i));  // f<int>(const int&)
    f(std::move(ci)); // f<int>(const int&)
    f(42);            // f<int>(const int&)
    f(make_int());    // f<int>(const int&)
}

// Special rule: When T&& is used as a function template parameter and an
// lvalue is being passed the deduced type is T& instead if T

// Both `forwarding references` and `const lvalue references` bind to everything.
// However, the former might be more expensive.
