
// Writing Algorithms
//
// - Output iterators overwrite
//   - Refer to a location for an element and don't know where ranges end
//   - Similar to raw pointers
//   => There must be elements to overwrite

#include <algorithm>
#include <list>
#include <vector>

int square(int val) {
    return val * val;
}

int main() {
    std::list<int> src {1, 2, 3, 4, 5, 6};

    // std::vector<int> d1;
    // std::transform(src.begin(),
    //                src.end(),
    //                d1.begin(), /* ERROR */
    //                square);

    std::vector<int> d2;
    d2.resize(src.size()); // set size big enough
    std::transform(src.begin(),
                   src.end(),
                   d2.begin(), /* OK */
                   square);
}
