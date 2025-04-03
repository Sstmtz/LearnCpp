
// auto and cbegin() / cend() (C++11)
//
// To support auto for read-only iterations, we have:
// - Type const_iterator

#include <iostream>

// template <typename T>
// void processElements(T &coll) {
//     // ...
//     for (typename T::const_iterator pos = coll.begin(); pos != coll.end(); ++pos) {
//         std::cout << *pos << '\n'; // *pos = 0; does not compile
//     }
// }

// C++11:
template <typename T>
void processElements(T &coll) {
    // ...
    for (auto pos = coll.cbegin(); pos != coll.cend(); ++pos) { // Partially broken by C++2x views
        std::cout << *pos << '\n';
    }
}
