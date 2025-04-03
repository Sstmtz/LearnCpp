
// Iterator Categories (C++11)

#include <iostream>

int main() {
    // print all elements (for all containers):
    for (auto pos = coll.begin(); pos != coll.end(); ++pos) {
        std::cout << *pos << '\n';
    }

    // print every 2nd elements (array, vector, deque only):
    for (auto pos = coll.begin(); pos < coll.end(); pos += 2) {
        std::cout << *pos << '\n';
    }

    // print every 2nd elements (for all containers):
    for (auto pos = coll.begin(); pos != coll.end();) {
        std::cout << *pos << '\n';
        ++pos;
        if (pos != coll.end()) {
            ++pos;
        }
    }
}
