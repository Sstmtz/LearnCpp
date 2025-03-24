#include <cstdio>
#include <iostream>
#include <typeinfo>

struct Pet {
    // since C++20, virtual functions can be marked as constexpr
    constexpr virtual void speak() = 0;
    virtual ~Pet() = default;
};

struct CatPet : Pet {
    void speak() override {
        puts("Meow!");
    }
};

struct DogPet : Pet {
    void speak() override {
        puts("Bark!");
    }
};

constexpr char const *getTypeName(Pet const &obj) {
    // since C++20, constexpr functions can use typeid
    return typeid(obj).name();
}

constexpr void foo() {
    // since C++20, constexpr functions can use dynamic_cast
    // and do dynamic memory allocations, global new/delete
    // but must be allocated and deallocated in the same constexpr function.
    // so std::string and std::vector are used on constexpr function.
    Pet *basePtr = new DogPet();
    if (DogPet *derivedPtr = dynamic_cast<DogPet *>(basePtr)) {
        derivedPtr->speak();
    } else {
        std::cout << "Conversion failed." << std::endl;
    }
    delete basePtr;
}

int main() {
    CatPet      c;
    char const *typeName = getTypeName(c);
    std::cout << "Type: " << typeName << '\n'; // Type: 6CatPet

    foo();                                     // Bark!
    return 0;
}
