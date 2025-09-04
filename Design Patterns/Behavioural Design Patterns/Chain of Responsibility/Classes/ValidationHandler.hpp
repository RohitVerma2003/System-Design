#include "../Interfaces/IHandler.hpp"
#include "Request.hpp"
#include <iostream>
using namespace std;

class ValidationHandler : public IHandler{
public:
    void handle(Request request) override{
        if(request.payload.empty()){
            cout<<"Validation Handler: Data not valid"<<endl;
            return;
        }

        cout<<"Validation Handler: Data is valid"<<endl;
        this->forward_req(request);
    }
};