#include <cstddef>
#include <map>
#include <mutex>
#include <set>
#include <string>
#include <utility>

// if-statement and switch-statement initialization

// before C++17:
template <typename Key, typename Value, typename F>
void find_and_update(std::map<Key, Value> &m, Key k, F f) {
    auto it = m.find(k);
    if (it != m.end()) {
        it->second = f(it->first);
    }
    // `it` can be modify
    // If the variable is still going to be used, that's fine,
    // but if the variable is only used for this if statement, that can lead to potential issues.
}

// since C++17:
template <typename Key, typename Value, typename F>
void find_and_update2(std::map<Key, Value> &m, Key k, F f) {
    if (auto it = m.find(k); it != m.end()) {
        it->second = f(it->first);
    }
    // `it` can't be modify
}

// before C++17:
std::string string_poo::pop(std::size_t new_cap) { // please ignore this undeclared identifier `string_poo`
    std::string s;

    // if you don't hold the lock while allocating memory
    // you need to put a scope around this lock guard
    {
        std::lock_guard<std::mutex> l(mtx_);
        if (pool_.empty()) {
            std::swap(s, pool_.back());
        }
    }

    if (s.capacity() < new_cap) {
        s.reserve(new_cap);
    }

    return s;
}

// since C++20:
std::string string_poo::pop2(std::size_t new_cap) { // please ignore this undeclared identifier `string_poo`
    std::string s;

    // now, you just put the lock guard right in that if statement here.
    if (std::lock_guard<std::mutex> l(mtx_); pool_.empty()) {
        std::swap(s, pool_.back());
    }

    if (s.capacity() < new_cap) {
        s.reserve(new_cap);
    }

    return s;
}

// combine with if-statement initialization
template <typename Key, typename F>
void emplace_or_throw(std::set<Key> &m, Key &&k, F f) {
    if (auto [it, s] = m.emplace(std::forward<Key>(k)); ! s) {
        throw /* ... */;
    } else {
        f(*it);
    }
}
