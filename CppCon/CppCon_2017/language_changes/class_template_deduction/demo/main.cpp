#include <string>
#include <string_view>
#include <vector>

// namespace std {
//     template <typename It>
//     vector(It b, It e) -> vector<typename std::iterator_traits<It>::value_type>;
// }

template <typename T>
struct name {
    constexpr name(T first_, T last_);
    T first;
    T last;
};

name(char const *) -> name<std::string_view>;

int main() {
    std::vector f8 = {0, 1, 1, 2, 3, 5, 8, 13}; // uses automatic deduction
    auto        it = f8.begin();
    std::vector f4(it, it + 4);                 // uses deduction guide

    name        n("John", "Smith");             // name<std::string_view>
    std::string first = "Hello";
    std::string last = "World";
    name        n2(first, last); // name<std::string>
}
