#ifndef USER_HPP
#define USER_HPP

#include <string>

class User{
private:
    std::string name , email;
public:
    User(std::string name , std::string email);
    std::string get_name();
    std::string get_email();
};

#endif