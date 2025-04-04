
// [[nodiscard]] and Constructors

struct FDHolder {
    [[nodiscard]] FDHolder(int FD);
    FDHolder();
};

int main() {
    FDHolder {42};   // warning
    FDHolder h {42}; // constructed object not discarded, no warning
    FDHolder {};     // default constructed, no warning
}
