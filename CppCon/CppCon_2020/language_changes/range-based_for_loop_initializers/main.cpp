#include <vector>

struct Foo {
    int value;
    int result;
};

Foo GetData() {
    return Foo();
}

Foo *GetData2() {
    return new Foo();
}

struct Foo2 {
    std::vector<int> values;
};

Foo2 GetData3() {
    return Foo2();
}

int main() {

    // Range-based for Condition Initializer
    // C++17, support `switch` and `if`
    switch (auto data {GetData()}; data.value) {
        case 1: return data.result;
    }
    if (auto data {GetData2()}; data) {
        // use data
    }

    // Range-based for Loop Initializer
    // C++20, support `for`
    for (auto data {GetData3()}; auto &value : data.values) {
        // use data
    }
}
