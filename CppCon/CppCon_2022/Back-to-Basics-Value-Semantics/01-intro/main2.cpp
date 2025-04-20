// A Value Semantics Solution

// This stype of programming has many advantages:
// - There is no inheritance hierarchy
// - The code is so much simpler (KISS)
// - There are no virtual functions
// - There are no pointers or indirections
// - There is no manual dynamic memory allocation
// - This is no need to manage lifetime
// - There is no lifetime-related issue (no need for smart pointers)
// - The performance is better

#include <variant>
#include <vector>

// Circle is not used via pointer, but as a value
class Circle { // no base class required! (non-intrusive)
public:
    explicit Circle(double rad)
        : radius {rad} //, ... Remaing data member
    {}

    double getRadius() const noexcept;
    // ... getCenter(), getRotation(), ...

    // No accumulation of dependencies
    // via member functions!

    // ...

private:
    double radius;
    // Remaing data member
};

class Square {
public:
    explicit Square(double s)
        : side {s} //, ... Remaing data member
    {}

    double getSide() const noexcept;
    // ... getCenter(), getRotation(), ...

    // ...

private:
    double side;
    // Remaing data member
};

// Draw is not used via pointer, but as a value
class Draw { // no base class required!
public:
    void operator()(Circle const &) const;
    void operator()(Square const &) const;
};

// A Shape is value, representing either a circle or a square
using Shape = std::variant<Circle, Square>;

void drawAllShapes(std::vector<Shape> const &shapes) {
    for (auto const &s : shapes) {
        std::visit(Draw {}, s);
    }
}

int main() {
    // (no pointers, no allocations, but values,...)
    using Shapes = std::vector<Shape>;

    // Creating some shapes
    Shapes shapes;
    shapes.emplace_back(Circle {2.0});
    shapes.emplace_back(Square {1.5});
    shapes.emplace_back(Circle {4.2});
    // (... and only values, making the code soooo much simpler)

    // Drawing all shapes
    drawAllShapes(shapes);
}
