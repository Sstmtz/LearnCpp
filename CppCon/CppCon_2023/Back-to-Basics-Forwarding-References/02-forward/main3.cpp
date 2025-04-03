
// Forwarding reference

#include <memory>

// Deduced function template parameter declared as rvalue reference to cv-unqualified type template parameter
template <typename T>
void f(T &&x);

// C++20:
void f(auto &&x);

// Special kind of reference that binds to any function argument
int       i = 42;
int const ci = 42;

int make_int() {
    return 42;
}

int main() {
    f(i);             // OK
    f(ci);            // OK
    f(std::move(i));  // OK
    f(std::move(ci)); // OK
    f(42);            // OK
    f(make_int());    // OK
}
