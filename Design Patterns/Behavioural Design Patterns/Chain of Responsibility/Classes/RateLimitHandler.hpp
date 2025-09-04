#include "../Interfaces/IHandler.hpp"
#include "Request.hpp"
#include <iostream>
using namespace std;

class RateLimitHandler : public IHandler{
public:
    void handle(Request request) override{
        if(request.request_count > 100){
            cout<<"Rate Limit Handler: Rate Limit Exceeded"<<endl;
            return;
        }

        cout<<"Rate Limit Handler: Forwarding the request"<<endl;
        this->forward_req(request);
    }
};