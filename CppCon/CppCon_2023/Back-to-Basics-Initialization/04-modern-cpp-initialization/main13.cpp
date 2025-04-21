// Now or Never

// For example, suppose that type `C` looks like this:

#include <cstddef>
#include <initializer_list>
#include <vector>

// Adding a `std::initializer_list<int>` constructor would change which
// constructor is used to initialize c1:

class C {
public:
    C();                                // #1
    C(int x, int y);                    // #2
    C(std::initializer_list<int> init); // #3
    // ...
};

// C c1 {10, 20}; // if, not have #3, calls #2
C c1 {10, 20}; // calls #3, used to call #1

// The problem can also occur in the other direction when removing a `std::initializer_list`
// constructor.

// The authors of the Standard Library had a unique opportunity when they added
// `std::initializer_list` constructors to the STL types.

// At the time, there was definitely no existing code that looked like this:

std::vector<int> v {1, 2, 3};

// Your code is likely to change more often than the Standard Library types do.

// By the way, the compiler has much less difficulty when the brace-enclosed list contains objects
// of different types:

class demo_str {
public:
    // ...
    demo_str(char const *str, std::size_t length); // #1
    demo_str(std::initializer_list<char> init);    // #2
    // ...
private:
    std::size_t stored_length;
    char *actual_str;
};

demo_str ds {"Hello World", 5}; // calls #1
