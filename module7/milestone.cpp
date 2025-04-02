#include <iostream>
#include <string>
#include <thread>

// Module 7: concurrency and multithreading
// CSC450-1 Braden Heeney
//Portfolio Milestone

using namespace std;
void countUp(int x);
void countDown(int x);
int main(){
    int num = 0;    
    thread t1;
    thread t2; 
    t1 = thread(countUp, num); // Create a thread to count up from 0
    t2 = thread(countDown, num); // Create a thread to count down from 20

    t1.join();
    t2.join(); 
    return 0;
}

void countUp(int x){
    while(x <= 20){
        cout << "Count: " << x << endl; // Print current count
        x++; // Increment count
    }
}
void countDown(int x){
    while(x >= 0){
        cout << "Count: " << x << endl; // Print current count
        x--; // Decrement count
    }
}