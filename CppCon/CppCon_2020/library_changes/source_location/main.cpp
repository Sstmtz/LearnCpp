#include <iostream>
#include <source_location>

void LogInfo(std::string_view info, std::source_location const &location = std::source_location::current()) {
    std::cout << location.file_name() << ": " << location.line() << ": " << info << '\n';
}

int main() {
    LogInfo("Welcome to CppCon 2020!");
}
