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

    // no copy constructor
    // no move constructor

    // - Move semantics is enabled
    //   because no other special member function is user-declared
    // - Unless a move is not implementable

    friend std::ostream &operator<<(std::ostream &strm, Cust const &c) {
        return strm << "[" << c.val << ": " << c.first << " " << c.last << "]";
    }
};

int main() {
    std::vector<Cust> v;
    Cust c1 {"Joe", "Fox", 77};
    v.push_back(std::move(c1)); // moves c1
    // so you will see that the first name and the last name was moved away
    std::cout << "c1: " << c1 << '\n'; // c1: [77: ??? ???]
}
