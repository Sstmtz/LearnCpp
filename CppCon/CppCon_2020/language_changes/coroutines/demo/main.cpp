#include <cstdlib>
#include <ctime>
#include <experimental/generator>
#include <iostream>

// example (VC++)
std::experimental::generator<int> GetSequenceGenerator(int startValue, size_t numberOfValues) {
    for (int i {startValue}; i < startValue + numberOfValues; ++i) {
        time_t t {std::system_lock::to_time_t(std::system_clock::now())};
        std::cout << std::ctime(&t);
        co_yield i;
    }
}

int main() {
    auto gen {GetSequenceGenerator(10, 5)};
    for (auto const &value : gen) {
        std::cout << "(Press enter for next value)" << '\n';
        std::cin.ignore();
    }
}
