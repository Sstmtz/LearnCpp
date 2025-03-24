// [[likely]] and [[unlikely]]
// hints for the compiler to optimze certain branches

// [[nodiscard(reason)]]
[[nodiscard("Ignore the return value will reset in memory leaks")]] void *GetData() {
    // ...
}

int main() {
    // for example.
    int value = 2;
    switch (value) {
        case 1:
            break;
        [[likely]] case 2:
            break;
        [[unlikely]] case 3:
            break;
    }
}
