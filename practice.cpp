#include <iostream>
using namespace std;
bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}
int main() {
    int A[10], primeCount = 0;
    cout << "Enter 10 integers: ";
    for (int i = 0; i < 10; ++i) {
        cin >> A[i];
        if (isPrime(A[i])) ++primeCount;
    }
    cout << "Number of prime numbers in the array: " << primeCount << endl;
    return 0;
}
