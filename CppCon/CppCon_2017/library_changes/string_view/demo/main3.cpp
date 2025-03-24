#include <string>
#include <string_view>

// before C++17:
int to_int(std::string const &s);
int to_int(char *const &s);
// int to_int(my_string *const &s);

// since C++17:
int to_int(std::string_view s);

struct my_string {
    // ...

    operator std::string_view() const {
        return std::string_view(data(), size());
    }
};
