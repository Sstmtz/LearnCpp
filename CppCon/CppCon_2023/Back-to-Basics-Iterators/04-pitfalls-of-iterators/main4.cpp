
// Using Inserters (C++98/C++11)
//
// Inserters:
// - Iterators that know the objects they iterate over
// - Insert instead of overwrite

#include <algorithm>
#include <iterator>
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
    std::transform(src.begin(),
                   src.end(),
                   std::back_inserter(d2), /* OK */
                   square);
}
