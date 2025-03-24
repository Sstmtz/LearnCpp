
// before C++23: two options for accessing multidimensional data:
// function call: data(x, y, z)
// multiple levels of array indexing: data[x][y][z]

// since C++23:
// multidimensional subscript operator: data[x, y, z]
// E.g:
// T& operator[](size_t x, size_t y, size_t z) noexcept { /* ... */}
