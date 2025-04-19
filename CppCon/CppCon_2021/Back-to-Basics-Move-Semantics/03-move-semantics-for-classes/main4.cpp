// Move Semantics in Polymorphic Classes

// - Declared virtual destructors disable move semantics
//   - Moveing special member functions are not generated
//   - If and only if a polymorphic base class has members expensive to copy,
//     it might make sense to declare/define move operations
// - Don't declare destructors in derived classes (unless you have to)

#include <string>
#include <vector>

class Person {      // polymorphic base class with virtual functions
protected:
    std::string id; // to support move semantics for id, declare move functions

public:
    virtual void print() const = 0;
    virtual ~Person() = default; // disables move semantics for members
};

class Customer : Person {  // derived polymorphic class
protected:
    std::vector<int> data; // move semantics for data enabled without special function
public:
    virtual void print() const override;
    // virtual ~Customer() = default; // disables move semantics for members
};
