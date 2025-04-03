
// Using Vector Iterators (C++11)

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> coll {1, 2, 3, 5, 8, 9, 11, 13, 17};
    for (int elem : coll) {
        std::cout << elem << ' ';
    }
    std::cout << '\n';

    auto pos8 = std::find(coll.begin(), coll.end(), 8);
    if (pos8 != coll.end()) {
        std::cout << "8 found\n";
        *pos8 *= 2;
    }

    coll.push_back(15);

    if (pos8 != coll.end()) {
        *pos8 *= 2; // fatal runtime ERROR: UB
    }
}
