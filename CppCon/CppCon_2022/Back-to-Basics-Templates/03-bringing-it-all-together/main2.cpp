// C++20: auto as Function Parameters

#include <set>
#include <vector>

void add(auto &coll, auto const &val) {
    coll.push_back(val);
}

void add(auto &coll, auto const &val) {
    coll.insert(val);
}

int main() {
    std::vector<int> coll1;
    std::set<int>    coll2;

    add(coll1, 42); // ERROR: ambiguous
    add(coll2, 42); // ERROR: ambiguous
}
