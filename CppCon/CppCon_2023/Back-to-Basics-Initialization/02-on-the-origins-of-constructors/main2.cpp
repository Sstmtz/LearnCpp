// The aggregate-initialization rules from C would allow someone to create a demo_str with an
// inconsistent stored_length and actual_str:

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

int main() {
    demo_str ds = {5, nullptr}; // empty string of length 5?
}

// Here, the demo_str doesn't respect the class invariant
