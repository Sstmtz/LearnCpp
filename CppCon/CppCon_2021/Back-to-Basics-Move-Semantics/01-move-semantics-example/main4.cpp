// Re-using Objects after std::move()

// - Yes, it makes sense to re-use objects after std::move()

// read line-by-line from myStream and store them all in a collection:
// std::vector<std::string> allRows;
// std::string row;
// while (std::getline(myStream, row)) {  // read next line into row
//     allRows.push_back(std::move(row)); // and move it to collection of all rows
// }

// swap two strings
#include <string>
#include <utility>

void swap(std::string &a, std::string &b) {
    std::string tmp {std::move(a)};
    a = std::move(b);   // assign new value to moved-from a
    b = std::move(tmp); // assign new value to moved-from a
}
