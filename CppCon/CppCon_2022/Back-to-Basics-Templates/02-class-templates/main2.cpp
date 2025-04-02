#include <cassert>
#include <iostream>
#include <utility>
#include <vector>

// C++98: Generic Member Functions are Only Instantiated if Used
//
// Class Template arguments
// - have to support all operations of member templates that are used
//   - don't have to support all operations that could be used

template <typename T>
class Stack {
private:
    std::vector<T> elems; // elements

public:
    Stack();
    void push(T const &);
    T    pop();
    T    top() const;

    bool empty() const {
        return elems.empty();
    }

    void print() const {
        for (T const &elem : elems) {
            std::cout << elem << ' '; // requires << for element type T
        }
    }
};

int main() {
    Stack<int> si;                           // OK
    si.push(42);                             // OK
    int i = si.top();                        // OK
    si.print();                              // OK

    Stack<std::pair<int, double>> sp;        // OK
    sp.push(std::pair<int, double>(1, 3.0)); // OK
    sp.push({6, 7});                         // OK since C++11
    std::cout << sp.top().first << '\n';     // OK
    // sp.print();                              // compile-time ERROR: << not defined for std::pair<>
}

template <typename T>
Stack<T>::Stack() {
    // constructor: nothing to do
}

template <typename T>
void Stack<T>::push(T const &elem) {
    elems.push_back(elem);
}

template <typename T>
T Stack<T>::pop() {
    assert(! elems.empty());
    T elem = elems.back();
    elems.pop_back();
    return elem;
}

template <typename T>
T Stack<T>::top() const {
    assert(! elems.empty());
    return elems.back();
}
