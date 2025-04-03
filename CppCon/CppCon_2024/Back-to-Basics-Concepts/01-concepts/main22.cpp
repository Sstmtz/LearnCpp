
// C++20: Do Not Automatically Subsume

template <typename T>
concept GeoObject = requires(T obj) { obj.draw(); };

template <GeoObject T>
void print(T) {
    // ...
}

class CirCle {
public:
    void draw() const;
    // ...
};

// Cowboy does not automatically subsume GeoObject
// template <typename T>
// concept Cowboy = requires(T obj) {
//     obj.draw();
//     obj = obj;
// };

// Would subsume if GeoObject is explictly required by the concept:
template <typename T>
concept Cowboy = GeoObject<T> && requires(T obj) { obj = obj; };

template <Cowboy T>
void print(T) {
    // ...
}

// Or by the function:
// template <typename T>
//     requires Cowboy<T> && GeoObject<T>
// void print(T) {
//     // ...
// }

int main() {
    CirCle c;
    // print(c); // ERROR: ambiguous
    print(c); // OK
}
