// Lambdas are More Than Functions

// - Local functions
// - Convenient way to define functions at runtime
//   - Functions with state

#include <algorithm>
#include <vector>

std::vector<int> c {0, 8, 15, 42, 11, 1, 77, -1, 3};

// bool less7(int v) {
//     return v < 7;
// }
//
// bool less8(int v) {
//     return v < 8;
// }
//
// int main() {
//     std::count_if(c.begin(), c.end(), less7);
//     std::count_if(c.begin(), c.end(), less8);
// }

//     void foo(int max) {
//         std::count_if(c.begin(), c.end(), lessMax); // ???
//     }

int main() {

    std::count_if(c.begin(), c.end(), [](int v) {
        return v < 7;
    });

    std::count_if(c.begin(), c.end(), [](int v) {
        return v < 7;
    });
}

void foo(int max) {
    std::count_if(c.begin(),
                  c.end(),
                  // function (object) created on the fly
                  [max](int v) {
                      return v < max;
                  });
}
