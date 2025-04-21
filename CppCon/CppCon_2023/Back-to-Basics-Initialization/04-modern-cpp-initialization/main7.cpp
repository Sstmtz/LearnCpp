// Value-Initialization in Modern C++

#include <cstddef>

// Empty braces now provide a convenient way to perform value-initialization without the ambiguity
// of parentheeses.

class demo_str {
private:
    std::size_t stored_length;
    char *actual_str;
};

int x;                // uninitialized
int y();              // oops, function declaration
int z {};             // value-init, z is 0
int *p1 = new int();  // value-init, *p1 is 0
int *p2 = new int {}; // value-init, *p2 ois 0

demo_str ds1;         // default-init, calls demo_str()
demo_str ds2();       // still a function
demo_str ds3 {};      // value-init, calls demo_str()

// This can make it much easier to ensure that objects are initialized in a template context:

template <typename T>
void f(T const &t) {
    T obj {}; // definitely not uninitialized
}

// If `T` is a class type with constructors, `obj` will be initialized by calling the default
// constructor.

// If `T` is a scalar type, `obj` will be zero-initialized
