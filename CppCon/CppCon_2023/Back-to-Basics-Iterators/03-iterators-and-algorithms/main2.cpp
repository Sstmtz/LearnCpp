
// Implementation of STL Algorithms
//
// Algorithms are generic:
// - Using the iterator interface of all containers
// - Provided all operations are supported

#include <iostream>
#include <set>
#include <string>
#include <vector>

template <typename IterT, typename ValueT>
ValueT accumulate(IterT beg, IterT end, /*range*/ ValueT val /* initial value*/) {
    for (IterT pos = beg; pos != end; ++pos) {
        val = val + *pos;
    }
    return val;
}

int main() {
    std::vector<long> coll {1, 2, 3, 4, 5};
    auto              res1 = accumulate(coll.begin(), coll.end(), 0L);
    std::cout << "sum: " << res1 << '\n'; // prints 15

    std::set<std::string> words {"one",
                                 "two",
                                 "three"
                                 "four"};
    auto                  res2 = accumulate(words.begin(), words.end(), std::string {});
    std::cout << res2 << '\n'; // prints onethreefourtwo
}
