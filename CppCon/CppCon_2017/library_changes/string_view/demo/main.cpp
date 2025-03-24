#include <string>
#include <string_view>

// before C++17:
std::string first_3(std::string const &s) {
    if (s.size() < 3) {
        return s;
    }

    // expensive copy
    // may allocate
    return s.substr(0, 2);
}

// since C++17:
std::string_view first_3_(std::string_view s) {
    if (s.size() < 3) {
        return s;
    }

    // cheap copy
    // won't allocate
    return s.substr(0, 2);
}

int main() {
    if (first_3("ABCDEFG") == "ABC") {
        // ...
    }

    if (first_3_("ABCDEFG") == "ABC") {
        // ...
    }
}
