// UNIQUE_PTR

// Gotchas

// Make sure only one unique_ptr for a block of memory

#include <memory>

// T *p = ...;
// std::unique_ptr<T> a {p};
// std::unique_ptr<T> b {p};
// crash due to double free

// auto c = std::make_unique<T>();
// std::unique_ptr<T> d {c.get()};
// crash due to double free

// Don't create a unique_ptr from a pointer unless you know where the pointer came
// from and that it needs an owner

// unique_ptr doesn't solve the dangling pointer problem

// T *p = nullptr;
// {
//     auto u = std::make_unique<T>();
//     p = u.get();
// }
// // p is now dangling and invalid
// auto bad = *p; // UB
