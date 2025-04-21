// Direct-Initialization vs. Copy-Initialization

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

// Let's take another look at this example:

demo_str ds1("Hello", 5);
demo_str ds2(ds1);

// ds2's initialization uses demo_str's copy constructor
// - However, perhaps suprisingly, this is still considered direct-initialization rather than
// copy-initialization
// By contrast, ds3's initialization is copy-initialization because the initializer is specified via
// an =:

demo_str ds3 = ds1;

// Initialization vs. Assignment

// Although the initializer is specified via a=, it does not invoke demo_str's operator= function

class demo_str {
public:
    demo_str(demo_str const &other);            // #1
    demo_str &operator=(demo_str const &other); // #2
};

demo_str ds3 = ds1; // invokes #1, not #2

// Especially when dealing with class types, it's important to distinguish between initialization
// and assignment...

// Initialization vs. Assignment

// Initialization occurs only when an object is first created
// - Initialization gives an object its initial state
// - For a class type with constructors, initialization invokes a constructor

demo_str ds1("Hello", 5); // direct-init
demo_str ds2(ds1);        // copy-init

// Assignment occurs only when overwriting the value of an existing object
// - Assignment is the only way to invoke an operator= member function

ds1 = ds2; // assignment, invokes operator=

// Because assignment replaces the value of an existing object, it may need to clean
// up to the object's previous state (e.g., delete allocated memory)

// Copy-Initialization

// In general, copy-initialization occurs when:
// - an initializer is given via an `=`
// - passing an object by value
// - returning an object by value
// - throwing an exception
// - catching an exception by value
