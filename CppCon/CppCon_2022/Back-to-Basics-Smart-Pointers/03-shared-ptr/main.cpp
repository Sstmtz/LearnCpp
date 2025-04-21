// SHARED_PTR

// One required template parameter, which is the pointed-to type

// template <typename T>
// struct shared_ptr {
//     // ...
//     using element_type = T;
//     // ...
// };

// template <typename T>
// struct shared_ptr {
//     // ...
//     shared_ptr() noexcept;    // create empty shared_ptr
//     explicit shared_ptr(T *); // starts managing an object
//     ~shared_ptr() noexcept;   // decrements count (Cleanup if count = 0)
//     // ...
// };

// template <typename T>
// struct shared_ptr {
//     // ...
//     shared_ptr(shared_ptr const &) noexcept;  // copies object and control block pointers
//     increments count shared_ptr(shared_ptr &&) noexcept; // transfers ownership
//     shared_ptr(unique_ptr<T> &&);             // transfers ownership
//
//     shared_ptr &operator=(shared_ptr const &) noexcept;
//     shared_ptr &operator=(shared_ptr &&) noexcept;
//     shared_ptr &operator=(unique_ptr<T> &&) noexcept;
//     // ...
// };

// template <typename T>
// struct shared_ptr {
//     // ...
//     T &operator*() const noexcept;
//     T *operator->() const noexcept;
//     // ...
// };

template <typename T>
struct shared_ptr {
    // ...
    void reset(T *);
    T *get() const noexcept;
    long use_count() const noexcept;
    explicit operator bool() const noexcept;
};
