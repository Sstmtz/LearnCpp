#include <iostream>
#include <string>

// the Rule of Three (before C++11)
// (copy constructor, copy-assignment operator, destructor)
// whenever you're managing a resource if you need any one of those special member functions,
// then you probably need all three

int gadget_number = 0;

struct Gadget {
    int i;

    Gadget() : i(++gadget_number) {
        std::cout << "gadget ctor: #" << i << '\n';
    }

    ~Gadget() { // explicitly implemented default destructor
        std::cout << "gadget dtor: #" << i << '\n';
    }

    Gadget(Gadget const &other) : i(other.i + 1) {
        std::cout << "gadget copy dctor: #" << i << '\n';
    }
};

// int main() {
//     Gadget gadget;
//     std::cout << gadget.i << "\n";
// }

// struct Widget {
//     std::string name;
//     int age;
//     Gadget *gadget;
// };

// struct Widget {
//     std::string name;
//     int age;
//     Gadget *gadget;
//
//     Widget() : age(0), gadget(nullptr) {}
// };

// struct Widget {
//     std::string name = "widget";
//     int age;
//     Gadget *gadget;
//
//     Widget() : age(42), gadget(new Gadget()) {}
//
//     ~Widget() {
//         delete gadget;
//     }
// };

// struct Widget {
//     std::string name = "widget";
//     int age;
//     Gadget *gadget;
//
//     Widget() : age(42), gadget(new Gadget()) {}
//
//     Widget(Widget const &other) // explicitly implemented copy-constructor
//         : name(other.name)
//         , age(other.age)
//         , gadget(new Gadget(*other.gadget)) {}
//
//     ~Widget() {
//         delete gadget;
//     }
// };

// struct Widget {
//     std::string name = "widget";
//     int age;
//     Gadget *gadget;
//
//     Widget() : age(42), gadget(new Gadget()) {}
//
//     Widget(Widget const &other) // explicitly implemented copy-constructor
//         : name(other.name)
//         , age(other.age)
//         , gadget(new Gadget(*other.gadget)) {}
//
//     Widget &operator=(Widget const &other) { // explicitly implemented copy-assignment operator
//         name = other.name;
//         age = other.age;
//         delete gadget; // delete old pointer
//         gadget = new Gadget(*other.gadget);
//         return *this;
//     }
//
//     ~Widget() {
//         delete gadget;
//     }
// };

struct Widget {
    std::string name = "widget";
    int age;
    Gadget *gadget;

    Widget() : age(42), gadget(new Gadget()) {}

    Widget(Widget const &other) // explicitly implemented copy-constructor
        : name(other.name)
        , age(other.age)
        , gadget(new Gadget(*other.gadget)) {}

    Widget &operator=(Widget const &other) { // explicitly implemented copy-assignment operator
        if (this != &other) {                // avoid assign itself
            name = other.name;
            age = other.age;
            Gadget *temp = new Gadget(*other.gadget);
            delete gadget;
            gadget = temp;
        }
        return *this;
    }

    ~Widget() { // destructor
        delete gadget;
    }
};

int main() {
    Widget widget;
    // std::cout << widget.name << '\n';   // default empty string
    // std::cout << widget.age << '\n';    // garbage value
    // std::cout << widget.gadget << '\n'; // garbage address

    // std::cout << widget.name << '\n';   // default empty string
    // std::cout << widget.age << '\n';    // 0
    // std::cout << widget.gadget << '\n'; // 0

    std::cout << widget.name << '\n';   // "widget"
    std::cout << widget.age << '\n';    // 42
    std::cout << widget.gadget << '\n'; // address

    // Widget widget2 = widget;
    // std::cout << widget2.name << '\n';   // "widget"
    // std::cout << widget2.age << '\n';    // 42
    // std::cout << widget2.gadget << '\n'; // address

    widget = Widget();
    std::cout << widget.name << '\n';   // "widget"
    std::cout << widget.age << '\n';    // 42
    std::cout << widget.gadget << '\n'; // address

    widget = widget;
    std::cout << widget.name << '\n';   // "widget"
    std::cout << widget.age << '\n';    // 42
    std::cout << widget.gadget << '\n'; // address
}
