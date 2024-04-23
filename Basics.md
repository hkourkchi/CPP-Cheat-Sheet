# Basics of C++ Cheat Sheet

## Hello World
```cpp
#include <iostream>
using namespace std;
int main() {
    cout << "Hello, World!" << endl;
    return 0;
}
```
## Variables and Data Types
```cpp
int myInt = 10;  // Integer variable (4 bytes on most systems)
float myFloat = 3.14;  // Floating point variable (4 bytes)
double myDouble = 3.14159265359;  // Double precision floating point variable (8 bytes)
char myChar = 'A';  // Character variable (1 byte)
string myString = "Hello";  // String variable
```

## Input/Output
```cpp
cin >> myInt; // Input
cout << "The value of myInt is: " << myInt << endl; // Output
```

## Basic Arithmetic Operations
```cpp
int result = 10 + 5; // Addition
result = 10 - 5; // Subtraction
result = 10 * 5; // Multiplication
result = 10 / 5; // Division
```
## Conditional Statements
```cpp
if (myInt > 10) {
    cout << "myInt is greater than 10" << endl;
} else if (myInt == 10) {
    cout << "myInt is equal to 10" << endl;
} else {
    cout << "myInt is less than 10" << endl;
}
```

## Loops
```cpp
for (int i = 0; i < 5; i++) {
    cout << i << endl;
}

while (myInt < 20) {
    cout << "myInt is less than 20" << endl;
    myInt++;
}
```
## Functions
```cpp
int add(int a, int b) {
    return a + b;
}
```
## Arrays
```cpp
int myArray[5] = {1, 2, 3, 4, 5};
```
## Pointers and References
```cpp
int* ptr = &myInt; // Pointer: Holds the memory address of myInt
int& ref = myInt; // Reference: Provides an alias to myInt
```
## Smart Pointers
```cpp
#include <memory>
shared_ptr<int> sptr(new int); // Shared Pointer: Manages dynamic memory allocation
unique_ptr<int> uptr(new int); // Unique Pointer: Exclusive ownership, cannot be copied
weak_ptr<int> wptr; // Weak Pointer: Non-owning observer to a shared pointer

*sptr = 10;
*uptr = 20;

cout << "Value of shared pointer: " << *sptr << endl;
cout << "Value of unique pointer: " << *uptr << endl;
```

Example of using weak pointer for resolving circular referencing
```cpp
class B; // Forward declaration

class A {
public:
    weak_ptr<B> b_ptr; // Weak pointer to B
    A() { cout << "A Constructor" << endl; }
    ~A() { cout << "A Destructor" << endl; }
};

class B {
public:
    shared_ptr<A> a_ptr; // Shared pointer to A
    B() { cout << "B Constructor" << endl; }
    ~B() { cout << "B Destructor" << endl; }
};

int main() {
    shared_ptr<A> a(new A);
    shared_ptr<B> b(new B);

    // Establishing the association between A and B
    a->b_ptr = b;
    b->a_ptr = a;

    // Deleting one of the objects
    a.reset();

    // Accessing the weak pointer
    if (b->a_ptr.expired()) {
        cout << "Weak pointer expired" << endl;
    } else {
        cout << "Weak pointer still valid" << endl;
    }

    return 0;
}
```

## Lambda Functions
Lambda Functions: Lambda functions are anonymous functions that can be defined inline. They are often used for short, one-off operations where defining a separate function would be overkill. In the example, a lambda function is used with std::count_if to count elements greater than a threshold in a vector.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // Example of a lambda function
    vector<int> nums = {1, 2, 3, 4, 5};
    int threshold = 3;

    // Using lambda function with std::count_if to count elements greater than the threshold
    int count = count_if(nums.begin(), nums.end(), [threshold](int x) { return x > threshold; });

    cout << "Count of elements greater than " << threshold << ": " << count << endl;

    return 0;
}
```
## Casting
Casting is the process of converting one data type into another. It allows you to change the 
interpretation of a value from one type to another, potentially altering its representation or behavior.

```cpp
int num1 = 10;
double num2 = static_cast<double>(num1); // Casting from int to double
```

Difference between C-style Casting and Modern Casting:
- C-style Casting:
  - Syntax: Uses parentheses with a type name inside, e.g., (int) myFloat.
  - Safety: Not type-safe and can lead to unintended conversions.
  - Visibility: Harder to spot in the code due to its implicit nature.
  - Usage: Commonly used in C programming but discouraged in C++ due to its lack of safety.
- Modern Casting (static_cast, dynamic_cast, const_cast, reinterpret_cast):
  - Syntax: Uses specific casting operators with clear names, e.g., static_cast<int>(myFloat).
  - Safety: Type-safe and provides compile-time checks for safer conversions.
  - Visibility: Clearly indicates the intent of the conversion, making it easier to understand and maintain.
  - Usage: Encouraged in C++ for its safety and clarity. Provides different casting operators for specific conversion needs.

Different Types of Casting:
- static_cast: Used for general type casting that can be checked at compile-time. It's safer than C-style casts and performs additional checks.
- dynamic_cast: Used for converting polymorphic types. It's primarily used in conjunction with inheritance and runtime type information (RTTI).
- const_cast: Used for removing the const or volatile qualifiers from a variable. It's typiclly used to cast away the constness of an object.
- reinterpret_cast: Used for low-level type casting between unrelated types. It's the most dangerous casting operator and should be used with caution.

```cpp
int intValue = 10;
const int* ptr = &intValue; // Pointer to a constant integer
int* nonConstPtr = const_cast<int*>(ptr); // Casting away constness

// Example of dynamic_cast
class Base {
public:
    virtual void foo() {}
};

class Derived : public Base {
public:
    void bar() {}
};

Base* basePtr = new Derived;
Derived* derivedPtr = dynamic_cast<Derived*>(basePtr); // Safe downcasting
if (derivedPtr != nullptr) {
    derivedPtr->bar(); // Access Derived class member
}

// Example of reinterpret_cast
int* p = new int(65);
char* c = reinterpret_cast<char*>(p); // Cast int pointer to char pointer
cout << *p << " interpreted as character: " << *c << endl;

// Example of const_cast
const int num = 10;
int& ref = const_cast<int&>(num); // Cast away constness
ref = 20; // Modifying a const variable through reference
```

## Classes and Objects
```cpp
class MyClass {
public:
    int myNum;
    string myString;
};
```

## File Handling
```cpp
#include <fstream>
ofstream outputFile;
outputFile.open("example.txt");
outputFile << "Writing to a file.";
outputFile.close();

ifstream inputFile;
inputFile.open("example.txt");
string line;
while (getline(inputFile, line)) {
    cout << line << endl;
}
inputFile.close();
```

## Pass by Reference, Pass by Value, Pass by Reference and Const, Constant Pointer, Constant Reference, Constant Functions
- Pass by Value: The function receives a copy of the argument passed to it. Changes made to the parameter inside the function do not affect the original argument.
- Pass by Reference: The function receives a reference to the original argument. Changes made to the parameter inside the function affect the original argument.
- Pass by Reference and Const: Similar to pass by reference, but the function promises not to modify the original argument. It's used to prevent unintended modifications.
- Constant Pointer: A pointer whose value (memory address) cannot be changed once initialized.
- Constant Reference: A reference to a constant value. It cannot be used to modify the original value.
- Constant Functions: Member functions that do not modify the state of the object. They are declared with the const keyword at the end of the function declaration.
- Constant Member Function: A member function declared as const, indicating that it does not modify the state of the object.

```cpp
void passByValue(int x) {
    x = 20; // Changes to x do not affect the original argument
}

void passByReference(int& x) {
    x = 20; // Changes to x affect the original argument
}

void passByReferenceConst(const int& x) {
    // x = 20; // Error: Cannot modify a const reference parameter
}

void constantPointer(const int* ptr) {
    // *ptr = 20; // Error: Cannot modify the value pointed to by a constant pointer
}

void constantReference(const int& ref) {
    // ref = 20; // Error: Cannot modify a const reference parameter
}

class Example {
public:
    void constMemberFunction() const {
        // myNum = 20; // Error: Cannot modify member variables in a const member function
    }

    int myNum;
};
```

## Return by Reference, Return by Value, Return by Pointer
- **Return by Reference:** Efficient, allows modification of original, no copy made.
- **Return by Value:** Creates a copy, original remains unchanged.
- **Return by Pointer:** Returns a pointer to the original, allows modification, requires memory management.

### Return by Reference

- **Syntax:** `Type& functionName() { }`
- **Behavior:**
  - Returns a reference to a variable or object.
  - Allows modification of the original value.
  - No copy of the variable or object is made.
- **Use Cases:**
  - Efficient for large objects to avoid unnecessary copying.
  - Useful when the caller needs to modify the original object.
- **Example:**
  ```cpp
  int& getMax(int& a, int& b) {
      return (a > b) ? a : b;
  }
  ```

## Return by Value

- **Syntax:** `Type functionName() { }`
- **Behavior:**
  - Returns a copy of the variable or object.
  - Modifications to the returned value do not affect the original.
  - Overhead involved in creating a copy.
- **Use Cases:**
  - Suitable for small objects or primitive types.
  - When the original value should not be modified.
- **Example:**
  ```cpp
  int square(int x) {
      return x * x;
  }
  ```

### Return by Pointer

- **Syntax:** `Type* functionName() { }`
- **Behavior:**
  - Returns a pointer to a variable or object.
  - Allows modification of the original value through the pointer.
  - Requires memory allocation and deallocation.
- **Use Cases:**
  - Useful when returning dynamically allocated memory.
  - When the caller needs to modify the original object.
- **Example:**
  ```cpp
  int* createArray(int size) {
      return new int[size];
  }
  ```
## Rule of 5
If you need to define one of the following special member functions for a class, you likely need to define all five:

- **Destructor**: Responsible for releasing resources allocated by the object.
- **Copy Constructor**: Creates a new object by copying the contents of an existing object.
- **Copy Assignment Operator**: Assigns the contents of one object to another existing object.
- **Move Constructor**: Creates a new object by moving the contents of an existing object, typically more efficient than copying.
- **Move Assignment Operator**: Assigns the contents of one object to another existing object by moving, typically more efficient than copying.

```cpp
  #include <iostream>
#include <algorithm> // For std::move

class DynamicArray {
private:
    int* data;
    size_t size;

public:
    // Default constructor
    DynamicArray() : data(nullptr), size(0) {}

    // Destructor
    ~DynamicArray() {
        delete[] data;
    }

    // Copy constructor
    DynamicArray(const DynamicArray& other) : data(nullptr), size(other.size) {
        data = new int[size];
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    // Copy assignment operator
    DynamicArray& operator=(const DynamicArray& other) {
        if (this != &other) {
            // Release old memory
            delete[] data;
            // Allocate new memory
            size = other.size;
            data = new int[size];
            // Copy data
            for (size_t i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    // Move constructor
    DynamicArray(DynamicArray&& other) noexcept : data(other.data), size(other.size) {
        // Nullify other's data pointer to prevent double deletion
        other.data = nullptr;
        other.size = 0;
    }

    // Move assignment operator
    DynamicArray& operator=(DynamicArray&& other) noexcept {
        if (this != &other) {
            // Release old memory
            delete[] data;
            // Transfer ownership
            data = other.data;
            size = other.size;
            // Nullify other's data pointer to prevent double deletion
            other.data = nullptr;
            other.size = 0;
        }
        return *this;
    }

    // Function to set data
    void setData(int* newData, size_t newSize) {
        delete[] data; // Release old memory
        data = new int[newSize];
        for (size_t i = 0; i < newSize; ++i) {
            data[i] = newData[i];
        }
        size = newSize;
    }

    // Function to print data
    void printData() const {
        for (size_t i = 0; i < size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    DynamicArray arr1;
    arr1.setData(new int[3]{1, 2, 3}, 3);

    DynamicArray arr2 = arr1; // Copy constructor
    arr2.printData();

    DynamicArray arr3;
    arr3 = arr1; // Copy assignment operator
    arr3.printData();

    DynamicArray arr4 = std::move(arr1); // Move constructor
    arr4.printData();

    DynamicArray arr5;
    arr5 = std::move(arr2); // Move assignment operator
    arr5.printData();

    return 0;
}
```

## Literals
Literals are representations of fixed values in code
### Prefix literals:
- Integer Literals: Represent whole numbers without any fractional part. Examples: 10, -20, 0x1A (hexadecimal), 057 (octal).
- Floating-Point Literals: Represent real numbers with a decimal point. Examples: 3.14, -0.001, 1.0e6 (scientific notation).
- Character Literals: Represent a single character enclosed in single quotes. Examples: 'A', '1', '%'.
- String Literals: Represent a sequence of characters enclosed in double quotes. Example: "Hello, World!".
- Boolean Literals: Represent the boolean values true and false.
- Pointer Literals: Represent the null pointer value, usually written as nullptr in modern C++.
- User-defined Literals: Allows users to define their own literal suffixes for types.
- Hexadecimal Literals: Represent numbers in base 16, prefixed with 0x. Example: 0x1A.
- Octal Literals: Represent numbers in base 8, prefixed with 0. Example: 057.
- Binary Literals (C++14 and later): Represent numbers in base 2, prefixed with 0b. Example: 0b1010.
- Integer Separator (C++14 and later): Allows inserting single quotes (') between digits to improve readability of large integer literals. Example: 1'000'000.
- Character Escape Sequences: Represent special characters using escape sequences, prefixed with a backslash (\). Examples: \n (newline), \t (tab), \\ (backslash), \' (single quote), \" (double quote).
### Suffixes literals: 
These suffixes provide additional type information for literals, allowing developers to specify the desired type explicitly. For example, appending f to a floating-point literal (3.14f) indicates that it should be treated as a float rather than the default double.
- u / U: Suffix used for unsigned integer literals. Example: 10u, 12345U.
- l / L: Suffix used for long integer literals. Example: 10000000000L, 1234567890l.
- ll / LL: Suffix used for long long integer literals. Example: 1000000000000LL, 9876543210ll.
- f / F: Suffix used for float literals. Example: 3.14f, 0.001F.
- d / D: Suffix used for double literals (although not commonly used, as double is the default type for floating-point literals). Example: 3.14d, 0.001D.
- s / S: Suffix used for std::string literals (user-defined literals). Example: "Hello"s, "World!"s./
  

