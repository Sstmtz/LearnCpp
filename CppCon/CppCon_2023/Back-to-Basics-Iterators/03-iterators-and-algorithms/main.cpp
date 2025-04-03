
// STL Algorithms (C++98/C++11)
//
// Standard algorithms
// - Process elements of half-open ranges
// - Using the iterator interface for element access
// - Generic to operate on different container types

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int main() {

    std::vector<int> coll {42, 214, 45, 22, 78, 19};

    // sort elements:
    std::sort(coll.begin(), coll.end());

    // find the element with the highest value:
    auto maxPos = std::max_element(coll.begin(), coll.end());
    if (maxPos != coll.end()) { // end() signals: none found (here: range was empty)
        std::cout << "max: " << *maxPos << '\n';
    }

    // process the sum of all elements:
    auto sum = std::accumulate(coll.begin(), coll.end(), 0);
}
