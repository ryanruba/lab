#include <iostream>
using namespace std;
const int arraysize = 10;
int searchArray(double array[], double key) {
    for (int i = 0; i < arraysize; i++)
        if (array[i] == key) return i;
    return -1;
}
int main() {
    double array[arraysize], key;
    cout << "Enter " << arraysize << " values:\n";
    for (double& value : array) cin >> value;
    cout << "Search for: ";
    cin >> key;
    int result = searchArray(array, key);
    if (result != -1) {
        cout << "Found at index: " << result << endl;
    }
    else {
        cout << "Not Found" << endl;
    }
    return 0;
}
