# Explanation of Virtual Method Table (VTable)

The Virtual Method Table (VTable) is a mechanism used in object-oriented programming languages like C++ to support dynamic dispatch or runtime polymorphism.

## How VTable Works

1. **Virtual Functions**: In C++, a virtual function is a member function declared within a base class and redefined (or overridden) by a derived class.

2. **VTable Construction**: When a class contains one or more virtual functions, the compiler typically generates a VTable for that class. The VTable is constructed at compile time and typically stored as a static array of function pointers. Each entry in the VTable corresponds to a virtual function of the class.

3. **Per-Object VTable**: Each object of a class with virtual functions contains a hidden pointer (often called a vptr or VPTR) that points to the VTable of its most-derived class.

4. **Dynamic Dispatch**: When a virtual function is called on an object through a base class pointer or reference, the compiler uses the vptr to determine which VTable to use. It then looks up the appropriate function pointer in the VTable and calls the corresponding function.

5. **Overriding Functions**: If a derived class overrides a virtual function of its base class, the corresponding entry in the VTable for the derived class is updated to point to the overridden function.

6. **Performance Implications**: While dynamic dispatch provides flexibility and extensibility, it comes with a slight performance overhead compared to static dispatch.

```cpp
// Example of a class with virtual functions and runtime polymorphism

#include <iostream>
using namespace std;

// Base class
class Animal {
public:
    virtual void sound() {
        cout << "Animal makes a sound" << endl;
    }
};

// Derived class
class Dog : public Animal {
public:
    void sound() override {
        cout << "Dog barks" << endl;
    }
};

int main() {
    // Pointer to base class object
    Animal* ptr = new Dog;




    // Runtime polymorphism
    ptr->sound(); // Calls Dog's version of the sound method

    delete ptr;
    return 0;
}
```
```py
import numpy as np
