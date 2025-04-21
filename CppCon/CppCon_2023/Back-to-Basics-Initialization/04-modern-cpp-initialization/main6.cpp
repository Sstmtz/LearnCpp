// Uniform Initialization Synatx
#include <cstddef>

// Modern C++ attempted to address these concerns by generalizing brace
// initialization to create a uniform initialization synatx.

// All types now support initialization via braces:

class demo_str {
private:
    std::size_t stored_length;
    char *actual_str;
};

int x {3};                      // scalar
int arr[3] {1, 4, 9};           // aggregate
demo_str ds {"Hello World", 5}; // class with constructor

// Unfortunately, there are still good reasons to use the other forms of initialization
// in Modern C++.
