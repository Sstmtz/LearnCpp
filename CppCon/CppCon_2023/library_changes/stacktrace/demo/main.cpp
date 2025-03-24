#include <print>
#include <stacktrace>

// allow you to get and work with stacktrace

int main() {
    auto trace {std::stacktrace::current()};
    std::println("{}", trace);
}
