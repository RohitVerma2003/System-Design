#include "../Interfaces/IHandler.hpp"
#include "Request.hpp"
#include <iostream>
using namespace std;

class AuthHandler : public IHandler{
public:
    void handle(Request request) override{
        if(request.user.empty()){
            cout<<"AuthHandler: User not authenticated"<<endl;
            return;
        }

        cout<<"AuthHandler: User is authrnticated"<<endl;
        this->forward_req(request);
    }
};