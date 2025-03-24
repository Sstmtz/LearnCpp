#include <generator>
#include <iostream>
#include <print>

std::generator<int> getSequeneceGenerator(int startValue, int numberOfValues) {
    for (int i {startValue}; i < startValue + numberOfValues; ++i) {
        // Yield a value to the callers, and suspend the coroutine.
        co_yield i;
    }
}

int main() {

    auto gen {getSequeneceGenerator(10, 5)};
    for (auto const &value : gen) {
        std::print("{} (Press enter for next value)", value);
        std::cin.ignore();
    }

    return 0;
}
