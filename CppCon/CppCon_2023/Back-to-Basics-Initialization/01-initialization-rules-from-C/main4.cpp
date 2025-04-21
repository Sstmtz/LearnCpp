// If the brace-enclosed list doesn't contain an initializer for every element of the
// aggregate, the remaining fields are zero-initialized:

struct widget {
    int id;
    double price;
};

int main() {
    widget v1 = {1000};  // equivalent to {1000, 0}
    int values[3] = {1}; // equivalent to {1, 0, 0}
}

// That covers C's initialization rules
