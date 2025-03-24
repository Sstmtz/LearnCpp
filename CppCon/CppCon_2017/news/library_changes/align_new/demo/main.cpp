#include <cstddef>
#include <cstdlib>

// before C++17:
template <typename T, typename... Args>
T *new_aligned_array(std::size_t size, std::size_t alignment) {
    void *vp = nullptr;
    int   r = posix_memalign(&vp, alignment, size * sizeof(T));

    return new (vp) T[]();
    // T must be default constructible.
}

struct alignas(128) person {
    // ...
};

person *p = new_aligned_array(1024, alignof(person));

// since C++17:
struct alignas(128) person {
    // ...
};

person *p = new person[1024];
// calls operator new[](sizeof(person), std::align_val_t(alignof(person)))
