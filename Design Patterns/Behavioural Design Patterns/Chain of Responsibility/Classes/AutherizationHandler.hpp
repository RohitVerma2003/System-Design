#include "../Interfaces/IHandler.hpp"
#include "Request.hpp"
#include <iostream>
using namespace std;

class AutherizationHandler : public IHandler{
public:
    void handle(Request request) override{
        if(request.user_role != "ADMIN"){
            cout<<"Autherization Handler: User not autherized"<<endl;
            return;
        }

        cout<<"Autherization Handler: User is autherized"<<endl;
        this->forward_req(request);
    }
};