#include <set>
#include <vector>

// C++20: Constraints with Concepts

template <typename CollT>
concept HasPushBack = requires(CollT c, CollT::value_type v) { c.push_back(v); };

// template <typename CollT, typename T>
//     requires HasPushBack<CollT>
template <HasPushBack CollT, typename T>
void add(CollT &coll, T const &val) {
    coll.push_back(val);
}

template <typename CollT, typename T>
void add(CollT &coll, T const &val) {
    coll.insert(val);
}

int main() {
    std::vector<int> coll1;
    std::set<int>    coll2;
    add(coll1, 42); // OK: uses 1st add() calling push_back()
    add(coll2, 42); // OK: uses 2nd add() calling insert()
}
