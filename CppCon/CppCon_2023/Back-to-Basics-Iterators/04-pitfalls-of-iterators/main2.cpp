
// std::transform() with 4 Arguments (C++98/C++11)

#include <algorithm>
#include <list>
#include <vector>

int square(int val) {
    return val * val;
}

void foo() {
    // std::list<int>   src;
    // std::vector<int> dest;
    std::list<int>   src {1, 2, 3, 4, 5, 6}; // some elements
    std::vector<int> dest;                   // empty
    // ...

    // transform all elements of the source range to the square in the destination range
    // - overwrites: does not insert
    // - precondition: dest.size() >= src.size()
    std::transform(src.begin(),
                   src.end(),    /* source range*/
                   dest.begin(), /* begin of destination range*/
                   square);      /* transformation */
    // Fatal runtime ERROR: UB
}
