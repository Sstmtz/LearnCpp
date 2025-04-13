// C++ parallel algorithms
//
// Loops to algorithms

#include <algorithm>
#include <cstdint>
#include <execution>
#include <functional>
#include <mutex>
#include <numeric>
#include <vector>

int main() {

    // Some raw loops can be converted into parallel algorithms

    std::vector<std::int64_t> v {10, 20, 30, 40, 50};

    // std::int64_t sum = 0;
    // for (std::int64_t x : v) {
    //     sum += x;
    // }

    // std::int64_t sum = 0;
    // std::for_each(std::execution::par_unseq, v.begin(), v.end(), [&sum](std::int64_t x) {
    //     sum += x; // Oops! Data race
    // });

    // std::int64_t sum = 0;
    // std::mutex mtx;
    // std::for_each(std::execution::par_unseq, v.begin(), v.end(), [&sum, &mtx](std::int64_t x) {
    //     std::scoped_lock lock(mtx); // Emmm... Absymal performance!
    //     sum += x;
    // });

    std::int64_t sum = std::reduce(
        std::execution::par_unseq, v.begin(), v.end(), std::int64_t(0), std::plus<> {});
}
