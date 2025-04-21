// We can initialize an aggregate with a brace-enclosed list:
struct widget {
    int id;
    double price;
};

int main() {
    widget w1 = {1000, 6.5};
    int values[3] = {1, 2, 3};
}

// C++ calls this aggregate-initialization

// We can also initialize unions with braces,
// though they must contain only a single element for the union's first member.
