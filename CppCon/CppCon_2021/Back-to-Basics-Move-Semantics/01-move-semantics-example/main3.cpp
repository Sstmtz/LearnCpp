// Processing Multiple Times

// std::vector<std::string> coll;
// coll.reserve(3);
//
// std::strings s {getData()};
// coll.push_back(s);
// coll.push_back(s); // would copy again

// std::vector<std::string> coll;
// coll.reserve(3);
//
// std::strings s {getData()};
// coll.push_back(s);
// coll.push_back(std::move(s)); // move

// So, What is the state of s afterwards ?
// Is is a half destoryed ?
// It a valid string ?
// It is completely destoryed ?
// Can we still use s ?

// A move-from-library object is in a valid but unspecified state
// std::cout << s;   // OK, some value
// int i = s.size(); // OK, consistent value
// s.append('.');    // OK, size() >= 1
// char c1 = s[0];   // OK, some value
// char c2 = s[5];   // ERROR (UB)
// s = "hello";      // OK, specified state
// ...
