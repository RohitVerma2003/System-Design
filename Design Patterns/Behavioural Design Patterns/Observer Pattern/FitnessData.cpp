#include "FitnessData.hpp"

FitnessData::FitnessData() : steps(0), calories(0), active_minutes(0) {}

void FitnessData::subscribe_observer(FitnessObserver* new_observer) {
    if (std::find(observers.begin(), observers.end(), new_observer) == observers.end())
        observers.push_back(new_observer);
}

void FitnessData::unsubscribe_observer(FitnessObserver* observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void FitnessData::notify_observers() {
    for (auto observer : observers) {
        observer->update(this);
    }
}

void FitnessData::push_new_data(int new_steps, int new_calories, int new_active_minutes) {
    steps = new_steps;
    calories = new_calories;
    active_minutes = new_active_minutes;

    std::cout << "New Data Received:" << std::endl;
    std::cout << "Steps-> " << steps << std::endl;
    std::cout << "Calories-> " << calories << std::endl;
    std::cout << "Active Minutes-> " << active_minutes << std::endl;

    notify_observers();
}

void FitnessData::daily_reset() {
    steps = calories = active_minutes = 0;
}

int FitnessData::get_steps() { return steps; }
int FitnessData::get_calories() { return calories; }
int FitnessData::get_active_minutes() { return active_minutes; }
