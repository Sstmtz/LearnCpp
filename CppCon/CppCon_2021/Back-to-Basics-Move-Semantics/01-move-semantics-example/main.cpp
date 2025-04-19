// Copy Semantics (with C++98/03)

// std::vector<std::string> coll;
// coll.reserve(3);
// std::string s {getData()};
// coll.push_back(s);
// // create a copy from but at the end of this statement we destorye all temporary objetcs
// coll.push_back(getData());

// Stack            Heap
//
// coll:
// [ 2 ]     ->  [ 4 ][5 ][ ]
//                 |   |
//                 |   ['d']['a']['t']['a']['2']['\0']  (a copy)
//                 ['d']['a']['t']['a']['\0']
// s:
// [ 4 ]     ->   ['d']['a']['t']['a']['\0']
//
// getData():
// [ 5 ] (destoryed) ->   ['d']['a']['t']['a']['2']['\0'] (destoryed)

// Move Semantics (with C++11)

// std::vector<std::string> coll;
// coll.reserve(3);
// std::string s {getData()};
// coll.push_back(s);
// // we still have a temporary objetc and still at the end of statement
// // this temporary objetc is destoryed
// // then we call the destructor, and the destructor will not free any memory
// // because the memory is gone, and was moved to the new second element of the vector
// coll.push_back(getData()); // destruct temporary

// Stack            Heap
//
// coll:
// [ 2 ]     ->  [ 4 ][5 ][ ]
//                 |   |
//                 |   --------------------------|
//                 |                             |
//                 ['d']['a']['t']['a']['\0']    |
// s:                                            |
// [ 4 ]     ->   ['d']['a']['t']['a']['\0']     |
//                                               |
//                      -------------------------|
//                      |
// getData():           |
// [ 5 ] (destoryed)   ['d']['a']['t']['a']['2']['\0'] (move)
