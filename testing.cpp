#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

using namespace std;

const int NUM_PHILOSOPHERS = 5;

mutex chopsticks[NUM_PHILOSOPHERS];

void philosopher(int id) {
    int left = id;
    int right = (id + 1) % NUM_PHILOSOPHERS;

    while (true) {
        // Thinking
        cout << "Philosopher " << id << " is thinking." << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));

        // Pick up chopsticks
        lock(chopsticks[left], chopsticks[right]);
        lock_guard<mutex> leftLock(chopsticks[left], adopt_lock);
        lock_guard<mutex> rightLock(chopsticks[right], adopt_lock);

        // Eating
        cout << "Philosopher " << id << " is eating." << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));

        // Put down chopsticks
        // Locks are automatically released when lock_guard goes out of scope
    }
}

int main() {
    vector<thread> philosophers;
    for (int i = 0; i < NUM_PHILOSOPHERS; ++i) {
        philosophers.push_back(thread(philosopher, i));
    }

    for (auto& p : philosophers) {
        p.join();
    }

    return 0;
}