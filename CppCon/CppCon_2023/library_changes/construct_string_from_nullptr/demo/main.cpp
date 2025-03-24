#include <string>
#include <string_view>

int main() {
    // C++20 and older,
    // compile is ok
    // but has ub at runtime!
    std::string s {nullptr};

    // C++23:
    // compile error
    // no more ub
}
