#include <iostream>
#include <stdexcept>
#include <exception>
class CustomException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error in nestedFunction";
    }
};
double divide(int numerator, int denominator) {
    if (denominator == 0) throw std::invalid_argument("Division by zero is not allowed.");
    return static_cast<double>(numerator) / denominator;
}
int accessArray(int arr[], int size, int index) {
    if (index < 0 || index >= size) throw std::out_of_range("Index out of bounds.");
    return arr[index];
}
void nestedFunction() { throw CustomException(); }
void outerFunction() {
    try { nestedFunction(); }
    catch (const CustomException& e) {
        std::cout << "Caught exception in outerFunction: " << e.what() << std::endl;
        throw;
    }
}
int main() {
    try {
        int num, denom;
        std::cout << "Enter numerator: "; std::cin >> num;
        std::cout << "Enter denominator: "; std::cin >> denom;
        std::cout << "Result: " << divide(num, denom) << std::endl;
    } catch (const std::invalid_argument& e) { std::cout << "Error: " << e.what() << std::endl; }

    try {
        int size, index;
        std::cout << "Enter array size: "; std::cin >> size;
        int* arr = new int[size];
        for (int i = 0; i < size; ++i) arr[i] = i * 10;
        std::cout << "Enter index to access: "; std::cin >> index;
        std::cout << "Value at index " << index << ": " << accessArray(arr, size, index) << std::endl;
        delete[] arr;
    } catch (const std::out_of_range& e) { std::cout << "Error: " << e.what() << std::endl; }
    try { outerFunction(); }
    catch (const CustomException& e) { std::cout << "Caught rethrown exception in main: " << e.what() << std::endl; }

    return 0;
}
