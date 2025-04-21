// Most of C++98/03's new initialization rules have to do with class types,
// constructors, and object lifetime.
//  - An object's lifetime begins after its been initialization
//  - C doesn't really distinguish between storage duration and lifetime.

// As an example, consider the simple string class: demo_str:

#include <cstddef>

class demo_str {
private:
    std::size_t stored_length;
    char *actual_str;
};

// demo_str stores its contents in a dynamically-allocated array.
// For example, the storage for a demo_str representing "hello" looks like:

// demo_str
// stored_length 5
// actual_str    -> 'h' 'e' 'l' 'l' 'o' '\0'

// A demo_str's stored_length should always be one less than the size of the array to which
// actual_str pointes.
// - We call this a **class invariant**.
// - It's one of the main reasons why classes needed new initialization rules.
