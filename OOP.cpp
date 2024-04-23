// Object-Oriented Programming (OOP) in C++

// Classes and Objects

// Class Declaration
// A class is a blueprint for creating objects. It defines the properties (data members) and behaviors (member functions) of objects.
class MyClass {
public:
    // Member variables (attributes)
    int myVar;
    
    // Member functions (methods)
    void myMethod();
};

// Object Creation
// An object is an instance of a class. It represents a specific entity with its own unique set of properties and behaviors.
MyClass obj;

// Accessing Members
// You can access the members (variables and functions) of an object using the dot operator `.`.
obj.myVar = 10;
obj.myMethod();

// Encapsulation

// Access Modifiers
// Access modifiers control the visibility of class members. 
// - public: Members are accessible from outside the class.
// - private: Members are accessible only from within the class.
class MyClass {
public:
    int publicVar;
private:
    int privateVar;
};

// Inheritance

// Base Class Declaration
// Inheritance allows a class to inherit properties and behaviors from another class.
class Animal {
public:
    void eat() {
        std::cout << "Eating..." << std::endl;
    }

    // Virtual destructor
    virtual ~Animal() {
        std::cout << "Animal destructor called" << std::endl;
    }
};

// Derived Class Declaration
// A derived class inherits from a base class using the `public` keyword.
class Mammal : public Animal {
public:
    void breathe() {
        std::cout << "Breathing..." << std::endl;
    }
};

class Bird : public Animal {
public:
    void fly() {
        std::cout << "Flying..." << std::endl;
    }
};

// Derived Class with Multiple Inheritance
// Multiple inheritance can lead to the diamond problem.
class Bat : public Mammal, public Bird {
public:
    void navigate() {
        // Ambiguity arises here when trying to call methods inherited from both Animal and its subclasses Mammal, Bird.
        // eat(); // Which eat() method to call? From Mammal or Bird?
        // breathe(); // Which breathe() method to call? From Mammal or Bird?
        // fly(); // Which fly() method to call? From Mammal or Bird?
        std::cout << "Navigating..." << std::endl;
    }
};

// Polymorphism

// Virtual Functions
// Polymorphism allows a function to have different forms based on the object it is called on. 
// A virtual function is a member function declared within a base class and overridden in derived classes.
class Animal {
public:
    virtual void makeSound() {
        std::cout << "Animal makes a sound" << std::endl;
    }

    // Virtual destructor
    virtual ~Animal() {
        std::cout << "Animal destructor called" << std::endl;
    }
};

class Dog : public Animal {
public:
    void makeSound() override {
        std::cout << "Dog barks" << std::endl;
    }

    // Destructor
    ~Dog() {
        std::cout << "Dog destructor called" << std::endl;
    }
};

// Object Creation
// You can create an object of the derived class and use it to call the virtual function.
Dog myDog;
Animal* myAnimal = &myDog;
myAnimal->makeSound(); // Outputs: Dog barks

// Overloading
// Overloading allows you to define multiple functions with the same name but different parameter lists.
class Math {
public:
    int add(int a, int b) {
        return a + b;
    }
    
    float add(float a, float b) {
        return a + b;
    }
};

// Abstraction

// Abstract Class
// Abstraction allows you to define the structure of a class without providing implementation details. 
// An abstract class contains one or more pure virtual functions.
class Shape {
public:
    virtual void draw() = 0; // Pure virtual function
};

// Concrete Class
// A concrete class provides implementations for all the pure virtual functions of the abstract class.
class Circle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a circle" << std::endl;
    }
};

// Object Creation
// You can create objects of concrete classes and call their member functions.
Circle myCircle;
myCircle.draw(); // Outputs: Drawing a circle

// Composition

// Class Composition
// Composition allows you to create complex objects by combining simpler objects. 
// A class can contain objects of other classes as member variables.
class Engine {
public:
    void start() {
        std::cout << "Engine started" << std::endl;
    }
};

class Car {
private:
    Engine engine;
public:
    void start() {
        engine.start();
        std::cout << "Car started" << std::endl;
    }
};

// Object Creation
// You can create an object of the composite class and access its member functions.
Car myCar;
myCar.start(); // Outputs: Engine started, Car started

// Runtime Inheritance
// Runtime inheritance refers to the dynamic binding of member functions during program execution.
// It allows for polymorphic behavior, where the correct member function is determined at runtime based on the actual object type.
// This is achieved through the use of virtual functions and pointers or references to base class objects.
Dog myDog;
Animal* myAnimal = &myDog;
myAnimal->makeSound(); // Outputs: Dog barks (determined at runtime)

// Compile-Time Inheritance
// Compile-time inheritance refers to the static binding of member functions during compilation.
// It involves the compiler resolving the function calls based on the static type of the object.
// Overloaded functions, non-virtual member functions, and template functions exhibit compile-time inheritance.
Math mathObj;
int result = mathObj.add(3, 4); // Calls int add(int a, int b) at compile time
float result2 = mathObj.add(3.5f, 4.5f); // Calls float add(float a, float b) at compile time

// Diamond Problem and Solution
// The diamond problem arises in multiple inheritance when a class inherits from two classes that have a common ancestor.
// This results in ambiguity in accessing members of the common ancestor.
// For example:
// class Animal { public: void eat() { std::cout << "Eating..." << std::endl; } };
// class Mammal : public Animal {};
// class Bird : public Animal {};
// class Bat : public Mammal, public Bird {}; // Multiple inheritance
// Solution: To resolve the diamond problem, virtual inheritance is used. 
// This ensures that only a single instance of the common ancestor is shared among the derived classes.
// To use virtual inheritance, you declare the base class as virtual in the derived classes that inherit from it.
