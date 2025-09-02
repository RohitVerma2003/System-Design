#include <iostream>
#include <thread>
#include <chrono>
using namespace std;
class VCS{
public:
    bool pull_current_branch(string branch){
        cout<<"Pulling the branch: "<<branch<<"..."<<endl;
        return true;
    }

private:
    void simulate_delay(){
        this_thread::sleep_for(chrono::microseconds(1000));
    }
};