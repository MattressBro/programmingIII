//Braden Heeney
//CSC450-1 
//Critical Thinking 3
// 3/2/2025
#include <iostream>
#include <string>
using namespace std;
int main() {
    int num1, num2, num3;
    cout << "Enter three integer values.";
    cout << endl << "Value 1: ";
    cin >> num1;
    cout << "Value 2: ";
    cin >> num2;
    cout << "Value 3: ";
    cin >> num3;

    int* ptr1 = new int(num1);
    int* ptr2 = new int(num2);
    int* ptr3 = new int(num3);

    cout << "Values entered: " << num1 << ", " << num2 << ", " << num3 << endl;
    cout << "Pointer values: " << *ptr1 << ", " << *ptr2 << ", " << *ptr3 << endl;

    delete ptr1;
    delete ptr2;
    delete ptr3;

    return 0;
}