// Vector Without Move Semantics (C++03)

// Containers have value semantics
// - New elements are copied into the container
// - Passed arguments are not modified
// This leads to unnecessary copies with C++98/03

#include <string>
#include <vector>

// template <typename T>
// class vector {
// public:
//     // ...
//     // copy elem into the vector:
//     void push_back(T const &elem);
//     // ...
// };

// std::vector<std::string> coll;
// std::string s = getData();
// // ...
// coll.push_back(s);         // copy s into coll
// coll.push_back(getData()); // copy temporary into coll
// coll.push_back(s + s);     // copy temporary into coll
// coll.push_back(s);         // copy s into coll (no longer need s)
// return coll;

// Vector with Move Semantics (C++11)

// With rvalue references you can provide move semantics
// Rvalue references bind to rvalues
// - Caller no longer needs the value
// - May steal but keep valid

template <typename T>
class vector {
public:
    // ...
    // copy elem into the vector:
    void push_back(T const &elem);
    // ...
    // move elem into the vector:
    void push_back(T &&elem);
    // ...
};

// std::vector<std::string> coll;
// std::string s = getData();
// // ...
// coll.push_back(s);            // copy s into coll
// coll.push_back(getData());    // move temporary into coll
// coll.push_back(s + s);        // move temporary into coll
// coll.push_back(std::move(s)); // move s into coll (no longer need s)
// return coll;
