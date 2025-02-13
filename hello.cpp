#include <iostream>
#include <string>

using namespace std;
int main() {
    string name = "Braden";
    int age = 27;
    float weight = 161.5;
    
    cout << "Enter your name: ";
    cin >> name;
    cout << "Hello, " << name << "!" << endl;
    return 0;
}