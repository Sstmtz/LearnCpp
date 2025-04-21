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

// Direct-initialization also takes place in the member initializer list of a constructor:

class C {
public:
    C();

private:
    demo_str ds;
};

C::C()
    : ds("James") // direct-init
{}
