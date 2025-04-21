// Direct-List-Initialization
#include <cstddef>

// We can now use braces to perform a form of direct-initialization similar to parentheses.
// - Direct-initialization with braces is called `direct-list-initialization`

// For now, these definitions produce the same results:

class demo_str {
private:
    std::size_t stored_length;
    char *actual_str;
};

int x(5);
int y {5};

// Both of these call demo_str(char const*, std::size_t)
demo_str ds1("Hello World", 5);
demo_str ds2 {"Hello World", 5};

// We can use direct-list-initialization in the same places where we can use direct-initialization:

class C {
public:
    C();

private:
    demo_str ds1, ds2;
};

C::C()
    : ds1("Uhura")   // direct-init
    , ds2 {"Chekov"} // direct-list-init
{}
