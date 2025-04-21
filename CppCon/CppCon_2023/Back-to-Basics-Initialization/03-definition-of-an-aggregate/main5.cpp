// explicit Constructors

// `demo_str` supports the following constructor (among others):

#include <cstddef>

class demo_str {
public:
    // ...
    demo_str(char const *str);
    // ...
private:
    std::size_t stored_length;
    char *actual_str;
};

// With this constructor as-written, this call to `f` is valid:

void f(demo_str ds); // pass-by-value
f("McCoy");          // copy-init

// If this constructor was declared `explicit`, the call to `f` would be invalid:

class demo_str {
public:
    // ...
    explicit demo_str(char const *str);
    // ...
private:
    std::size_t stored_length;
    char *actual_str;
};

void f(demo_str ds); // pass-by-value
f("McCoy");          // ERROR
