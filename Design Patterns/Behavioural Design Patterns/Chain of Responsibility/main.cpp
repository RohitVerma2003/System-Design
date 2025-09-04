#include "./Classes/AutherizationHandler.hpp"
#include "./Classes/AuthHandler.hpp"
#include "./Classes/Request.hpp"
#include "./Classes/ValidationHandler.hpp"
#include "./Classes/BussinessLogicHandler.hpp"
#include "./Interfaces/IRequestHandler.hpp"
#include "./Classes/RateLimitHandler.hpp"

int main(){
    IRequestHandler* auth = new AuthHandler();
    IRequestHandler* autherize = new AutherizationHandler();
    IRequestHandler* rate_limiter = new RateLimitHandler();
    IRequestHandler* validation = new ValidationHandler();
    IRequestHandler* bussiness_logic = new BussinessLogic();

    auth->set_next(autherize);
    autherize->set_next(rate_limiter);
    rate_limiter->set_next(validation);
    validation->set_next(bussiness_logic);

    Request request("Rohit" , "ADMIN" , "data: 123" , 12);
    auth->handle(request);

    return -1;
}