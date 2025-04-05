
// No Function Template Arguments

#include <execution>
#include <numeric>

template <class ExecutionPolicy, class ForwardIt, class T, class BinaryOp, class UnaryOp>
T transform_reduce(ExecutionPolicy &&policy, ForwardIt first, ForwardIt last, T init, BinaryOp reduce, UnaryOp transform);

// route_const find_best_route(int *const distances, int N) {
//     return std::transform_reduce(std::execution::par,
//                                  counting_iterator<long>(0L),
//                                  counting_iterator<long>(factorial(N)),
//                                  route_const(),
//                                  route_const::min,
//                                  [=](long i) {
//                                      int cost = 0;
//                                      // ... calculate cost ...
//                                      return route_cost(i, cost);
//                                  });
// }
