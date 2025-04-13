// Lifetime and Variable

#include <iostream>

void non_statcic_increment() {
    int count = 0;
    count++;
    std::cout << count << '\n';
}

void static_increment() {
    static int count = 0;
    count++;
    std::cout << count << '\n';
}

int count = 0;

void global_increment() {
    count++;
    std::cout << count << '\n';
}

int main() {

    std::cout << "- (Not static keyword): " << '\n';
    for (int i = 0; i < 5; i++) {
        non_statcic_increment();
    }

    std::cout << "- (Has static keyword): " << '\n';
    for (int i = 0; i < 5; i++) {
        static_increment();
    }

    std::cout << "- (Not static keyword, but gloabl): " << '\n';
    for (int i = 0; i < 5; i++) {
        global_increment();
    }
}
