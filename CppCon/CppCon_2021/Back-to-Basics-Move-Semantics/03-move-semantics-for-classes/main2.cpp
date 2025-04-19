// Move Semantics and Special Member Functions

#include <iostream>
#include <ostream>
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

    Cust(Cust const &) = default; // copy constructor

    // no move constructor

    // - Move semantics is disabled
    //   because of user-declared other special member function
    // - Copying used as fallback

    friend std::ostream &operator<<(std::ostream &strm, Cust const &c) {
        return strm << "[" << c.val << ": " << c.first << " " << c.last << "]";
    }
};

int main() {
    std::vector<Cust> v;
    Cust c1 {"Joe", "Fox", 77};
    // by default, if we can't use move, copying is used
    // so this will copy the `Cust` into the vector
    v.push_back(std::move(c1));        // copies c1
    std::cout << "c1: " << c1 << '\n'; // c1: [77: Joe Fox]
}
