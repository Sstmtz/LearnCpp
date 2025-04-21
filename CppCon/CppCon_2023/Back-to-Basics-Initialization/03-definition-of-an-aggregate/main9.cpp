// Roundabout Value-Initialization

// Using value-initialization in other contexts was possible in C++03, but you had to do it in a
// roundabout way:

#include <cstddef>

class demo_str {
public:
    demo_str();
    demo_str(char const *str);
    demo_str(char const *str, std::size_t length);

private:
    std::size_t stored_length;
    char *actual_str;
};

int x = int();            // x is 0
demo_str ds = demo_str(); // call default constructor

// This is really a combination of value-initialization and copy-initialization

// Moreover, until C++17, this roundabout form of value-initialization required an accessible copy
// constructor:

class C {
public:
    C();

private:
    // disable copy operations in C++03
    C(C const &other);
    C &operator=(C const &other);
};

C c = C(); // ERROR: copy constructor inaccessible
