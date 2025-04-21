// 4. Initializing STL Containers

#include <vector>

// With aggregate-initialization, we can easily initialize an array with arbitrary contents:
int values[] = {1, 2, 3};

// Unfortunately, it's much more difficult to initialize an STL container with
// arbitrary contents in C++03:
int values[] = {1, 2, 3};
std::vector<int> v(values, values + 3);
