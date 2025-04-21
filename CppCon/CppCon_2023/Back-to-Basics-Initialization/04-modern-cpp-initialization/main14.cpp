// Initialization in Templates

// Because of the potential for confusion, using brace initialization inside
// templates isn't necessarily the corrent solution.

#include <initializer_list>
#include <memory>
#include <utility>
#include <vector>

// Which `std::vector<int>` constructor does this statement invoke ?

using VI = std::vector<int>;
std::unique_ptr<VI> p = std::make_unique<VI>(12, -1);

// If `std::make_unique` uses direct-initialization, `p` points to a vector
// containing 12 copies of -1

// If it uses direct-list-initialization, `p` points to a vector containing a 12 and a -1

// It depends on whether `std::make_unique` is implemented something like this:

template <typename T, typename... Args>
unique_ptr<T> make_unique(Args &&...args) {
    // direct-initialization
    return unique_ptr<T>(new T(std::forward<Args>(args)...));
}

// or more like this:
template <typename T, typename... Args>
unique_ptr<T> make_unique(Args &&...args) {
    // direct-initialization
    return unique_ptr<T>(new T {std::forward<Args>(args)...});
}

// If you want to invoke the constructor that takes a `std::initializer_list`, you can write:

using VI = std::vector<int>;
std::initializer_list<int> init {12, -1};
std::unique_ptr<VI> p = std::make_unique<VI>(init);

// When in doubt, follow the model set by the Standard Library and use direct-initialization for
// template types

// If you have good reason to use different form of initialization, make it clear in your
// documentation.
