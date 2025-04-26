#include <algorithm>
#include <iostream>
#include <string>
#include <utility>

// the Rule of Five (since C++11, added the move operations)
// (copy constructor,
//  move constructor,
//  copy-assignment operator,
//  move-assignment operator,
//  destructor)
// if you want move semantics then you probably need all five

int gadget_number = 0;

struct Gadget {
    int i;

    Gadget() : i(++gadget_number) {
        std::cout << "gadget ctor: #" << i << '\n';
    }

    ~Gadget() {
        std::cout << "gadget dtor: #" << i << '\n';
    }

    Gadget(Gadget const &other) : i(other.i + 1) {
        std::cout << "gadget copy ctor: #" << i << '\n';
    }
};

// struct Widget {
//     std::string name = "widget";
//     int age;
//     Gadget *gadget;
//
//     Widget() : age(42), gadget(new Gadget()) {}
//
//     Widget(Widget const &other)
//         : name(other.name)
//         , age(other.age)
//         , gadget(new Gadget(*other.gadget)) {}
//
//     Widget &operator=(Widget const &other) {
//         // There seems to be a memory leak issue here
//         Widget temp(other);
//         std::swap(name, temp.name);
//         std::swap(age, temp.age);
//         std::swap(gadget, temp.gadget);
//         return *this;
//     }
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
//     Widget(Widget const &other)
//         : name(other.name)
//         , age(other.age)
//         , gadget(new Gadget(*other.gadget)) {}
//
//     Widget &operator=(Widget const &other) {
//         Widget temp(other);
//         std::swap(name, temp.name);
//         std::swap(age, temp.age);
//         std::swap(gadget, temp.gadget);
//         return *this;
//     }
//
//     Widget(Widget &&other) noexcept
//         : name(std::move(other.name))
//         , age(std::move(other.age))
//         // , gadget(std::move(other.gadget)) {} // ERROR: didn't actually move the resource
//         //     , gadget(other.gadget) {
//         //     other.gadget = nullptr;
//         // }
//         , gadget(std::exchange(other.gadget, nullptr)) {}
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

    Widget(Widget const &other)
        : name(other.name)
        , age(other.age)
        , gadget(new Gadget(*other.gadget)) {}

    Widget &operator=(Widget const &other) {
        Widget temp(other);
        std::swap(name, temp.name);
        std::swap(age, temp.age);
        std::swap(gadget, temp.gadget);
        return *this;
    }

    Widget(Widget &&other) noexcept
        : name(std::move(other.name))
        , age(std::move(other.age))
        , gadget(std::exchange(other.gadget, nullptr)) {}

    Widget &operator=(Widget &&other) noexcept {
        name = std::move(other.name);
        age = other.age;
        gadget = std::exchange(other.gadget, nullptr);
        return *this;
    }

    ~Widget() {
        delete gadget;
    }
};

int main() {
    Widget widget;
    std::cout << widget.name << '\n';   // "widget"
    std::cout << widget.age << '\n';    // 42
    std::cout << widget.gadget << '\n'; // address

    // if you do move operations and you don't have move constructor or move-assignment operator,
    // it's going to fallback to the copy operations and they will just work
    // Widget widget2 = std::move(widget);
    // std::cout << widget2.name << '\n';   // "widget"
    // std::cout << widget2.age << '\n';    // 42
    // std::cout << widget2.gadget << '\n'; // address

    // Widget widget2 = std::move(widget);
    // std::cout << widget2.name << '\n';   // "widget"
    // std::cout << widget2.age << '\n';    // 42
    // std::cout << widget2.gadget << '\n'; // address

    // if you do move-assignment operations but you don't have move-assignment operator,
    // it's going to fallback to the copy operations and they will just work
    // Widget widget2;
    // widget2 = std::move(widget);
    // std::cout << widget2.name << '\n';   // "widget"
    // std::cout << widget2.age << '\n';    // 42
    // std::cout << widget2.gadget << '\n'; // address

    Widget widget2;
    widget2 = std::move(widget);
    std::cout << widget2.name << '\n';   // "widget"
    std::cout << widget2.age << '\n';    // 42
    std::cout << widget2.gadget << '\n'; // address
}
