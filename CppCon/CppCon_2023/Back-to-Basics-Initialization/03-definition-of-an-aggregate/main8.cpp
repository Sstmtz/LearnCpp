// Value-Initialization

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

// If we try to include the parentheses in a typical declaration, the compiler will
// misinterpret the statement as a function declaration:

demo_str ds(); // oops: declares a function that takes no parameters and results a demo_str

// This is mostly a consequence of C's rules for parsing declaration
// - Changing this would have interfered with C compatibility.

// However, we can initialize objects with an explicit () in some other initialization contexts:

demo_str::demo_str() : stored_length(), actual_str() {}

demo_str *pds = new demo_str();

// This is another form of initialization called value-initialization
