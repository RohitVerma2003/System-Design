
#include "FitnessData.hpp"
#include "LiveActivityDisplay.hpp"
#include <iostream>
using namespace std;

void fitnessObserverDemo(){
    FitnessData* fitnessData = new FitnessData();
    LiveActivityDisplay* new_observer = new LiveActivityDisplay();
    cout<<"Run"<<endl;

    fitnessData->subscribe_observer(new_observer);
    fitnessData->push_new_data(500 , 3500 , 20);

    delete fitnessData;
    delete new_observer;
}

int main(){
    fitnessObserverDemo();
    return -1;
}