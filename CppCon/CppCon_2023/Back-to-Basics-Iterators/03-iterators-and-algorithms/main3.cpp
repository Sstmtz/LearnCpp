
// Standard Template Library (STL) (C++98)
//
// - Data structures as ranges
// - Algorithms
// - Iterators as glue interface

// STL Algorithms for Pointers (C++98)
//
// Algorithms are generic:
// - Using the iterator interface of all containers
// - Provided all operations are supported

#include <iostream>

template <typename IterT, typename ValueT>
ValueT accumulate(IterT beg, IterT end, ValueT val) {
    for (IterT pos = beg; pos != end; ++pos) {
        val = val + *pos; // all value of each element
    }
    return val;
}

int main() {
    double arr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double res = accumulate(arr, arr + 5, 0.0);
    std::cout << res << '\n'; // prints 16.5
}
