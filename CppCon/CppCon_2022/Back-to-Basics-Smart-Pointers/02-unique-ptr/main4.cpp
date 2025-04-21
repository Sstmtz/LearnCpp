// MAKE_UNIQUE

// template <typename T, typename... Args>
// unique_ptr<T> make_unique(Args &&...args);

// Combines together:
// - Allocates memory
// - Constructs a T with the given arguments
// - Wraps it in a std::unique_ptr<T>
// Perfect using make_unique to creating a unique_ptr explicitly

#include <memory>

// Example

// std::unique_ptr<HelperType> owner {new HelperType(inputs)};
// // is better written as
// auto owner = std::make_unique<HelperType>(inputs);

// Non-example

// std::unique_ptr<WidgetBase> owner;
// MyClass(InputType inputs) : owner(create_widget(inputs)) {}

// make_unique doesn't help here, because allocation/construction happens within `create_widget`
