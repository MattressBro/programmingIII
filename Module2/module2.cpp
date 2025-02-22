#include <string>
#include <iostream>
//Module 2: Critical Thinking
//CSC450-1 Braden Heeney
using namespace std;
int main(){
    string s1, s2, s3;
    for (int i = 0; i < 3; i++){
        cout << "Enter a string: ";
        getline(cin, s1);
        cout << "Enter another string: ";
        getline(cin, s2);
        s3 = s1 + s2;
        cout << "The concatenated string is: " << s3 << endl;
    }
    return 0;  
}