#include <iostream>
#include <string>
#include <thread>
#include <mutex>
// Module 7: concurrency and multithreading
// CSC450-1 Braden Heeney
//Portfolio Milestone


using namespace std;
mutex mut; 
void countUp(int& x);
void countDown(int& x);
int main(){
    int num = 0;    
    thread t1, t2;
    t1 = thread(countUp, ref(num));  
    cout << "Thread 1 \n";
    t1.join();
    cout << "\nThread 2" << endl;
    t2 = thread(countDown, ref(num));
    t2.join(); 
    return 0;
}

void countUp(int& x){
    while(x <= 20){
        lock_guard<mutex> lock(mut); 
        cout << x << endl; 
        this_thread::sleep_for(chrono::milliseconds(100));
        if(x == 20)break;
        x++; 
    }
}
void countDown(int& x){
    while(x >= 0){
        lock_guard<mutex> lock(mut);
        cout << x << endl; 
        this_thread::sleep_for(chrono::milliseconds(100));
        x--;
    }
}