
// [[nodiscard]] and Types

struct [[nodiscard]] ErrorType {};

ErrorType get_value();

int main() {
    get_value(); // warning issued from any reasonable compiler
}
