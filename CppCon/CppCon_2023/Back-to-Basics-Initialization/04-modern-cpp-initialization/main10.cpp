// explicit Constructors, Revisited

#include <cstddef>

// As before, the main difference between direct-list-initialization and copy-list-initialization is
// whether `explicit` constructors are considered.

// For example, suppose that this `demo_str` constructor were declared `explicit`:

class demo_str {
public:
    // ...
    explicit demo_str(char const *str);
    // ...
private:
    std::size_t stored_length;
    char *actual_str;
};

// Then direct-list-initialization would permit conversions from `char const*` to `demo_str`,
// whereas copy-list-initialization would not:

class C {
public:
    // ...
    C(int x, demo_str const &str);
    // ...
};

C c1 {10, "Crusher"};   // OK
C c2 = {10, "Crusher"}; // ERROR, requires implicit conversion
