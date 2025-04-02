#include <cassert>
#include <complex>
#include <iostream>
#include <string>
#include <vector>

// C++98: Class Templates
//
// Class code for arbitray types

template <typename T>
class Stack {
private:
    std::vector<T> elems; // elements

public:
    Stack();              // constructor
    void push(T const &); // push element
    T    pop();           // pop element
    T    top() const;     // yield top elem

    bool empty() const {  // no element?
        return elems.empty();
    }
};

int main() {
    // stack of ints:
    Stack<int> intStack;
    intStack.push(7);
    std::cout << intStack.top() << '\n';

    // stack of strings:
    Stack<std::string> strStack;
    strStack.push("hello");
    std::cout << strStack.top() << '\n';
    strStack.pop();

    // stack of complex numbers:
    Stack<std::complex<double>> cpxStack;
}

// Implementation of Class Templates:
template <typename T>
Stack<T>::Stack() {
    // constructor: nothing to do
}

template <typename T>
void Stack<T>::push(T const &elem) {
    elems.push_back(elem); // insert at the end
}

template <typename T>
T Stack<T>::pop() {
    assert(! elems.empty());
    T elem = elems.back(); // copy last element
    elems.pop_back();      // remove last element
    return elem;           // return saved copy
}

template <typename T>
T Stack<T>::top() const {
    assert(! elems.empty());
    return elems.back(); // return last element
}
