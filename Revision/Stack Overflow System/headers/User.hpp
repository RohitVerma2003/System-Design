#ifndef USER_HPP
#define USER_HPP

#include <string>
#include <random>
using namespace std;

class User{
private:
    string id , name , email;
public:
    User(string name , string email);
    string get_name();
    string get_id();
    void set_name(string name);
    float get_score();
};

#endif