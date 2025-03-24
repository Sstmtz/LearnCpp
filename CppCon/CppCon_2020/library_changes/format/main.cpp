#include <format>
#include <iostream>

int main() {
    int n = 0;
    std::cout << std::format("{:=^19}", "CppCon 2020") << '\n'; // ====CppCon 2020====
    // use placeholder,
    // you can change the order of the placeholder instead of arguments
    // so you don't have modify the order of your arguments
    std::cout << std::format("Read {0} btyes from {1}", n, "file1.txt") << '\n';
    std::cout << std::format("从 {1} 中读取 {0} 字节", n, "file1.txt") << '\n';
}
