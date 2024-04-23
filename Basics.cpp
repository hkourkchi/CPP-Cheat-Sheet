// C++ Cheat Sheet

// 1. Hello World
#include <iostream>
using namespace std;
int main() {
    cout << "Hello, World!" << endl;
    return 0;
}

// 2. Variables and Data Types
int myInt = 10;  // Integer variable (4 bytes on most systems)
float myFloat = 3.14;  // Floating point variable (4 bytes)
double myDouble = 3.14159265359;  // Double precision floating point variable (8 bytes)
char myChar = 'A';  // Character variable (1 byte)
string myString = "Hello";  // String variable

// 3. Input/Output
cin >> myInt; // Input
cout << "The value of myInt is: " << myInt << endl; // Output

// 4. Basic Arithmetic Operations
int result = 10 + 5; // Addition
result = 10 - 5; // Subtraction
result = 10 * 5; // Multiplication
result = 10 / 5; // Division

// 5. Conditional Statements
if (myInt > 10) {
    cout << "myInt is greater than 10" << endl;
} else if (myInt == 10) {
    cout << "myInt is equal to 10" << endl;
} else {
    cout << "myInt is less than 10" << endl;
}

// 6. Loops
for (int i = 0; i < 5; i++) {
    cout << i << endl;
}

while (myInt < 20) {
    cout << "myInt is less than 20" << endl;
    myInt++;
}

// 7. Functions
int add(int a, int b) {
    return a + b;
}

// 8. Arrays
int myArray[5] = {1, 2, 3, 4, 5};

// 9. Pointers and References
int* ptr = &myInt; // Pointer: Holds the memory address of myInt
int& ref = myInt; // Reference: Provides an alias to myInt

// 10. Smart Pointers
#include <memory>
shared_ptr<int> sptr(new int); // Shared Pointer: Manages dynamic memory allocation
unique_ptr<int> uptr(new int); // Unique Pointer: Exclusive ownership, cannot be copied
weak_ptr<int> wptr; // Weak Pointer: Non-owning observer to a shared pointer

*sptr = 10;
*uptr = 20;

cout << "Value of shared pointer: " << *sptr << endl;
cout << "Value of unique pointer: " << *uptr << endl;

// Example of using weak pointer for resolving circular referencing
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

// 11. Lambda Functions
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

// Explanation:
// Lambda Functions: Lambda functions are anonymous functions that can be defined inline. They are often used for short, one-off operations where defining a separate function would be overkill. In the example, a lambda function is used with std::count_if to count elements greater than a threshold in a vector.

// 12. Casting
int num1 = 10;
double num2 = static_cast<double>(num1); // Casting from int to double

// Explanation:
// Casting: Casting is the process of converting one data type into another. It allows you to change the 
// interpretation of a value from one type to another, potentially altering its representation or behavior.

// Difference between C-style Casting and Modern Casting:
// - C-style Casting:
//   - Syntax: Uses parentheses with a type name inside, e.g., (int) myFloat.
//   - Safety: Not type-safe and can lead to unintended conversions.
//   - Visibility: Harder to spot in the code due to its implicit nature.
//   - Usage: Commonly used in C programming but discouraged in C++ due to its lack of safety.
// - Modern Casting (static_cast, dynamic_cast, const_cast, reinterpret_cast):
//   - Syntax: Uses specific casting operators with clear names, e.g., static_cast<int>(myFloat).
//   - Safety: Type-safe and provides compile-time checks for safer conversions.
//   - Visibility: Clearly indicates the intent of the conversion, making it easier to understand and maintain.
//   - Usage: Encouraged in C++ for its safety and clarity. Provides different casting operators for specific conversion needs.

// Different Types of Casting:
// - static_cast: Used for general type casting that can be checked at compile-time. It's safer than 
//   C-style casts and performs additional checks.
// - dynamic_cast: Used for converting polymorphic types. It's primarily used in conjunction with 
//   inheritance and runtime type information (RTTI).
// - const_cast: Used for removing the const or volatile qualifiers from a variable. It's typically 
//   used to cast away the constness of an object.
// - reinterpret_cast: Used for low-level type casting between unrelated types. It's the most 
//   dangerous casting operator and should be used with caution.

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

// Classes and Objects
class MyClass {
public:
    int myNum;
    string myString;
};

// File Handling
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

// 13. Pass by Reference, Pass by Value, Pass by Reference and Const, Constant Pointer, Constant Reference, Constant Functions

// Explanation:
// - Pass by Value: The function receives a copy of the argument passed to it. Changes made to the parameter inside the function do not affect the original argument.
// - Pass by Reference: The function receives a reference to the original argument. Changes made to the parameter inside the function affect the original argument.
// - Pass by Reference and Const: Similar to pass by reference, but the function promises not to modify the original argument. It's used to prevent unintended modifications.
// - Constant Pointer: A pointer whose value (memory address) cannot be changed once initialized.
// - Constant Reference: A reference to a constant value. It cannot be used to modify the original value.
// - Constant Functions: Member functions that do not modify the state of the object. They are declared with the const keyword at the end of the function declaration.
// - Constant Member Function: A member function declared as const, indicating that it does not modify the state of the object.

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

// 14. Literals
#include <iostream>
using namespace std;

int main() {
    // Integer Literal
    int num1 = 10; // 4 bytes

    // Floating-point Literal
    double num2 = 3.14; // 8 bytes

    // Character Literal
    char ch = 'A'; // 1 byte

    // String Literal
    string str = "Hello"; // Depends on string length

    // Boolean Literal
    bool flag = true; // Typically 1 byte

    // Hexadecimal Literal
    int hex = 0x1A; // 4 bytes

    // Binary Literal (C++14)
    int binary = 0b1010; // 4 bytes

    cout << "Integer Literal: " << num1 << endl;
    cout << "Floating-point Literal: " << num2 << endl;
    cout << "Character Literal: " << ch << endl;
    cout << "String Literal: " << str << endl;
    cout << "Boolean Literal: " << flag << endl;
    cout << "Hexadecimal Literal: " << hex << endl;
    cout << "Binary Literal: " << binary << endl;

    return 0;
}

// Explanation:
// - Integer Literal: Represents whole numbers without any fractional part.
// - Floating-point Literal: Represents real numbers with a decimal point.
// - Character Literal: Represents a single character enclosed in single quotes.
// - String Literal: Represents a sequence of characters enclosed in double quotes.
// - Boolean Literal: Represents true or false values.
// - Hexadecimal Literal: Represents numbers in base 16, prefixed with '0x'.
// - Binary Literal (C++14): Represents numbers in base 2, prefixed with '0b'.
// - The number of bytes required for each data type may vary depending on the system architecture.

