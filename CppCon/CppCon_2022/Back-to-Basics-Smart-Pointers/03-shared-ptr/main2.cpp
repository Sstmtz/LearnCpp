// MAKE_SHARED

// template <typename T, typename... Args>
// shared_ptr<T> make_shared(Args &&...args);

// Combines together:
// - One memory allocation for both the object and the control block
// - Constructs a T with the given arguments
// - Initializes the control block
// - Wraps them in a std::shared_ptr<T> object
// Prefer using make_shared to creating a shared_ptr directly

// Shared ownership

// To share ownership, additional shared_ptr objects must be created or assigned from an existing
// shared_ptr, not from the raw pointer

#include <memory>
#include <thread>

// {
//     T *p = ...;
//     std::shared_ptr<T> a(p);
//     std::shared_ptr<T> b(p);
// } // runtime error: double free

// {
//     auto a = std::make_shared<T>();
//     std::shared_ptr<T> b(a.get());
// } // runtime error: double free

// {
//     auto a = std::make_shared<T>();
//     std::shared_ptr<T> b(a);
//     std::shared_ptr<T> c;
//     c = b;
// }

// Thread safety

// Updating the same control block from different threads is thread safe

// auto a = std::make_shared(42);
// std::thread t(
//     [](std::shared_ptr<int> b) {
//         std::shared_ptr<int> c = b; // increment count
//         work(*c); // read object
//     }, // decrement count
//     a);
// {
//     std::shared_ptr<int> d = a; // increment count
//     a.reset((int *)nullptr); // decrement count
//     more_work(*d); // read object
// } // decrement count
// t.join();

// Updating the managed object from different threads is not thread safe

// auto a = std::make_shared(42);
// std::thread t(
//     [](std::shared_ptr<int> b) {
//         std::shared_ptr<int> c = b;
//         *c = 100; // write to object (data race!)
//     },
//     a);
// {
//     std::shared_ptr<int> d = a;
//     a.reset((int *)nullptr);
//     *d = 200; // write to object (data race!)
// }
// t.join();

// Updating the same shared_ptr object from different threads is not thread safe

// auto a = std::make_shared<int>(42);
// std::thread t([&]() {           // capture `a` by reference
//     work(*a);                   // read and write (data race!)
// });
// a = std::make_shared<int>(100); // read and write (data race!)
// t.join();
