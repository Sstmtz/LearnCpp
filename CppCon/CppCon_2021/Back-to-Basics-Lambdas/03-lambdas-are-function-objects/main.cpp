// Lambdas are Function Objects

// - Lambdas are function objects defined "on the fly"
//   - Simple way to define objects that can be used like functions
//     - Using operator()
// - have a "unique, unnamed non-union class type"
//   - "closure type"

#include <algorithm>
auto add = [](int x, int y) {
    return x + y;
};

// has the effect of:
//
// class lambda??? {
// public:
//     lambda??? (); // only callable by compiler before C++20
//     int operator()(int x, int y) const {
//         return x + y;
//     }
// }
//
// auto add = lambda???{};

int main() {
    int i = 4;
    i = add(17, i); // calls add.operator()(17, i);
}

// while (...) {
//     int min, max;
//     // ...
//     p = std::find_if(coll.begin(), coll.end(), [min, max](int i) {
//         return min <= i && i <= max;
//     });
// }

// has the effect of:
//
// class lambda??? {
// private:
//     int _min, _max;
//
// public:
//     lambda??? (int min, int max) : _min(min), _max(max) {}
//     bool operator()(int i) const {
//         return _min <= i && i <= +max;
//     }
// }
//
// while (...) {
//     int min, max;
//     // ...
//     p = std::find_if(coll.begin(), coll.end(), lambda???{min, max});
// }

template <typename Iter, typename Callback>
Iter find_if(Iter beg,
             Iter end,    // range
             Callback op) // predicate
{
    for (Iter pos = beg; pos != end; ++pos) {
        if (op(*pos)) { // if op() yield true for element
            return pos; // return iterator to element
        } // calls: op.operator()(*pos);
    }
    return end; // non found: return end
}
