#pragma once
class UIComponent;

class Mediator{
public:
    virtual void component_changes(UIComponent* component) = 0;
    virtual ~Mediator(){}
};