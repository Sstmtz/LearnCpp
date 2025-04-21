// Which Initialization Do You Mean?

// When Initializing a class object with data members, there are actually multiple
// initialization taking place
// - The class object itself is initialized
// - The data members of the object are also initialized

// The class object might be initialized with one form of initialization, while a
// data member might be initialized with another...

// Here's an implementation of demo_str's copy constructor:

#include <cstddef>
#include <cstring>

class demo_str {
public:
    demo_str();
    demo_str(char const *str);
    demo_str(char const *str, std::size_t length);

private:
    std::size_t stored_length;
    char *actual_str;
};

demo_str::demo_str(demo_str const *&other)
    : stored_length(other.stored_length)        // direct-init
    , actual_str(new char[stored_length + 1]) { // direct-init
    std::strcpy(actual_str, other.actual_str);
}

// The stored_length and actual_str members are direct-initialized regardless
// of how the demo_str itself is initialized:

demo_str ds2(ds1);  // direct-init
demo_str ds3 = ds1; // copy-init

// As another example, when brace-initializing in aggregate, each element
// follows the rules for copy-initialization:

struct widget {
    int id;
    demo_str ds;
};

widget w1 = {1000, "Spock"};

// w1 is aggregate-initialized, while the `id` and `ds` members are copy-initialized.
