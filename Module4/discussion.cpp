#include <iostream>
#include <string>
#include <limits>

using namespace std;
int main(){
    int age;
    while (true) {
        cout << "Enter your age: ";
        cin >> age;
        if (cin.fail()) {
            cin.clear(); // clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            cout << "Invalid input. Please enter a valid integer." << endl;
        } else {
            break; // valid input, exit the loop
        }
    }
}