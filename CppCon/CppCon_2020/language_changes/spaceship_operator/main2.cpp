// Spaceship operator <=>
// Offical name: Three-way comparison operator
// Comparing 2 objects and then comparing result with 0

// (a <=> b) < 0; // true if a < b
// (a <=> b) > 0; // true if a > b
// (a <=> b) = 0; // true if a == b
// Similar to C-style strcmp() returning neg. value 0 or pos

#include <compare>

// C++17: support all six comparison operators
class Point {
    int x;
    int y;

public:
    friend bool operator==(Point const &a, Point const &b) {
        return a.x == b.x && a.y == b.y;
    }

    friend bool operator<(Point const &a, Point const &b) {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    }

    friend bool operator!=(Point const &a, Point const &b) {
        return ! (a == b);
    }

    friend bool operator<=(Point const &a, Point const &b) {
        return ! (b < a);
    }

    friend bool operator>(Point const &a, Point const &b) {
        return b < a;
    }

    friend bool operator>=(Point const &a, Point const &b) {
        return ! (a < b);
    }

    // non-comparison functions ...
};

// C++20: this single line of code is all you need,
// and the compiler will automatically generate all six types of operators for you.
class Point2 {
    int x;
    int y;

public:
    auto operator<=>(Point2 const &) const = default;
    // non-comparison functions ...
};

int main() {
    return 0;
}
