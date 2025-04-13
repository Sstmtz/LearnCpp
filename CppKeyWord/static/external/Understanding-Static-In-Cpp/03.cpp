// static member

#include <iostream>

class Thing {
public:
    static int num_things;

    Thing() {
        num_things++;
    }

    ~Thing() {
        num_things--;
    }
};

int Thing::num_things = 0;

int main() {

    std::cout << "There are " << Thing::num_things << " things.\n"; // 0
    Thing thing1;
    Thing thing2;

    std::cout << "There are " << Thing::num_things << " things.\n"; // 2
    thing1.~Thing();
    thing2.~Thing();

    std::cout << "There are " << Thing::num_things << " things.\n"; // 0

    return 0;
}
