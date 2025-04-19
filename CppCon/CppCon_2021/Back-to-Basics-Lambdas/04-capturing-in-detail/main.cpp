// Lambdas: Capture by Value

// Objects capture by value are by default `read-only copies`
// - to make the lambdas stateless (can't change its behavior)

#include <algorithm>
#include <deque>
#include <iostream>

int main() {
    std::deque<int> coll {1, 3, 19, 5, 13, 7, 11, 2, 17};

    int min = 5;
    int max = 12;

    // find position of first element greater than x and less than y:
    auto pos = std::find_if(coll.begin(),
                            coll.end(),
                            [min, max](int i) // capture x and y
                            {
                                return min <= i && i <= max;
                            });

    if (pos != coll.end()) {
        std::cout << "first found element: " << *pos << '\n';
    }
}
