#include <iostream>
#include <string>

class Student {
private:
    int         m_age;
    std::string m_name;

public:
    Student(int age, std::string name) : m_age(age), m_name(name) {}

    void hello() {
        std::cout << "Hello " << m_name << '\n';
    }

    void print() {
        // before C++20, [=] captures `this` implicity
        // auto fn = [=]() { this->hello(); }; // deprecated warning
        // since C++20, need to be explict, so: [=, this]
        auto fn2 = [=, this]() {
            this->hello();
        };
        // fn();
        fn2();
    }
};

int main() {
    auto stu = new Student(12, "John");
    stu->print();
}
