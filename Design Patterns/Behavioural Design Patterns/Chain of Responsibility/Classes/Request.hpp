#pragma once
#include "Request.hpp"
#include <string>
using namespace std;

class Request{
public:
    string user;
    string user_role;
    string payload;
    int request_count;

    Request(string user , string role , string payload , int count): user(user) , user_role(role) , payload(payload) , request_count(count){}
};