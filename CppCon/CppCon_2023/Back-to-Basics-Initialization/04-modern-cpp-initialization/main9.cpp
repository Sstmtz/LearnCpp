// Copy-List-Initialization

#include <cstddef>

// We can also use braces with = to perform a form of copy-initialization
// called `copy-list-initialization`

// For now, these definitions produce the same results:

class demo_str {
private:
    std::size_t stored_length;
    char *actual_str;
};

int x = 5;
int y = {5};

// Both of these call demo_str(char const*)
demo_str ds1 = "Picard";
demo_str ds2 = {"Riker"};
