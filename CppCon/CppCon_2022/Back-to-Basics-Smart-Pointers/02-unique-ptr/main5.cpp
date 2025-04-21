// UNIQUE_PTR

// Array types

// unique_ptr is specialized for array types
// - Calls delete[] instead of delete
// - Provides operator[]
// make_unique is specialized for array types
// - Argument is number of elements, not constructor arguments

#include <memory>

// Fixing the first example from the begining of the talk:
// void science(double *data, int N) {
//     auto temp = std::make_unique<double[]>(N * 2);
//     do_setup(data, temp.get(), N);
//     if (not needed(data, temp.get(), N)) {
//         return;
//     }
//     calculate(data, temp.get(), N);
// }
