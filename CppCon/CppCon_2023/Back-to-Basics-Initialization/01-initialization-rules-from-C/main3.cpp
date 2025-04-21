// We can also copy-initialize a structure or union from another object of a compatible type:

struct widget {
    int id;
    double price;
};

int main() {
    widget w1 = {1000, 6.5}; // aggregate-init
    widget w2 = w1;          // copy-init

    // Neither C or C++ lets us copy-initialize an array:
    int a1[3] = {1, 4, 9}; // aggregate-init
    // int a2 = a1;           // ERROR
}
