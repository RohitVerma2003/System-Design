#pragma once
#include "FitnessSubject.hpp"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class FitnessData : public FitnessSubject {
private:
    int steps, calories, active_minutes;
    vector<FitnessObserver*> observers;

public:
    FitnessData();

    void subscribe_observer(FitnessObserver* new_observer) override;
    void unsubscribe_observer(FitnessObserver* observer) override;
    void notify_observers() override;

    void push_new_data(int new_steps, int new_calories, int new_active_minutes);
    void daily_reset();

    int get_steps();
    int get_calories();
    int get_active_minutes();
};
