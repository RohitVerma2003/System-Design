#include "FitnessObserver.hpp"
#include "FitnessData.hpp"

class LiveActivityDisplay : public FitnessObserver{
public:
    void update(FitnessData *data) override{
        cout << "Live Display -> Steps: " << data->get_steps()
             << " | Active Minutes: " << data->get_active_minutes()
             << " | Calories: " << data->get_calories() << endl;
    }
};