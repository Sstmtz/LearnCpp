
// Iterators have different Categories (C++98)
//
// Random access iterators
// - Can jump to and compare with any other position
//   =, *, ==, !=, --, +=, -=, <, <=, ..., [], ...
// - vector<>, array<>, deque<>, raw arrays, strings
//
// Bidirectional iterators
// - Can iterate forward and backward
//   =, *, ++, ==, !=, --
// - list<>, associative containers (set<>, map<>, ...)
//
// Forward iterators
// - Can iterate forward only
//   =, *=, ++, ==, !=
// - forward_list<>, unordered containers (hash tables)
//
// Input iterators
// - Can read elements only once
// - istream_iterator<>

// Range/Iterator Categories/Concepts (since C++20)
//
//  Contiguous range/iterator
// - Can jump to and compare with any other position
//   =, *, ==, !=, --, +=, -=, <, <=, ..., [], -
// - iterator may be raw pointer, range has std::ranges::data()
// - vector<>, array<>, raw arrays, strings
//
// Random access range/iterator
// - Can jump to and compare with any other position
//   =, *, ==, !=, --, +=, -=, <, <=, ..., [], -
// - deque<>
//
// Bidirectional range/iterator
// - Can iterate forward and backward
//   =, *, ++, ==, !=, --
// - list<>, associative containers (set<>, map<>, ...)
//
// Forward range/iterator
// - Can iterate forward multiple times
//   =, *=, ++, ==, !=
// - forward_list<>, unordered containers (hash tables)
