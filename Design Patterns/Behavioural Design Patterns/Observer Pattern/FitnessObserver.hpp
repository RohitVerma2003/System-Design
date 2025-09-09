#pragma once

class FitnessData;

class FitnessObserver{
public:
    virtual ~FitnessObserver(){}
    virtual void update(FitnessData* data) = 0;
};