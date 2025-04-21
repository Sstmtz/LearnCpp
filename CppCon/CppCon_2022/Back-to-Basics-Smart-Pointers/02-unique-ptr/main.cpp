// UNIQUE_PTR

// Basic usage - function

#include <memory>

// One required template parameter, which is the pointed-to-value
template <typename T>
struct unique_ptr {
    // ...
    using element_type = T;
    using pointer = T *;
    // ...
};

// void calculate_more(HelperType &);
//
// ResultType do_work(InputType inputs) {
//     // Create unique_ptr with newly allocated memory
//     std::unique_ptr<HelperType> owner {new HelperType(inputs)};
//     owner->calculate();
//     calculate_more(*owner);
//     return owner->important_result();
// } // delete happens automatically
