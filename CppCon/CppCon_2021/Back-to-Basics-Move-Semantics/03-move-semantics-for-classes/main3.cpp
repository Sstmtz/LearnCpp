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

    // copy constructor
    Cust(Cust const &c) : first {c.first}, last {c.last}, val(c.val) {}

    // move constructor
    // Mark move constructor with noexcept, if implemented and it never throws
    Cust(Cust &&c) noexcept : first {std::move(c.first)}, last {std::move(c.last)}, val {c.val} {
        c.val *= -1;
    }

    // Parameter c has no move semantics
    // unless marked with move() again,
    // (the caller no longer needs the value, but we might need it multiple times)

    friend std::ostream &operator<<(std::ostream &strm, Cust const &c) {
        return strm << "[" << c.val << ": " << c.first << " " << c.last << "]";
    }
};

int main() {
    std::vector<Cust> v;
    Cust c1 {"Joe", "Fox", 77};
    v.push_back(std::move(c1));        // moves c1
    std::cout << "c1: " << c1 << '\n'; // c1: [-77: ??? ???]
}
