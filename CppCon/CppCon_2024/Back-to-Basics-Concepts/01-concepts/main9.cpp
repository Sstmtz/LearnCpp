#include <ranges>
#include <set>
#include <type_traits>
#include <vector>

// C++20: Concepts and Type Functions

// template <typename CollT>
// concept HasPushBack = requires(CollT c, CollT::value_type v) { c.push_back(v); };

// void add(HasPushBack auto &coll, auto const &val)
//     requires HasPushBack<std::remove_cvref_t<decltype(coll)>> // solution 1
// {
//     coll.push_back(val);
// }

// template <typename CollT>
// concept HasPushBack = requires(CollT c, std::remove_cvref_t<CollT>::value_type v) { c.push_back(v); }; // solution 2

// Works for references and raw arrays
template <typename CollT>
concept HasPushBack = requires(CollT c, std::ranges::range_value_t<CollT> v) { c.push_back(v); }; // solution 3

void add(HasPushBack auto &coll, auto const &val)
    requires HasPushBack<decltype(coll)>
{
    coll.push_back(val);
}

void add(auto &coll, auto const &val) {
    coll.insert(val);
}

int main() {
    std::vector<int> coll1;
    std::set<int>    coll2;

    add(coll1, 42); // OK: uses 1st add() calling push_back()
    add(coll2, 42); // OK: uses 2nd add() calling insert()

    // test case:
    static_assert(HasPushBack<std::vector<int> &>);
}
