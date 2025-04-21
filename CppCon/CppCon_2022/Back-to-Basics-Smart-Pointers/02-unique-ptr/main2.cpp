// UNIQUE_PTR

// Basic usage - class

#include <memory>

// WidgetBase *create_widget(InputType);
//
// class MyClass {
//     std::unique_ptr<WidgetBase> owner;
//
// public:
//     MyClass(InputType inputs) : owner(create_widget(inputs)) {}
//
//     ~MyClass() = default;
//     // ... member functions that use owner-> ...
// };
