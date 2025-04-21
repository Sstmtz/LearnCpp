// UNIQUE_PTR

// Transfer ownership

// Use move constructor/assignment to transfer ownership

#include <memory>
#include <utility>

// auto a = std::make_unique<T>();
// // ...
// // std::unique_ptr<T> b {a.release()}; // don't use that
// std::unique_ptr<T> b {std::move(a)};
// // ...
// // a.reset(b.release()); // don't use that
// a = std::move(b);

// To transfer ownership to a function, pass std::unique_ptr by value
// To return ownership from a function, return std::unique_ptr by value

// std::unique_ptr<float[]> science(std::unique_ptr<float[]> x, std::unique_ptr<float[]> y, int N) {
//     auto z = std::make_unique<float[]>(N);
//     saxpy(2.5, x.get(), y.get(), z.get(), N);
//     return z;
// }

// WidgetBase* create_widget(InputType);
// // better communicates its intent if changed to
// std::unique_ptr<WidgetBase> create_widget(InputType);
