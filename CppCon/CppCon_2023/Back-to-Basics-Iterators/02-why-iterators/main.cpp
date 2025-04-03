
// Index Operator vs. Iterator

#include <iostream>
#include <list>
#include <vector>

int main() {
    std::vector<int> vec {0, 8, 15, 47, 11, 42};
    std::cout << vec[3]; // cheap

    std::list<int> lst {0, 8, 15, 47, 11, 42};
    // std::cout << lst[3]; // expensive
}
