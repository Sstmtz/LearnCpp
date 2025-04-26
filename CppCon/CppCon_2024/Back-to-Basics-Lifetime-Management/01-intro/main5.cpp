#include <iostream>
#include <memory>
#include <string>
#include <utility>

// the Rule of Zero
// Always strive to have the compiler generated Special Member Functions do right thing
//
// example:
// struct Widget {
//     // only value type or managers
// }

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
//     int age = 42;
// };

struct Widget {
    std::string name = "widget";
    int age = 42;
    std::unique_ptr<Gadget> gadget = std::make_unique<Gadget>();
};

void print(Widget const &widget) {
    std::cout << widget.name << '\n';
    std::cout << widget.age << '\n';
}

int main() {
    Widget widget;
    print(widget); // widget 42

    // Widget widget2 = widget;
    // print(widget2); // widget 42
    // Widget widget3 = std::move(widget);
    // print(widget3); // widget 42
    // print(widget);  // (empty string) 42 (move from)
    //
    // widget2 = widget3;
    // print(widget2); // widget 42
    // widget3 = std::move(widget2);
    // print(widget3); // widget 42
    // print(widget2); // (empty string) 42 (move from)

    Widget widget2 = std::move(widget);
    print(widget2); // widget 42
    print(widget);  // (empty string) 42

    widget = std::move(widget2);
    print(widget2); // (empty string) 42
    print(widget);  // widget 42
}
