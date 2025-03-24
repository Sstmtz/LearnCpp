#include <atomic>

// before C++17:

// In header (.hpp):
extern std::atomic<bool> ready;

// In source file (.cpp)
std::atomic<bool> ready = false;

// since C++17:
// in header (.hpp)
inline std::atomic<bool> ready_ = false;

// before C++17:
struct system {
    static std::atomic<bool> ready;
};

std::atomic<bool> system::ready = false;

// since C++17:
struct system_ {
    static inline std::atomic<bool> ready;
};

int main() {
    return 0;
}
