#include <concepts>
#include <ranges>
#include <set>
#include <string>
#include <vector>

// C++20: Concepts and Error Messages

// void add(auto &coll, auto const &val) {
//     if constexpr (requires { coll.push_back(val); }) {
//         coll.push_back(val);
//     } else {
//         coll.insert(val);
//     }
// }

template <std::ranges::range CollT, typename T>
void add(CollT &coll, T const &val)
    requires std::convertible_to<T, std::ranges::range_value_t<CollT>>
{
    if constexpr (requires { coll.push_back(val); }) {
        coll.push_back(val);
    } else {
        coll.insert(val);
    }
}

int main() {
    std::vector<int>      coll1;
    std::set<std::string> coll2;

    add(coll1, 42); // OK: calls push_back()
    // add(coll2, 42); // ERROR in the code of std::set<> when calling insert()
    add(coll2, 42); // ERROR when calling add()
}
