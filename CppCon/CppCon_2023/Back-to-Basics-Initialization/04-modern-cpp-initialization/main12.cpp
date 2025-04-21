// Initializer Lists

#include <algorithm>
#include <cstddef>
#include <initializer_list>
#include <iterator>
#include <vector>

// As mentioned, C++03 allowed us to create an array with arbitrary contents:
int values[] = {1, 2, 3};

// Modern C++ lets us create user-defined types that can be initialized in much
// the same way.

// To do so, we write a constructor that takes an argument of type std::initializer_list<T>
// (defined in the header<initializer_list>)...

// For example, we could give `demo_str` a constructor that takes a `std::initializer_list<char>`:

class demo_str {
public:
    demo_str();
    demo_str(char const *str);
    demo_str(char const *, std::size_t length);
    demo_str(std::initializer_list<char> init);
    //...
private:
    std::size_t stored_length;
    char *actual_str;
};

// `std::initializer_list` are often passed by value.
// - Copying a `std::initializer_list` produces a shallow copy

// We can use a constructor that takes a `std::initializer_list` for both direct-list-initialization
// and copy-list-initialization:

demo_str ds1 {'D', 'a', 't', 'a'}; // direct-list-init
demo_str ds2 {'T', 'r', 'o', 'i'}; // copy-list-init

// If we have an object of a `std::initializer_list` type, we can also use it for traditional
// direct-initialization and copy-initialization:

std::initializer_list<char> worf {'W', 'o', 'r', 'f'};
demo_str ds3(worf);  // direct-init
demo_str ds4 = worf; // copy-init

// If a class has both a default constructor and a `std::initializer_list` constructor,
// empty braces invoke the default constructor:

demo_str ds1 {'D', 'a', 't', 'a'}; // direct-list-init
demo_str ds2 {};                   // value-init

// If a class has a `std::initializer_list` constructor and doesn't have a default constructor,
// empty braces are interpreted as an empty `std::initializer_list`.

// `std::initializer_list` supports iterators, just like the STL container types.
// Here's an implementation of the `std::initializer_list<char>` constructor for `demo_str`:

demo_str::demo_str(std::initializer_list<char> init)
    : stored_length(std::size(init))
    , actual_str(new char[stored_length + 1]) {
    std::copy(std::cbegin(init), std::cend(init), actual_str);
    actual_str[stored_length] = '\0';
}

// Many types with constructors that take `std::initializer_list` parameters
// are templates, such as `std::vector`:

template <typename T>
class vector {
public:
    using size_type = ...;
    // ...
    vector(size_type count);
    vector(size_type count, T const &value);
    vector(std::initializer_list<T> init);
    // ...
};

std::vector<int> v {1, 2, 3, 4, 5};

// Unfortunately, if `C` is a class type with a `std::initializer_list` constructor, it's
// possible for these two definitions to invoke differenet constructors:

C c1(1, 2);
C c2 {1, 2};

// This is most common when `C` is a class template type, such as `std::vector<T>`

// These definitions invoke the constructors that you would probably expect:

std::vector<int> a;           // default constructor
std::vector<int> b(12);       // one-argument constructor
std::vector<int> c(12, -1);   // two-argument constructor
std::vector<int> d {1, 2, 3}; // std::initializer_list constructor

// However, you might be surprised that these definitions invoke the `std::initializer_list`
// constructor:

std::vector<int> e {12};     // std::initializer_list constructor
std::vector<int> f {12, -1}; // std::initializer_list constructor

// Overload resolution strongly favors initializer lists.

// This confusion usually occurs when the `std::initializer_list` holds a type that
// closely resembles arguments to other constructors

// Here, 12 can be interpreted as either `std::vector<int>::size_type` or
// `std::initializer_list<int>`:

std::vector<int> v1(12);  // std::vector<int>::size_type
std::vector<int> v2 {12}; // std::initializer_list<int>
