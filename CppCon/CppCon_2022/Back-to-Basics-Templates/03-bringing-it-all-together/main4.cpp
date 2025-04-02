// C++20: requires and Compile-Time if

#include <set>
#include <vector>

void add(auto &coll, auto const &val) {
    if constexpr (requires { coll.push_back(val); }) {
        coll.push_back(val);
    } else {
        coll.insert(val);
    }
}

int main() {
    std::vector<int> coll1;
    std::set<int>    coll2;

    add(coll1, 42); // OK: calls push_back()
    add(coll2, 42); // OK: calls insert()
}
