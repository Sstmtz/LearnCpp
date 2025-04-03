#include <set>
#include <vector>

// C++98: Generic Function to Insert a Value

template <typename CollT, typename T>
void add(CollT &coll, T const &val) {
    coll.push_back(val);
}

int main() {
    std::vector<int> coll1;
    std::set<int>    coll2;
    add(coll1, 42); // OK
    add(coll2, 42); // ERROR: no pusk_back()
}
