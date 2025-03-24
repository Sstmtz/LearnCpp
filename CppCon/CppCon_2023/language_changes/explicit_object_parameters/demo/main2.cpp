// Allow you to write ref-qualified members differently

// support you have:
void f() &;
void g() const &;
void h() &&;
// those can be rewritten as:
void f(this Data &);
void g(this Data const &);
void h(this Data &&);

int main() {
    return 0;
}
