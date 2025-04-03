#include <set>
#include <vector>

// C++20: Concepts as Type Constraints

template <typename CollT>
concept HasPushBack = requires(CollT c, CollT::value_type v) { c.push_back(v); };

void add(HasPushBack auto &coll, auto const &val) {
    coll.push_back(val);
}

// Equivalent to:
// template <HasPushBack T1, typename T2>
// void add(T1 &coll, T2 const &val) {
//     coll.push_back(val);
// }

void add(auto &coll, auto const &val) {
    coll.insert(val);
}

int main() {
    std::vector<int> coll1;
    std::set<int>    coll2;

    add(coll1, 42); // OK: uses 1st add() calling push_back()
    add(coll2, 42); // OK: uses 2nd add() calling insert()
}
