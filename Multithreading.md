# C++ Multithreading Cheat Sheet

## Include Necessary Headers:
```cpp
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
```

## Creating Threads:
When you create a thread in C++, several things happen:

- *Thread Creation*: The std::thread constructor is called, which creates a new thread of execution. The constructor takes a callable object (such as a function pointer, function object, or lambda expression) and any arguments required by the callable object.
- *Thread Execution*: Once the thread is created, it begins executing the provided callable object concurrently with the other threads in the program. The new thread executes the specified function or callable object.
- *Concurrency*: The new thread runs concurrently with the main thread (and any other threads in the program). This means that multiple threads are executing simultaneously, sharing CPU time and potentially accessing shared resources concurrently.
- *Context Switching*: The operating system manages the execution of multiple threads by performing context switches. This involves saving the state of one thread and restoring the state of another thread, allowing them to run in interleaved fashion.
- *Synchronization*: If the thread interacts with shared resources or other threads, synchronization mechanisms such as mutexes, condition variables, or atomic operations may be used to ensure thread safety and prevent data races and other concurrency issues.
- *Completion*: Once the thread has finished executing its task (or has been detached), it exits, and its resources are cleaned up by the operating system.

In summary, creating a thread involves initiating a new execution context, running a specified function concurrently, and potentially coordinating with other threads to ensure correct behavior in a multithreaded environment.

```cpp
std::thread t1(FunctionName, args);
```

## Joining and Detaching Threads:
Joining a thread waits for it to finish execution and then cleans up its resources.
Detaching a thread allows it to run independently without any further interaction from the calling thread, and its resources are automatically cleaned up upon completion.

### Joining Threads:
Joining a thread means that the calling thread will wait for the specified thread to finish its execution before continuing.
The join() member function is called on the std::thread object to perform this action.
If the specified thread has already finished executing, join() returns immediately.
If the specified thread is still running, the calling thread is blocked until the specified thread finishes.
Once the joined thread completes its execution, its resources are cleaned up, and the join() call returns.

```cpp
t1.join();
```

### Detaching Threads:
Detaching a thread means that the calling thread relinquishes ownership of the specified thread, allowing it to execute independently.
The detach() member function is called on the std::thread object to perform this action.
After detaching a thread, the calling thread no longer has any control over the detached thread.
The detached thread continues to execute independently until it completes or is terminated.
Once a thread is detached, its resources are automatically cleaned up by the operating system when it finishes execution.

```cpp
t1.detach();
```

```cpp
#include <iostream>
#include <thread>
#include <chrono>

// Function that will be executed by the thread
void ThreadFunction(int id) {
    // Simulate some work by sleeping for a while
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Thread " << id << " has finished its work." << std::endl;
}

int main() {
    // Creating a thread and joining it
    std::thread t1(ThreadFunction, 1);
    std::cout << "Main thread is waiting for t1 to finish..." << std::endl;
    t1.join(); // Main thread waits for t1 to finish

    // Creating a thread and detaching it
    std::thread t2(ThreadFunction, 2);
    t2.detach(); // Detach t2 from the main thread

    // Main thread continues its work
    std::cout << "Main thread continues its work independently." << std::endl;

    // Sleeping to allow detached thread to finish (if it hasn't already)
    std::this_thread::sleep_for(std::chrono::seconds(3));

    return 0;
}
```


## Thread Function:
It refers to the function that a thread will execute when it is created. It's the code block or function pointer that specifies what work the thread should perform concurrently with other threads.

In C++, a thread function can be any callable object that can be executed by a thread. This includes:

- Function pointer.
- Function object (also known as a functor).
- Lambda expression.
- Member function pointer (when used with std::thread constructor and std::bind).
  
```cpp
void FunctionName(args) {
    // Thread logic
}
```

## Mutexes (Mutual Exclusion):
Mutexes are synchronization primitives used to protect shared resources in multithreaded applications. They ensure that only one thread can access a critical section of code at a time, preventing data corruption and race conditions.

```cpp
#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx; // Mutex for protecting shared resource

int sharedData = 0; // Shared resource

// Function to modify the shared data
void ModifySharedData(int id) {
    // Acquire the lock
    mtx.lock();

    // Critical section
    std::cout << "Thread " << id << " is modifying the shared data..." << std::endl;
    sharedData++; // Increment shared data
    std::cout << "Thread " << id << " modified the shared data to: " << sharedData << std::endl;

    // Release the lock
    mtx.unlock();
}

int main() {
    // Create two threads to modify the shared data
    std::thread t1(ModifySharedData, 1);
    std::thread t2(ModifySharedData, 2);

    // Wait for threads to finish
    t1.join();
    t2.join();

    return 0;
}
```

## RAII Locking (Resource Acquisition Is Initialization):
RAII (Resource Acquisition Is Initialization) locking is a programming idiom used to manage resource acquisition and release in a scoped and automatic manner. In the context of multithreading, RAII locking is often used to manage mutexes and other synchronization primitives.

```cpp
std::mutex mtx; // Declaration
{
    std::lock_guard<std::mutex> lock(mtx); // Automatically lock and unlock mutex
    // Critical section
}
```
Here's how RAII locking works:

1. **Resource Acquisition:** When acquiring a lock (e.g., a mutex), a lock object is created within a limited scope, such as within a function or a code block.

2. **Initialization:** The lock object is initialized with the mutex, automatically acquiring the lock on the mutex. This initialization happens at the point of object creation.

3. **Automatic Release:** When the lock object goes out of scope (i.e., when it goes out of the limited scope where it was declared), its destructor is automatically called. This destructor releases the lock on the mutex, ensuring that the mutex is unlocked even if an exception occurs or the control flow exits prematurely.

RAII locking ensures that mutexes (or other synchronization primitives) are always properly released, regardless of how the block of code is exited (e.g., through normal execution, an exception, or an early return statement), thereby preventing deadlocks, resource leaks, and other synchronization issues.

Here's an example of RAII locking using `std::lock_guard`:

```cpp
#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx; // Mutex for synchronization

void ThreadFunction() {
    std::lock_guard<std::mutex> lock(mtx); // RAII lock acquisition
    // Critical section
    std::cout << "Thread executing critical section..." << std::endl;
} // lock goes out of scope and releases the mutex automatically

int main() {
    std::thread t(ThreadFunction);
    t.join();
    return 0;
}
```
In this example, std::lock_guard is used to acquire the lock on mtx within the scope of ThreadFunction(). The lock is automatically released when the lock object goes out of scope, ensuring proper synchronization without the need for manual unlocking.


## Condition Variables:
Condition variables are synchronization primitives used in multithreaded programming to facilitate communication between threads. They allow threads to wait for a certain condition to become true before proceeding with their execution. Condition variables are often used in conjunction with mutexes to coordinate access to shared resources among multiple threads.

Here's a brief overview of how condition variables work:

1. **Waiting for a Condition:** A thread waits on a condition variable by calling the `wait()` or `wait_for()` function. Before calling `wait()`, the thread must first acquire a lock on a mutex associated with the condition variable.

2. **Releasing the Lock:** When the thread calls `wait()`, it atomically releases the lock on the mutex and enters a waiting state. This allows other threads to acquire the lock and modify shared data protected by the mutex.

3. **Notification:** Another thread can signal the condition variable when the condition it represents becomes true. This is typically done by calling the `notify_one()` or `notify_all()` function on the condition variable.

4. **Resumption of Waiting Threads:** When a thread waiting on a condition variable is notified, it wakes up and reacquires the lock on the mutex. It then rechecks the condition that it was waiting for. If the condition is still false, the thread may choose to wait again.

Condition variables are useful for scenarios where threads need to coordinate their actions based on changes in shared data or other external events. They help avoid busy-waiting loops and improve efficiency by allowing threads to sleep until they are needed.

Here's a simple example demonstrating the usage of condition variables:

```cpp
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void WorkerThread() {
    std::unique_lock<std::mutex> lock(mtx);
    while (!ready) {
        cv.wait(lock); // Wait until 'ready' becomes true
    }
    std::cout << "Worker thread is now doing its work..." << std::endl;
}

int main() {
    std::thread worker(WorkerThread);
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulate some work
    {
        std::lock_guard<std::mutex> lock(mtx);
        ready = true; // Set the condition to true
    }
    cv.notify_one(); // Notify the worker thread
    worker.join();
    return 0;
}
```
In this example, the main thread sets the ready flag to true after a delay of 2 seconds and then notifies the worker thread using the condition variable cv. The worker thread waits for the condition to become true using cv.wait(), and once notified, it proceeds with its work.

## Atomic Operations:
Atomic operations are operations performed on shared data in a multithreaded environment that are guaranteed to be executed without interruption from other threads. These operations ensure that the data is accessed and modified atomically, meaning that they are indivisible and appear instantaneous to other threads.
In C++, the `std::atomic` template provides support for atomic operations on shared variables. It ensures that read and write operations on the variable are performed atomically, without the need for explicit locking mechanisms such as mutexes.
```cpp
std::atomic<int> counter(0); // Atomic variable declaration
counter.fetch_add(1); // Atomic increment
```

Here are some common atomic operations provided by `std::atomic`:

1. **Load:** Reads the value of the atomic variable atomically.
2. **Store:** Writes a value to the atomic variable atomically.
3. **Exchange:** Atomically reads the value of the atomic variable and replaces it with a new value.
4. **Compare and Swap (CAS):** Compares the value of the atomic variable with an expected value. If they are equal, it updates the value of the atomic variable to a new value atomically.

Atomic operations are useful in scenarios where multiple threads access shared data concurrently and need to perform read-modify-write operations. They ensure that such operations are performed safely without the risk of data races or other concurrency issues.

Here's a simple example demonstrating the usage of atomic operations:

```cpp
#include <iostream>
#include <thread>
#include <atomic>

std::atomic<int> counter(0); // Atomic variable declaration

void IncrementCounter() {
    for (int i = 0; i < 10000; ++i) {
        counter.fetch_add(1); // Atomic increment
    }
}

int main() {
    std::thread t1(IncrementCounter);
    std::thread t2(IncrementCounter);
    t1.join();
    t2.join();
    std::cout << "Counter value: " << counter << std::endl;
    return 0;
}
```
In this example, counter is an atomic variable of type int. Two threads increment counter by 1, each performing 10,000 increments. Since the increment operation (fetch_add) is atomic, concurrent accesses to counter are safe, and the final value of counter is guaranteed to be the sum of increments performed by both threads.


## Thread Safety with Data Structures:
Thread safety with data structures refers to the property of a data structure being able to be safely accessed and modified by multiple threads concurrently without causing data corruption or synchronization issues. In other words, a thread-safe data structure ensures that its internal state remains consistent and correct, even when accessed or modified by multiple threads simultaneously.

Achieving thread safety typically involves using synchronization mechanisms to coordinate access to shared data. Here are some common techniques and considerations for achieving thread safety with data structures:

1. **Mutexes and Locks:** One approach to ensuring thread safety is to use mutexes (mutual exclusion locks) to protect critical sections of code where shared data is accessed or modified. By acquiring a lock before accessing the data and releasing it afterwards, you ensure that only one thread can access the data at a time, preventing race conditions and data corruption.

2. **Atomic Operations:** Another approach is to use atomic data types or operations provided by the language or standard library. Atomic operations ensure that certain operations (such as reads, writes, or updates) on shared variables are performed atomically and cannot be interrupted by other threads.

3. **Read/Write Locks:** For data structures that are predominantly read-mostly but occasionally modified, using read/write locks can improve concurrency. Read locks allow multiple threads to read the data simultaneously, while write locks ensure exclusive access during updates.

4. **Thread-Safe Data Structures:** Many programming languages and libraries provide built-in thread-safe data structures, such as thread-safe queues, maps, sets, etc. These data structures are implemented with internal synchronization mechanisms to ensure thread safety without the need for explicit locking by the user.

5. **Lock-Free Data Structures:** Advanced techniques such as lock-free or wait-free data structures aim to provide high concurrency without relying on traditional locking mechanisms. These data structures use atomic operations and synchronization primitives to achieve thread safety while minimizing contention and overhead.

When designing or using thread-safe data structures, it's important to consider factors such as performance, scalability, and the specific requirements of the application. While synchronization mechanisms ensure correctness, they can also introduce overhead and potential bottlenecks, so it's essential to strike a balance between safety and efficiency. Additionally, thorough testing and validation are crucial to ensure the correctness and robustness of thread-safe data structures in multithreaded environments.

```cpp
#include <vector>
std::mutex mtx; // Declaration
std::vector<int> sharedVector; // Shared data structure
void ModifyVector(int value) {
    std::lock_guard<std::mutex> lock(mtx);
    sharedVector.push_back(value);
}
```

## Challenges and Solutions:
1. **Race Conditions:**
   - Description: Race conditions occur when multiple threads access shared data concurrently without proper synchronization, leading to unpredictable behavior.
   - Solution: Use synchronization mechanisms such as mutexes or atomic operations to ensure that only one thread accesses shared data at a time.

2. **Deadlocks:**
   - Description: Deadlocks occur when two or more threads are blocked indefinitely, waiting for each other to release resources that they hold.
   - Solution: Prevent deadlocks by acquiring locks in a consistent order and using techniques like deadlock detection and avoidance.

3. **Starvation:**
   - Description: Starvation happens when a thread is unable to gain access to a shared resource because other threads continuously acquire the resource, leaving the starving thread waiting indefinitely.
   - Solution: Implement fairness policies or scheduling algorithms to ensure that all threads have a chance to access shared resources.

4. **Priority Inversion:**
   - Description: Priority inversion occurs when a low-priority thread holds a lock needed by a high-priority thread, causing the high-priority thread to wait longer than expected.
   - Solution: Use priority inheritance protocols or priority ceiling protocols to prevent priority inversion and ensure that high-priority threads can proceed without undue delay.

5. **Oversubscription:**
   - Description: Oversubscription occurs when the number of threads created exceeds the available hardware resources, leading to decreased performance due to excessive context switching.
   - Solution: Design your multithreaded application to create an optimal number of threads based on available hardware resources, workload characteristics, and performance requirements.

6. **Data Races:**
   - Description: Data races occur when two or more threads access the same memory location concurrently, and at least one of the accesses is a write operation, leading to undefined behavior.
   - Solution: Use synchronization primitives such as mutexes, locks, or atomic operations to protect shared data and prevent data races.

7. **Scalability Issues:**
   - Description: Scalability issues arise when adding more threads to a multithreaded application does not result in a proportional increase in performance due to contention or synchronization overhead.
   - Solution: Employ techniques such as workload partitioning, lock-free data structures, and fine-grained locking to improve scalability and maximize parallelism.

8. **Debugging Multithreaded Code:**
   - Description: Debugging multithreaded code can be challenging due to the non-deterministic nature of thread execution and the difficulty of reproducing concurrency-related bugs.
   - Solution: Use tools like thread sanitizers, race condition detectors, and debuggers with multithreading support to identify and diagnose issues in multithreaded code.
