
// noexcept
//
// `noexcept` notifies the user (and compiler) that a function may not
// throw an exception. If an exception is thrown from that function,
// `terminate` MUST be called

void myfunc() noexcept {
    // required to terminate the program
    throw 42;
}

int main() {
    try {
        myfunc();
    } catch (...) {
        // catch is irrelevant, `terminate` is called
    }
}
