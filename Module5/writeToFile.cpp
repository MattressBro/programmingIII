#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
//Braden Heeney
//CSC450-1 Module 5 Critical Thinking
//3/15/2025
using namespace std;
void appendToFile(const string& filename, const string& data);
void reverseFileContent(const string& inputFilename, const string& outputFilename);
int main() {
    string filename = "CSC450_CT5_mod5.txt";
    string reversedFilename = "CSC450-mod5-reverse.txt";
    string userInput;
    cout << "Enter data to append to the file: ";
    getline(cin, userInput);
    appendToFile(filename, userInput);
    reverseFileContent(filename, reversedFilename);
    cout << "Data appended and file content reversed successfully." << endl;
    return 0;
}
void appendToFile(const string& filename, const string& data) {
    ofstream outFile;
    outFile.open(filename, ios::app); // Open file in append mode
    if (outFile.is_open()) {
        outFile << data << endl;
        outFile.close();
    } else {
        cerr << "Unable to open file." << endl;
    }
}

void reverseFileContent(const string& inputFilename, const string& outputFilename) {
    ifstream inFile(inputFilename);
    ofstream outFile(outputFilename);
    if (inFile.is_open() && outFile.is_open()) {
        string line, content;
        while (getline(inFile, line)) {
            content += line + '\n';
        }
        reverse(content.begin(), content.end());
        outFile << content;
        inFile.close();
        outFile.close();
    } else {
        cerr << "Unable to open file." << endl;
    }
}