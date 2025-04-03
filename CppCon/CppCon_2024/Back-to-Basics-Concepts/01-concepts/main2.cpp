#include <set>
#include <vector>

// C++98: Overloading Function Templates

template <typename CollT, typename T>
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
    add(coll1, 42); // ERROR: two definitions of add()
    add(coll2, 42); // ERROR: two definitions of add()
}
