#include <set>
#include <vector>

// C++20: auto as Function Parameters

void add(auto &coll, auto const &val) {
    coll.push_back(val);
}

// 1. Equivalent to:
// template <typename T1, typename T2>
// void add(T1 &coll, T2 const &val) {
//     coll.push_back(val);
// }
//
// 2. Definition usually in header files
// 3. No `inline` necessary

void add(auto &coll, auto const &val) {
    coll.insert(val);
}

int main() {
    std::vector<int> coll1;
    std::set<int>    coll2;
    add(coll1, 42); // ERROR: two definitions of add()
    add(coll2, 42); // ERROR: two definitions of add()
}
