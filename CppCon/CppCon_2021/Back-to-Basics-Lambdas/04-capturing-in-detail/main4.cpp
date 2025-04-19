// C++14: Lambda Capture Initializers

// Since C++14, you can pass initializers to lambda captures
// - Enables adding local state
// - Enables capturing by const reference with std::as_const()

#include <iostream>
#include <utility>

int main() {
    // compute price function on the fly:
    auto price = [disc = getDiscount(cust)](auto item) { // compute discount once for cust
        return getPrince(item) * disc;                   // and use it for all function calls
    };

    for (auto const &item : order) {
        std::cout << "your price: " << price(item) << '\n';
    }

    // capture by const&:
    auto coll = ...;

    auto dealWithColl = [&coll = std::as_const(coll)] { // ensure coll can't be modified
        // ...
    };

    dealWithColl(); // coll can be used inside the lambda but is not mutable
}
