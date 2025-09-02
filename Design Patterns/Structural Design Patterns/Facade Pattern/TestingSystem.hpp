#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

class TestingSystem{
public:
    bool unit_testing(){
        cout<<"Testing: unit testing start..."<<endl;
        simulate_delay();
        cout<<"Testing: unit testing done..."<<endl;
        return true;
    }

    bool integration_testing(){
        cout<<"Testing: integration testing start..."<<endl;
        simulate_delay();
        cout<<"Testing: integration testing done..."<<endl;
        return true;
    }

private:
    void simulate_delay(){
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
};