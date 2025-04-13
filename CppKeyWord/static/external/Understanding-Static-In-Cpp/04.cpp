// static member
//
// Inside a class definition, the keyword static declares members that are not bound to class instances.

#include <iostream>

class Thing {
private:
    static int num_things;

public:
    Thing() {
        num_things++;
    }

    ~Thing() {
        num_things--;
    }

    // So, static functions can only access static variable
    static int get_num_things() {
        return num_things;
    }

    static void set_num_things(int n) {
        num_things = n;
    }
};

int Thing::num_things = 0;

int main() {

    // These non-static functions belong to an instance of the class and
    // thus cannot be called unless we first instantiate any instance of the class
    // in other words, we can no longer print `num_things` utils we first create a
    // `Thing` if instead these methods were marked static

    std::cout << "There are " << Thing::get_num_things() << " things.\n"; // 0
    Thing thing1;
    Thing thing2;

    std::cout << "There are " << Thing::get_num_things() << " things.\n"; // 2
    thing1.~Thing();
    thing2.~Thing();

    std::cout << "There are " << Thing::get_num_things() << " things.\n"; // 0

    return 0;
}
