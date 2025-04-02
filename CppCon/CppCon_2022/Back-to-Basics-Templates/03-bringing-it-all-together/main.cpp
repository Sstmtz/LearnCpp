
// C++98: Let' Add Values to a Collection

#include <vector>

template <typename Coll, typename T>
void add(Coll &coll, T const &val) {
    coll.push_back(val);
}

int main() {
    std::vector<int> coll;
    add(coll, 42); // OK
}
