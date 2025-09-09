#include "FitnessObserver.hpp"
#pragma once

class FitnessSubject{
public:
    virtual ~FitnessSubject(){}
    virtual void subscribe_observer(FitnessObserver* observer) = 0;
    virtual void unsubscribe_observer(FitnessObserver* observer) = 0;
    virtual void notify_observers() = 0;
};