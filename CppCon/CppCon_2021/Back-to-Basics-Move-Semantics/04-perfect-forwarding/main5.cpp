// Using Generated and Implemented Move Semantics

#include <string>
#include <utility>
#include <vector>

class Cust {
private:
    std::string first;
    std::string last;
    int val;

public:
    Cust(std::string const &f, std::string const &l, int v) : first {f}, last {l}, val(v) {}

    // ... no special member functions
};

// std::vector<Cust> cv;

// cv.push_back(Cust {"Art", "Lee", 42}); // create customer and copy/move it into `cv`

// template <typename T, ...>
// class Vector {
// public:
//     // ...
//     template <typename... Args>
//     void emplace_back(Args &&...args) {
//         place_element_in_memory(T(std::forward<Args>(args)...));
//     }
//     // ...
// };

// std::string first {"Jil"};
// std::string last {"Cook"};
// // first was moved, last was copied
// cv.emplace_back(std::move(first), last, 39); // create new customer inside cv
