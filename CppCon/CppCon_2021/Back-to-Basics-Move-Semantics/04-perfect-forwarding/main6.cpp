// Perfect Passing with auto&&

// To perfect forward a return value
// - declare returned value as auto&&
//   - Universal/forwarding reference without being a template parameter
// - and forward

#include <utility>

// // for example:
// // pass return value type of compute() to process()
// process(compute(t)); // OK, prefect
//
// // same, but doing something between compute() and process():
// auto &&val = compute(t);
// // ...
// process(std::forward<decltype(val)>(val));
