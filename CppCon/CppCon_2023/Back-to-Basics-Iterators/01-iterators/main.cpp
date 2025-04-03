
// Loop Over Arrays
//
// Two ways to iterate over the elements of an array
// - Using indexes
// - Using pointers

#include <iostream>

int main() {
    int arr[] = {10, 20, 30, 40};

    // iterate over elements with index:
    for (int i = 0; i < 4; ++i) {
        std::cout << arr[i] << '\n';
    }

    // iterate over elements with pointer:
    for (int *p = arr; p < arr + 4; ++p) {
        std::cout << *p << '\n';
    }
}
