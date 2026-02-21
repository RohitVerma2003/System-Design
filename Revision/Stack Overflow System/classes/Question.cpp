#include "../headers/Question.hpp"

Question::Question(string content, string user): Post(content , user){}

void Question::set_tag(Tag *tag){this->tags.push_back(tag);}

void Question::set_keywords(Keyword *keyword){this->keywords.push_back(keyword);}

vector<Tag *> Question::get_tags(){return this->tags;}

vector<Keyword *> Question::get_keywords(){return this->keywords;}
