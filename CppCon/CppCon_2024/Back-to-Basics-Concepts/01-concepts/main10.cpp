#include <set>
#include <vector>

// C++20: Concepts for Multiple Parameters

template <typename CollT, typename T>
concept CanPushBack = requires(CollT c, T v) { c.push_back(v); };

template <typename CollT, typename T>
    requires CanPushBack<CollT, T>
void add(CollT &coll, T const &val) {
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
}
