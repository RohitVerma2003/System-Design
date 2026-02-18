#include <iostream>
#include <thread>
using namespace std;

int count = 0;

void increament(){
    for(int i = 0; i < 1000000; i++){
        count++;
    }
}

int main(){
    thread t1(increament);
    thread t2(increament);

    t1.join();
    t2.join();

    cout<<"Count: "<<count;

    return -1;
}