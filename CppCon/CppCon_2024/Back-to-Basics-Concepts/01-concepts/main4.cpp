#include <set>
#include <vector>

// C++20: Invalid Concepts
//
// Requirements not met
// => Concept not satisfied 1st add() ignored

template <typename CollT>
concept HasPushBack = requires(CollT c, CollT::value_type v) {
    c.pushback(v); // OOPS: spelling error
};

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

    // 2nd add() is used, because concept for 1st add() not satisfied
    add(coll1, 42); // ERROR: can't call insert()
    add(coll2, 42); // OK: uses 2nd add() calling insert()
}
