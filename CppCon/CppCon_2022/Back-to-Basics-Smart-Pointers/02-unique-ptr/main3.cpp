// UNIQUE_PTR

// Sample implementation

#include <utility>

// template <typename T>
// class unique_ptr {
//     T *ptr;
//
// public:
//     unique_ptr() noexcept : ptr(nullptr) {}
//
//     explicit unique_ptr(T *p) noexcept : ptr(p) {}
//
//     ~unique_ptr() noexcept {
//         delete ptr;
//     }
// };

// template <typename T>
// struct unique_ptr {
//     // ...
//     unique_ptr(unique_ptr const &) = delete; // not copyable
//
//     unique_ptr(unique_ptr &&o) noexcept
//         : ptr(std::exchange(o.ptr, nullptr)) {}         // Move constructor transfers ownership
//
//     unique_ptr &operator=(unique_ptr const &) = delete; // not copyable
//
//     unique_ptr &operator=(unique_ptr &&o) noexcept {
//         delete ptr;      // frees  memory
//         ptr = o.ptr;
//         o.ptr = nullptr; // transfers ownership
//         return *this;
//     }
//
//     // ...
//
// private:
//     T *ptr;
// };

// template <typename T>
// struct unique_ptr {
//     // ...
//     T &operator*() const noexcept {
//         return *ptr;
//     }
//
//     T *operator->() const noexcept {
//         return ptr;
//     }
//
// private:
//     T *ptr;
// };

template <typename T>
struct unique_ptr {
    T *release() noexcept { // gives up ownership
        T *old = ptr;
        ptr = nullptr;
        return old;
    }

    void reset(T *p = nullptr) noexcept { // cleans up takes ownership
        delete ptr;
        ptr = p;
    }

    T *get() const noexcept {
        return ptr;
    }

    explicit operator bool() const noexcept { // test for non-empty
        return ptr != nullptr;
    }

private:
    T *ptr;
};
