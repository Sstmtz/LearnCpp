// A Class Visitor Implementation

// This style of programming has many disadvantages:
// - We have a two inheritance hierarchies (intrusive)
// - Performance is reduced due to two virtual function calls per operation
// - Performance is affected due to many pointer (indirections)
// - Promotes dynamic memory allocation
// - Performance is reduced due to many small, manual, allocations
// - We need to manage lifetimes explicitly (std::unique_ptr)
// - Danger of lifetime-related bugs

#include <memory>
#include <vector>

class Circle;
class Square;

class ShapeVistor {
public:
    virtual ~ShapeVistor() = default;

    virtual void visit(Circle const &) const = 0;
    virtual void visit(Square const &) const = 0;
    // (The consequence: many virtual functions)
};

class Shape {
public:
    Shape() = default;
    virtual ~Shape() = default;

    virtual void accept(ShapeVistor const &) = 0;
};

class Circle : public Shape {
public:
    explicit Circle(double rad)
        : radius {rad} //, ... Remaing data member
    {}

    double getRadius() const noexcept;
    // ... getCenter(), getRotation(), ...

    void accept(ShapeVistor const &) override;

    // ...

private:
    double radius;
    // Remaing data member
};

class Square : public Shape {
public:
    explicit Square(double s)
        : side {s} //, ... Remaing data member
    {}

    double getSide() const noexcept;
    // ... getCenter(), getRotation(), ...

    void accept(ShapeVistor const &)
        override; // All derived classes need to implement the accept() function

    // ...

private:
    double side;
    // Remaing data member
};

class Draw : public ShapeVistor {
public:
    void visit(Circle const &) const override;
    void visit(Square const &) const override;
};

void drawAllShapes(std::vector<std::unique_ptr<Shape>> const &shapes) {
    for (auto const &s : shapes) {
        s->accept(Draw {});
    }
}

int main() {
    // (Another consequence: pointer)
    using Shapes = std::vector<std::unique_ptr<Shape>>;

    // Creating some shapes
    Shapes shapes;
    shapes.emplace_back(std::make_unique<Circle>(2.0));
    shapes.emplace_back(std::make_unique<Square>(1.5));
    shapes.emplace_back(std::make_unique<Circle>(4.2));
    // (And yet another consequence: manual allocations)

    // Drawing all shapes
    drawAllShapes(shapes);
}
