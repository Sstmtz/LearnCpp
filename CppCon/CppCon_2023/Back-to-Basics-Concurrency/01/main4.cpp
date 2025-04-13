#include <execution>
#include <iterator>
#include <numeric>

// std::transform_reduce -- traveling salesman

// route_const find_best_route(int const *distances, int N) {
//     return std::transform_reduce(std::execution::par,
//                                  std::counted_iterator<loog>(0L),
//                                  std::counted_iterator<loog>(factorial(N)),
//                                  route_cost(),
//                                  route_cost::min,
//                                  [=](loog i) {
//                                      int cost = 0;
//                                      route_iterator it(i, N);
//                                      int from = it.first();
//                                      while (! it.done()) {
//                                          it to = it.next();
//                                          cost += distances[from * N + to];
//                                          from = to;
//                                      }
//                                      return route_cost(i, cost);
//                                  });
// }
