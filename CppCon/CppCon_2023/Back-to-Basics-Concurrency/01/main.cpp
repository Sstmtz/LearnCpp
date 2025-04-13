// std::thread

#include <iostream>
#include <thread>

int main() {
    std::thread my_thread {[](int z) {
        std::cout << "Hello from thread: " << z << '\n';
    }};
    my_thread.join();
    return 0;
}
