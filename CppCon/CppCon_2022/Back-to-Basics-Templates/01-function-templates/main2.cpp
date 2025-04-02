#include <iostream>
#include <set>
#include <string>
#include <vector>

// C++98: Generic Iterating with Function Templates
//
// Iterate over elements of different containers
// with the same generic code:

template <typename T>
void print(T const &coll) {
    for (auto const &elem : coll) {
        std::cout << elem << '\n';
    }
}

int main() {
    std::vector<int>      v;
    std::set<std::string> ss;
    std::vector<double>   v2;
    print(v);
    print(ss);
    print(v2);
}
