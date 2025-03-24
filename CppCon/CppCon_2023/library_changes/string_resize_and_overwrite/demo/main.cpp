#include <cstddef>
#include <cstring>
#include <string>

// resize_and_overwrite(count, op)
// 1. resizes a string and sets new content by invoking an operation
// 2. use if performance is critical
// Effect:
// 1. if count <= size(), erase the last size() - count elements
// 2. if count > size(), append (count - size()) defalut-initialized elements
// 3. invokes r = op(data(), count)
// 4. invokes erase(begin() + r, end())

std::string GeneratePattern(std::string const &pattern, size_t count) {
    std::string result;
    result.reserve(pattern.size() * count);
    for (size_t i = 0; i < count; ++i) {
        // Not optiaml:
        // - Write 'count' nulls
        // - Updates size and checks for potential resize 'count' times
        result.append(pattern);
    }
    return result;
}

std::string GeneratePattern_(std::string const &pattern, size_t count) {
    std::string result;
    auto const  step = pattern.size();
    // Good: No initialization
    result.resize_and_overwrite(step * count, [&](char *buf, size_t n) {
        for (size_t i = 0; i < count; ++i) {
            // Good: No bookkeeping
            memcpy(buf + i * step, pattern.data(), step);
        }
        return step * count;
    });
    return result;
}
