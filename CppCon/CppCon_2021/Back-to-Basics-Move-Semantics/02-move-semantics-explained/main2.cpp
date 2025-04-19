// Strings With Move Semantics

// Move semantics is usually implemented in:
// - a move constructor
// - a move assignment operator
// as optimized copying
// - Steals by keeping the source valid

// class string {
// private:
//     int len;    // current number of characters
//     char *data; // array of characters
//
// public:
//     // create a full copy of s:
//     string(string const &s)
//         : len(s.len)                       // copy length
//     {
//         if (len > 0) {                     // if not empty
//             data = new char[len + 1];      // new memory
//             memcpy(data, s.data, len + 1); // copy memory
//         }
//     }
//
//     // create a copy of s with its content moved:
//     string(string &&s)
//         : len(s.len)      // copy length and
//         , data(s.data)    // copy pointer to memory
//     {
//         s.data = nullptr; // erase memory at source
//                           // to really move ownership
//         s.len = 0;
//     }
// };

// string x = "move";
//
// coll.push_back(x);
// string e1 = x;
//
// coll.push_back(std::move(x));
// string e2 = std::move(x); // std::move(x) is equivalent to static_assert<string&&>(x)
