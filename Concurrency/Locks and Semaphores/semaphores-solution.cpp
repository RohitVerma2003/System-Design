#include <iostream>
#include <thread>
#include <semaphore>

using namespace std;

counting_semaphore<2> sem(2);

void task(int id) {
    sem.acquire();
    cout << "Thread " << id << " entered\n";
    this_thread::sleep_for(chrono::seconds(2));
    cout << "Thread " << id << " leaving\n";
    sem.release();
}

int main() {
    thread t1(task, 1);
    thread t2(task, 2);
    thread t3(task, 3);

    t1.join();
    t2.join();
    t3.join();
}