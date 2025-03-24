#include <exception>
#include <print>
#include <stacktrace>

class MyException : public std::exception {
public:
    MyException(std::string message, std::stacktrace st = std::stacktrace::current())
        : m_message {std::move(message)}
        , m_stacktrace {std::move(st)} {}

    char const *what() const noexcept override {
        return m_message.c_str();
    }

    std::stacktrace const &trace() const noexcept {
        return m_stacktrace;
    }

private:
    std::string     m_message;
    std::stacktrace m_stacktrace;
};

void bar() {
    throw MyException {"Some exception..."};
}

void foo() {
    bar();
}

int main() {
    try {
        foo();
    } catch (MyException const &e) {
        std::println("Exception caught: {}", e.what());
        std::println("Stacetrace:\n{}", e.trace());
    }
}
