#include <print>
#include <vector>

// Copy an object in C++:
// auto c = x;
// but `c` is lvalue

// C++23 adds `auto(x)` or `auto{x}`
// 1. Copy is a prvalue
// E.g:
void process(int &&value) {
    std::println("{}", value);
}

void process_all(std::vector<int> const &data) {
    for (auto &i : data) {
        process(auto(i));
    }
}

int main() {
    return 0;
}
