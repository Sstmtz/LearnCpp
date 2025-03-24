#include <mutex>

// before C++17:
auto grab_lock(std::mutex &m) {
    return std::lock_guard<std::mutex>(m);
    // compile error: copy or move ctor
    // require; lock_guard has neither
}

// since C++17:
auto grab_lock_(std::mutex &m) {
    return std::lock_guard(m);
}

int main() {
    std::mutex mtx;
    auto guard = grab_lock(mtx);

    std::mutex mtx_;
    auto guard_ = grab_lock_(mtx_);
}
