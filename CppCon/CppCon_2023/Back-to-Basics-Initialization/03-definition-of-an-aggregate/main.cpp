// Direct-Initialization

#include <cstddef>

class demo_str {
public:
    demo_str();
    demo_str(char const *str);
    demo_str(char const *str, std::size_t length);
    demo_str(demo_str const &other);            // copy constructor
    demo_str &operator=(demo_str const &other); // copy assignment operator
    ~demo_str();

private:
    std::size_t stored_length;
    char *actual_str;
};

int main() {
    // We can direct-initialize a demo_str by providing constructor arguments in parentheses:
    demo_str ds1("Hello", 5); // calls demo_str(char const *str, std::size_t length)
    demo_str ds2(ds1);        // calls demo_str(demo_str const &other)
}
