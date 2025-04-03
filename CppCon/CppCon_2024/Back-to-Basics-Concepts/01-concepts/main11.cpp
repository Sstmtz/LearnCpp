#include <set>
#include <vector>

// C++20: Granularity of Concepts

template <typename CollT, typename T>
concept CanPushBack = requires(CollT c, T v) { c.push_back(v); };

void add(auto &coll, auto const &val)
    requires CanPushBack<decltype(coll), decltype(val)>
{
    coll.push_back(val);
} // Don't include a concept for each statement (too fine grained)

void add(auto &coll, auto const &val) {
    coll.insert(val);
}

int main() {
    std::vector<int> coll1;
    std::set<int>    coll2;

    add(coll1, 42); // OK: uses 1st add() calling push_back()
    add(coll2, 42); // OK: uses 2nd add() calling insert()
}
