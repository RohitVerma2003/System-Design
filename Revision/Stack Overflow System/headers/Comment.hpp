#ifndef COMMENT_HPP
#define COMMENT_HPP

#include <string>
#include <random>
using namespace std;

class Comment{
private:
    string text , post_id , user_id , id;
public:
    Comment(string text , string post , string user);
    string get_comment();
    string get_id();
    string get_post_id();
    string get_user_id();
};

#endif