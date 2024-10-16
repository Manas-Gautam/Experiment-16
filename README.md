# Experiment-16
## Theory: - 
Exception handling in C++ is a mechanism that allows you to handle runtime errors and ensure that a program doesn't crash unexpectedly. It helps in separating error-handling code from regular code, making the code cleaner and easier to maintain. Here's a breakdown of the theory behind exception handling in C++:

### Key Concepts of Exception Handling:

1. **Exceptions**: 
   - An exception is an error condition or unexpected situation that arises during the execution of a program.
   - C++ exceptions are objects of any type, but it is common to throw standard types or custom classes derived from `std::exception`.

2. **Throwing Exceptions**: 
   - When a function detects an error that it cannot handle, it throws an exception using the `throw` keyword. 
   - Syntax: `throw exception_object;`
   - Example:
     ```cpp
     if (x == 0) {
         throw std::invalid_argument("Division by zero");
     }
     ```

3. **Catching Exceptions**: 
   - When an exception is thrown, the program looks for an appropriate handler to catch it. A handler is defined using the `try` and `catch` blocks.
   - A `try` block contains the code that might throw an exception, and the `catch` block contains code to handle the exception.
   - Syntax:
     ```cpp
     try {
         // code that might throw an exception
     }
     catch (exception_type& e) {
         // handle the exception
     }
     ```
   - Example:
     ```cpp
     try {
         // code that may throw an exception
         int result = divide(a, b);
     }
     catch (const std::invalid_argument& e) {
         std::cout << "Error: " << e.what() << std::endl;
     }
     ```

4. **Multiple Catch Blocks**:
   - You can have multiple `catch` blocks to handle different types of exceptions.
   - Example:
     ```cpp
     try {
         // code that may throw an exception
     }
     catch (const std::out_of_range& e) {
         std::cout << "Out of range error: " << e.what() << std::endl;
     }
     catch (const std::invalid_argument& e) {
         std::cout << "Invalid argument error: " << e.what() << std::endl;
     }
     ```

5. **Generic Catch Block**:
   - You can use a generic catch block to catch exceptions of any type using `catch(...)`.
   - Example:
     ```cpp
     try {
         // code that may throw an exception
     }
     catch (...) {
         std::cout << "An unknown exception occurred" << std::endl;
     }
     ```

6. **Stack Unwinding**:
   - When an exception is thrown, the C++ runtime performs "stack unwinding." It goes backward through the call stack, cleaning up and destroying objects created in functions along the way, until it finds an appropriate exception handler.
   - This ensures that destructors of local objects are automatically called, preventing resource leaks.

7. **Standard Exceptions**:
   - The C++ Standard Library provides a set of standard exceptions, all of which inherit from the `std::exception` class. Commonly used standard exceptions include:
     - `std::exception`: The base class for all standard exceptions.
     - `std::runtime_error`: For general runtime errors.
     - `std::invalid_argument`: For invalid function arguments.
     - `std::out_of_range`: For accessing elements out of bounds (e.g., in arrays or vectors).
     - `std::bad_alloc`: For memory allocation failures.

8. **Custom Exceptions**:
   - You can define your own exception classes by inheriting from `std::exception` or any other standard exception class.
   - Example:
     ```cpp
     class MyException : public std::exception {
     public:
         const char* what() const noexcept override {
             return "Custom exception occurred";
         }
     };
     ```

9. **Rethrowing Exceptions**:
   - You can catch an exception and rethrow it using the `throw;` statement. This is useful when you want to add some additional information or logging but still allow higher levels of code to handle the exception.
   - Example:
     ```cpp
     try {
         // code that may throw an exception
     }
     catch (const std::exception& e) {
         std::cout << "Logging error: " << e.what() << std::endl;
         throw;  // rethrow the exception
     }
     ```

10. **Exception Specification (deprecated)**:
    - Older versions of C++ used exception specifications to declare which exceptions a function might throw using the `throw()` syntax. However, this feature is deprecated in modern C++ and has been replaced with `noexcept`.

11. **`noexcept`**:
    - The `noexcept` keyword indicates that a function is not expected to throw exceptions. If an exception is thrown from a `noexcept` function, the program will terminate.
    - Syntax: 
      ```cpp
      void myFunction() noexcept { /* function code */ }
      ```

### Advantages of Exception Handling:

- **Cleaner Error Handling**: It separates error-handling code from regular code, making programs easier to understand and maintain.
- **Automatic Cleanup**: Stack unwinding ensures that destructors are called and resources are freed when an exception occurs.
- **Flexibility**: Different types of exceptions can be handled using multiple `catch` blocks, making it easier to differentiate between errors.

### Best Practices:

- Use exceptions for error conditions that are truly exceptional and not for normal flow control.
- Always catch exceptions by reference (e.g., `catch(const std::exception& e)`), to avoid slicing and performance overhead.
- Use `std::exception` and its derived classes to benefit from the built-in `what()` function, which provides error messages.

## Experiment 16{A}: - Prompt the user to enter a positive number. If user enters positive number, display that number. If user enters negative number throw an exception.

## Code : - 


#include<iostream>
 using namespace std;

int main() {
    float a;
    cout << "Enter a positive number: ";
    cin >> a;

    try {
        if (a < 0) {
            throw a;
        } else {
            cout << "The number is: " << a << endl;
        }
    } catch (const float n) {
        cout << "You entered " << a << " which is a negative number: " << n << endl;
    }
    return 0;
}

## Output: - 

![image](https://github.com/user-attachments/assets/06b90967-0f97-46df-91a9-c8363992fc16)

## Experiment 16 {B}: - Prompt the user to enter a year greater than 2000. If user enters year greater than 2000, then display that year. If user enters year less than 2000 throw an exception.

## Code: - 


#include<iostream>
using namespace std;

int main() {
    int year;
    cout << "Enter year greater than 2000: ";
    cin >> year;

    try {
        if (year < 2000) {
            throw "You entered a year less than 2000";
        } else {
            cout << "Entered year is: " << year << endl;
        }
    } catch (const char* msg) {
        cout << msg << endl;
    }
    return 0;
}

## Output: - 

![image](https://github.com/user-attachments/assets/f2596977-7169-43b2-b6d7-576b643c92f4)

### Conclusion:

Exception handling in C++ is a powerful mechanism that provides a structured way to handle runtime errors and ensures that programs can recover gracefully from unexpected situations. By using `try`, `catch`, and `throw`, C++ enables the separation of error-handling code from regular code, making programs cleaner and easier to maintain. With features like stack unwinding, automatic resource cleanup, and customizable exception types, C++ exception handling offers both flexibility and robustness. However, it should be used judiciously for true exceptional conditions, ensuring that performance and code clarity are maintained.

