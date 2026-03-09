#include "../Headers/Intersection.hpp"

Intersection::Intersection(): currentIndex(0){}

void Intersection::add_road(std::string name, int red, int yellow, int green){
    Road* new_road = new Road(name , SignalType::RED , red , yellow , green);
    this->roads.push_back(new_road);
}

void Intersection::print_current_state(){
    for(auto road : roads){
        std::cout<<road->get_name()<<" -> "<<to_string(road->get_signal()->current_state)<<std::endl;
    }
    std::cout<<"========================================"<<std::endl;
}

void Intersection::start(){
    Road* current_road = this->roads[this->currentIndex];
    this->currentIndex = (this->currentIndex + 1) % this->roads.size();
    Road* next_road = this->roads[this->currentIndex];

    Signal* current_signal = current_road->get_signal();
    Signal* next_signal = next_road->get_signal();

    current_signal->current_state = SignalType::YELLOW;
    next_signal->current_state = SignalType::YELLOW;

    this->print_current_state();
    std::this_thread::sleep_for(std::chrono::seconds(current_signal->yellow_duration));

    current_signal->current_state = SignalType::RED;
    next_signal->current_state = SignalType::GREEN;
    
    this->print_current_state();
    std::this_thread::sleep_for(std::chrono::seconds(next_signal->green_duration));
}
