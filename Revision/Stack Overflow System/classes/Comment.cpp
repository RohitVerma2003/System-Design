#include "../headers/Comment.hpp"

Comment::Comment(string text , string post , string user){
    this->text = text;
    this->user_id = user;
    this->post_id = post;

    int num = rand() % 100000;
    this->id = to_string(num);
}

string Comment::get_comment() {return this->text;}
string Comment::get_id() {return this->id;}
string Comment::get_post_id() {return this->post_id;}
string Comment::get_user_id() {return this->user_id;}