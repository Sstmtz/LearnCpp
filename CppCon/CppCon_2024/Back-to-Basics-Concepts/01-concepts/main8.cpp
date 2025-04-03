#include <set>
#include <vector>

// C++20: Concepts in requires Clauses

template <typename CollT>
concept HasPushBack = requires(CollT c, CollT::value_type v) { c.push_back(v); };

void add(HasPushBack auto &coll, auto const &val)
    requires HasPushBack<decltype(coll)> // std::vector<int>&::value_type is not valid
{
    coll.push_back(val);
}

void add(auto &coll, auto const &val) {
    coll.insert(val);
}

int main() {
    std::vector<int> coll1;
    std::set<int>    coll2;

    add(coll1, 42); // ERROR: can't call insert()
    add(coll2, 42); // OK: uses 2nd add() calling insert()
}
