
// Allow for recursive lambda expressions
// `this` in a lambda accesses the object that contains the lambda,
// not the lambda instance itself!

auto fibonacci = [](this auto self, int n) {
    if (n < 2) {
        return n;
    }
    return self(n - 1) + self(n - 2);
};

int main() {
    return 0;
}
