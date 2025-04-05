
// Be Choosy

// Avoid function templates that accept anything
// Especially ones with common names

template <class T, class U>
void count_stipples_and_report_daces(T const &t, U const &u) {
    // ...
}

template <class T, class U>
bool operator==(T const &t, U const &u) {
    // ...
}

int main() {
    return 0;
}
