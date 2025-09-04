#include "../Interfaces/IHandler.hpp"
#include "Request.hpp"
#include <iostream>
using namespace std;

class BussinessLogic : public IHandler{
public:
    void handle(Request request) override{
        cout<<"Bussiness Handler: Processing your request...."<<endl;
    }
};