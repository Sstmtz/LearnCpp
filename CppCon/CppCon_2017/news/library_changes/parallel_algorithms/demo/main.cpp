#include <algorithm> // *
#include <cmath>
#include <cstddef>
#include <execution>
#include <numbers> // *
#include <numeric>
#include <vector>  // *

// template <typename ExecutionPolicy, ...>
// auto algorithm(ExecutionPolicy& exec, ...);

// execution policies:
// std::seq: serial
// std::par: parallel (SIMT)
// std::par_unseq: parallel and unordered (SIMT and SIMD)

int main() {
    // before C++17:
    std::vector<T> x = /* ... */;

#pragma omp parallel for simd
    for (std::size_t i = 0; i < x.size(); ++i) {
        process(x[i]);
    }

    // since C++17:
    std::for_each(std::par_unseq, x.begin(), x.end(), process);

    // serial:
    std::sort(x.begin(), x.end());
    // parallel:
    std::sort(std::par, x.begin(), x.end());

    std::vector<double> x = /* ...*/;
    std::vector<double> y = /* ...*/;
    // serial:
    // doublele dot_product = (x[0] * y[0]) + (x[1] * y[1]) + /* ... */;
    // parallel:
    // double dot_product = std::transform_reduce(std::par_unseq, x.begin(), x.end(), y.begin());

    // serial:
    // double norm = std::sqrt(x[0] * x[0] + x[1] * x[1] + /* ... */);
    // parallel:
    // double norm = std::sqrt(std::transform_reduce(
    //     std::par_unseq,
    //     // Input sequence
    //     x.begin(),
    //     x.end(),
    //     // Initial reduction value
    //     double(0.0),
    //     // Binary reduction op: Addition
    //     [](double x1, double xr) {
    //         return x1 + xr;
    //     },
    //     // Unary transform op: Squaring
    //     [](double x) {
    //         return x * x;
    //     }));
}
