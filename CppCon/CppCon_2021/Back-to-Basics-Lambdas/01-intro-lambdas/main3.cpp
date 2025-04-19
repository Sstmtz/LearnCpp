// Algorithms Using Helper Functions

#include <algorithm>
#include <iostream>
#include <vector>

bool isOdd(int value) {
    return value % 2 != 0;
}

int main() {
    std::vector<int> coll {0, 8, 15, 42, 11, 1, 77, -1, 3};

    // count number of elements with odd value:
    // int num = std::count_if(coll.begin(),
    //                         coll.end(), // range
    //                         isOdd);     // criterion

    // std::cout << "odd elems: " << num << '\n';

    // find position of first element with odd value (returns iteator):
    // auto pos = std::find_if(coll.begin(),
    //                         coll.end(), // range
    //                         isOdd);     // criterion

    // if (pos != coll.end()) {
    //     std::cout << "first odd elem: " << *pos << '\n';
    // }

    // Lambda: Function defined on the fly

    // count number of elements with odd value:
    // int num = std::count_if(coll.begin(),
    //                         coll.end(), // range
    //                         [](int elem) {
    //                             return elem % 2 != 0;
    //                         }); // criterion (defined on the fly)

    // std::cout << "odd elems: " << num << '\n';

    // find position of first element with odd value (returns iteator):
    // auto pos = std::find_if(coll.begin(),
    //                         coll.end(), // range
    //                         [](int elem) {
    //                             return elem % 2 != 0;
    //                         }); // criterion (defined on the fly)

    // if (pos != coll.end()) {
    //     std::cout << "first odd elem: " << *pos << '\n';
    // }

    // Lambda: Function object defined on the fly

    auto isOdd = [](int elem) {
        return elem % 2 != 0;
    };

    // count number of elements with odd value:
    int num = std::count_if(coll.begin(),
                            coll.end(), // range
                            isOdd);     // criterion

    std::cout << "odd elems: " << num << '\n';

    // find position of first element with odd value (returns iteator):
    auto pos = std::find_if(coll.begin(),
                            coll.end(), // range
                            isOdd);     // criterion

    if (pos != coll.end()) {
        std::cout << "first odd elem: " << *pos << '\n';
    }
}
