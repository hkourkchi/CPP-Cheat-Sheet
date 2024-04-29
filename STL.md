# STL Cheat Sheet
## Containers:

1. **Sequence Containers**:
   - `vector`: Resizable array, provides dynamic storage allocation.
     ```cpp
     #include <vector>
     std::vector<int> vec = {1, 2, 3, 4};
     vec.push_back(5);
     ```
   - `deque`: Double-ended queue, allows fast insertion/removal at both ends.
     ```cpp
     #include <deque>
     std::deque<int> deq = {1, 2, 3, 4};
     deq.push_front(0);
     deq.push_back(5);
     ```
   - `list`: Doubly linked list, efficient for insertion/removal anywhere but slower random access.
     ```cpp
     #include <list>
     std::list<int> lst = {1, 2, 3, 4};
     lst.push_back(5);
     lst.push_front(0);
     ```
   - `forward_list`: Singly linked list, similar to `list` but with less memory overhead.
     ```cpp
     #include <forward_list>
     std::forward_list<int> flst = {1, 2, 3, 4};
     flst.push_front(0);
     ```
   - `array`: Fixed-size array, provides compile-time size checking.
     ```cpp
     #include <array>
     std::array<int, 5> arr = {1, 2, 3, 4, 5};
     ```

2. **Associative Containers**:
   - `set`: Ordered set of unique keys, implemented as a balanced binary search tree.
     ```cpp
     #include <set>
     std::set<int> s = {3, 1, 4, 1, 5};
     ```
   - `multiset`: Allows duplicate keys while maintaining ordering.
     ```cpp
     #include <set>
     std::multiset<int> ms = {3, 1, 4, 1, 5};
     ```
   - `map`: Collection of key-value pairs sorted by keys, useful for associative arrays.
     ```cpp
     #include <map>
     std::map<char, int> m = {{'a', 1}, {'b', 2}, {'c', 3}};
     ```
   - `multimap`: Allows duplicate keys while maintaining sorting.
     ```cpp
     #include <map>
     std::multimap<char, int> mm = {{'a', 1}, {'b', 2}, {'a', 3}};
     ```

3. **Unordered Containers**:
   - `unordered_set`: Unordered set of unique keys, implemented as hash tables for faster lookup.
     ```cpp
     #include <unordered_set>
     std::unordered_set<int> us = {3, 1, 4, 1, 5};
     ```
   - `unordered_multiset`: Allows duplicate keys with faster lookup compared to `multiset`.
     ```cpp
     #include <unordered_set>
     std::unordered_multiset<int> ums = {3, 1, 4, 1, 5};
     ```
   - `unordered_map`: Unordered key-value pairs with fast average constant-time lookup.
     ```cpp
     #include <unordered_map>
     std::unordered_map<char, int> um = {{'a', 1}, {'b', 2}, {'c', 3}};
     ```
   - `unordered_multimap`: Allows duplicate keys with fast lookup.
     ```cpp
     #include <unordered_map>
     std::unordered_multimap<char, int> umm = {{'a', 1}, {'b', 2}, {'a', 3}};
     ```

## Iterators:
- **Input Iterators**: Read-only access to a sequence of elements.
- **Output Iterators**: Write-only access to a sequence of elements.
- **Forward Iterators**: Read/write access, can move forward in a sequence.
- **Bidirectional Iterators**: Read/write access, can move forward and backward in a sequence.
- **Random Access Iterators**: Supports arithmetic operations for random access.

```cpp
#include <vector>
#include <iostream>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    // Using iterators
    for(auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    return 0;
}
```

## Algorithms:

- **Non-modifying Sequence Operations**: Operations that do not modify the sequence, such as searching, counting, etc.
- **Modifying Sequence Operations**: Operations that modify the sequence, such as sorting, shuffling, etc.
- **Sorting and Related Operations**: Functions for sorting elements in a sequence.
- **Binary Search**: Functions for binary search operations.
- **Heap Operations**: Functions for creating and manipulating heap data structures.
- **Set Operations**: Operations for set manipulation like union, intersection, etc.
- **Numeric Operations**: Operations for numerical computations like accumulation, inner product, etc.

```cpp
#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> vec = {3, 1, 4, 1, 5};
    // Sorting
    std::sort(vec.begin(), vec.end());
    // Output
    for(auto num : vec) {
        std::cout << num << " ";
    }
    return 0;
}
```

## Utility Components:

- **Iterators**: Functions for working with iterators, like `begin()`, `end()`, etc.
- **Comparators**: Function objects used for custom comparison in algorithms.
- **Function Objects**: Objects that behave like functions, often used in algorithms.
- **Pair**: Container for storing a pair of values, used in associative containers, algorithms, etc.
- **Tuple**: Container for storing heterogeneous elements, providing access by index.
- **Smart Pointers**: Classes for automatic memory management, preventing memory leaks and managing resources efficiently.
- **Allocators**: Mechanism for controlling memory allocation and deallocation in containers.

```cpp
#include <iostream>
#include <utility>
#include <tuple>

int main() {
    // Pair example
    std::pair<int, std::string> p = std::make_pair(42, "hello");
    std::cout << p.first << " " << p.second << std::endl;
    
    // Tuple example
    std::tuple<int, float, std::string> t(1, 2.2, "world");
    std::cout << std::get<0>(t) << " " << std::get<1>(t) << " " << std::get<2>(t) << std::endl;

    return 0;
}
```

## Memory Management:

- **Smart Pointers**: `std::unique_ptr` for exclusive ownership, `std::shared_ptr` for shared ownership, and `std::weak_ptr` for non-owning references.
- **Allocators**: Customizable memory management for containers, allowing custom memory allocation strategies.

```cpp
#include <memory>
#include <iostream>

int main() {
    // Smart pointers
    std::unique_ptr<int> uptr(new int(42));
    std::cout << *uptr << std::endl;

    return 0;
}
```

## Miscellaneous:

- **Strings**: `std::string` for handling strings efficiently, supporting various operations like concatenation, substring, etc.
- **I/O Streams**: Input/output operations for reading from and writing to streams like standard input/output, files, etc.
- **Exceptions**: Mechanism for handling errors and exceptional conditions in a program.
- **Type Traits**: Templates for compile-time type introspection, enabling conditional compilation based on type properties.

```cpp
#include <iostream>
#include <string>

int main() {
    // String example
    std::string str = "Hello, World!";
    std::cout << str << std::endl;

    return 0;
}

