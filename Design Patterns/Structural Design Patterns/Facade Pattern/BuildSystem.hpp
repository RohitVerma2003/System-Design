#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

class BuildSystem{
public:
    bool compile_project(){
        cout<<"Compiling the project..."<<endl;
        simulate_delay(2000);
        cout<<"Project compile successfully."<<endl;
        return true;
    }

    string artifact_path(){
        cout<<"Build artifact located at: application/atifacts.jrk"<<endl;
        return "application/atifacts.jrk";
    }

private:
    void simulate_delay(int ms){
        this_thread::sleep_for(chrono::milliseconds(ms));
    }
};