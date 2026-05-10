#include <bits/stdc++.h>
using namespace std;

int sum(int a, int b) {
    return a + b;
}

int substraction(int a, int b) {
    return a - b;
}

void swap(int a, int b) {
    cout << a << " " << b << endl;
    int temp = a;
    a = b;
    b = temp;
    cout << a << " " << b << endl;
}

void swap_reference(int &a, int &b) {
    cout << a << " " << b << endl;
    int temp = a;
    a = b;
    b = temp;
    cout << a << " " << b << endl;
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }cout << endl;
}
void set_to_zero(int arr[], int index) {
    if (index >= 0) {
        arr[index] = 0;
    }
}

double area(double length, double width) {
    return length * width;
}
double area(double side) {
    return side * side;
}

// Use a default argument of 2 for the exponent.
// The function should calculate the square if the exponent
// is omitted during the call.
// use pow for calculating the power
double power(double base, int exponent = 2) {
    return pow(base, exponent);
}

long long factorial(int n) {
    // base case
    if (n == 0) {
        return 1;
    }
    else {
        return n * factorial(n - 1);
    }
}

int fibonacci_func(int m) {
    if (m == 0) {
        return 0;
    }

    if (m == 1) {
        return 1;
    }

    if (m >= 2) {
        return fibonacci_func(m - 1) + fibonacci_func(m - 2);
    }

    return -1; // Fallback return statement
}

void fibonacci_print(int size = 9) {
    int n = 0;
    while (n <= size) {
        cout << fibonacci_func(n) << " ";
        n++;
    }
}

// Function defined as inline
inline int add(int a, int b) {
    return a + b;
}

// Target function
int max_of_two(int a, int b) {
    return (a > b) ? a : b;
}

int execute_operation(int a, int b, int (*operation) (int, int)) {
    return operation(a,b);
}

// Function  Template definition
// A Function Template defines a generic function that can operate on different
// data types without being rewritten for each type.
//The compiler generates specific versions of the function at compile
//time, a concept known as generic programming.
template <typename T>
T max_value(T a, T b) {
    return (a > b) ? a : b;
}

//This template combines generic programming with pass by reference.
//By using T& for the parameters, the function can swap any two variables of type T,
//avoiding code duplication while maintaining efficiency.
template <typename T>
T swap_generic(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

void print_string(const string &s) {
    cout << "String value (read-only): " << s << endl;
    // This line would cause a compile-time error:
    // s = "Attempted modification";
}

// This line would cause a compile-time error:
// s = "Attempted modification";


bool is_prime(int n) {
    if (n <= 1) return false;
    // Check divisibility up to the square root of n
    for (int i = 2; i <= std::sqrt(n); ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// Function definition: takes const reference
int sum_vector(const std::vector<int> &vec) {
    int total = 0;
    // Range-based for loop for easy iteration
    for (int element : vec) {
        total += element;
    }
    return total;
}

int main () {
    cout << sum(2,4) << endl;
    swap(2, 3);

    int x = 3;
    int y = 4;
    swap_reference(x, y);
    int arr[] = {1, 2, 4, 6, 7, 9};
    int size_arr =  sizeof(arr)/ sizeof(arr[0]);
    print_array(arr,size_arr);
    set_to_zero(arr, 1);
    print_array(arr,size_arr);
    cout << "Override Example: " << endl;
    cout << area(3,5) << endl;
    cout << area(2) << endl;
    cout << power(2) << endl;
    cout << power(2, 3) << endl;
    cout << factorial(5) << endl;
    cout << fibonacci_func(9) << endl;
    fibonacci_print();
    std::cout << "x:" << x <<" y:" <<y << std::endl;
    // The compiler is requested to replace this call with the function body.
    int result = add(x, y);
    std::cout << "Inline add result: " << result << std::endl;


    //A function pointer stores the memory address of a function, allowing
    //the function to be called indirectly.
    //The declaration defines the pointer as pointing to a function
    //taking two integers and returning an integer.
    int (*ptr_max)(int, int) = max_of_two;

    int s = 45;
    int z = 90;

    // Calling the function using the pointer
    int result_ptr = ptr_max(s, z);

    std::cout << "Using function pointer, max of " << x << " and " << y << " is: " << result_ptr << std::endl;

    // This exercise demonstrates passing a function pointer as a parameter. The function’s
    // behavior is determined entirely by the function passed to it,
    // which is the basis for implementing callback mechanisms.
    execute_operation(3,6, add);
    execute_operation(3,6, substraction);

    // 1. Using with integers
    std::cout << "Max int: " << max_value(5, 10) << std::endl;

    // 2. Using with doubles
    std::cout << "Max double: " << max_value(3.14, 2.71) << std::endl;

    // 3. Using with characters
    std::cout << "Max char: " << max_value('z', 'a') << std::endl;

    double d1 = 5.5;
    double d2 = 9.9;

    swap_generic(x, y); // Swapping integers
    swap_generic(d1, d2); // Swapping doubles

    std::cout << "After swap (int): x = " << x << ", y = " << y << std::endl;
    std::cout << "After swap (double): d1 = " << d1 << ", d2 = " << d2 << std::endl;

    //Pass by Constant Reference (const T&) is an optimization. The use of & avoids creating a full
    //copy of the large string object. The use of const guarantees that the
    //function cannot modify the original object, maintaining data integrity.
    std::string message = "This is a long message.";

    print_string(message);

    std::cout << "Original string remains: " << message << std::endl;

    std::cout << "Prime numbers between 1 and 20:" << std::endl;
    for (int i = 1; i <= 20; ++i) {
        if (is_prime(i)) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;

    // This exercise applies function concepts to the Standard Template Library (STL).
    // By using const reference (const std::vector<int> &), we achieve efficiency (
    // no vector copy) and safety (the function cannot modify the original vector).
    std::vector<int> data = {10, 20, 30, 40};

    int total_sum = sum_vector(data); // Expected sum: 100

    std::cout << "The sum of the vector elements is: " << total_sum << std::endl;


    return 0;
}