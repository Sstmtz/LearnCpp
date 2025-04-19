// Objects with Names

// Often you can't avoid objects with names:

// 1. When you need a object/value multiple names:

// std::string str {getData()};
// // ...
// coll1.push_back(str); // copy (still need the value of str)
// coll2.push_back(str); // copy (but no longer need the value)

// 2. When you deal with parameters:

// void reinit(std::string &s) {
//     history.push_back(s); // copy (but no longer need the value)
//     s = getDefaultValue();
// }

// read line-by-line from myStream and store them all in a collection:

// std::string row;
// while (std::getline(myStream, row)) { // read next line into row
//     allRows.push_back(row);           // and copy it to collection of all rows
// }

// std::move() for Objects with Names
//
// std::move(): "I no longer need this value here"

// 1. When you need a object/value multiple names:

// std::string str {getData()};
// // ...
// coll1.push_back(str);            // copy (still need the value of str)
// coll2.push_back(std::move(str)); // move (ok, no longer need the value)

// 2. When you deal with parameters:

// void reinit(std::string &s) {
//     history.push_back(std::move(s)); // move (ok, no longer need the value)
//     s = getDefaultValue();
// }

// read line-by-line from myStream and store them all in a collection:
// std::vector<std::string> allRows;
// std::string row;
// while (std::getline(myStream, row)) {  // read next line into row
//     allRows.push_back(std::move(row)); // and move it to collection of all rows
// }
