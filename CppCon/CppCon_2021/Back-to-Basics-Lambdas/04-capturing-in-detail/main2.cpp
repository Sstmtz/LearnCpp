// Capturing in detail

// - Capturing is performed when the lambda is created
//   - Local read-only copy (unless passed by reference)

#include <iostream>
#include <string>

int main() {
    std::string prefix = "elem: ";
    auto printval = [prefix](int i) { // captures local copy
        std::cout << prefix << i << '\n';
    };

    prefix = "value: "; // no impact no printval
    printval(17);       // prints: elem: 17
}
