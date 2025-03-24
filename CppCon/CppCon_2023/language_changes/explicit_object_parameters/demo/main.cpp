// Instead of implicit `this`, explicitly specify the object parameter

class Cell {
public:
    // before C++23:
    // void setValue(double value) {
    //     m_value = value;
    // }

    // since C++23:
    void setValue(this Cell &self, double value) {
        self.m_value = value;
    }

private:
    double m_value;
};

int main() {
    Cell cell;
    cell.setValue(1.2);
    return 0;
}
