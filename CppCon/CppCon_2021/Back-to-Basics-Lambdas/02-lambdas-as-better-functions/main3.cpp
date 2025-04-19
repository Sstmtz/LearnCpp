// Using Lambdas

// - Lambdas can be used as objects
//   - Local functions (behavior defined at runtime)
//   - Type has to be `auto` (type name is platform dependent)

#include <algorithm>
#include <iostream>

void processInvoice(Invoice const &iv) {
    double tax = getTax(iv);

    // Local function object that adds tax for invoice iv
    auto plusTax = [tax](double d) {
        return d * (1 + tax);
    };

    // add tax at various places of the invoice:
    std::cout << plusTax(iv.getSum()) << '\n'; // prints result of sum * (1 + tax)

    for (auto const &item : iv) {
        std::cout << plusTax(item) << '\n'; // prints items plus tax
    }

    std::transform(iv.begin(),
                   iv.end(),   // transform elements of the invoice
                   iv.begin(), // writing back the result
                   plusTax);   // to add tax
}

// - Lambdas can be used as objects
//   - Functions passed around (behavior defined at runtime)
//   - Multiple "functions" can co-exist

auto makeAddTaxFunc(Invoice const &iv) {
    double tax = getTax(iv);

    // Return function object that adds tax for invoice iv
    return [tax](double d) {
        return d * (1 + tax);
    };
}

int main() {
    Invoice iv1, iv2;

    auto plusTax1 = makeAddTaxFunc(iv1);
    auto plusTax2 = makeAddTaxFunc(iv2);

    std::cout << plusTax1(iv1.getSum()) << '\n';
    std::cout << plusTax2(iv2.getSum()) << '\n';
}
