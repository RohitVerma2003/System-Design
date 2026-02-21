#ifndef QUESTION_HPP
#define QUESTION_HPP

#include "./Post.hpp"
#include "./Tag.hpp"
#include "./Keyword.hpp"

class Question: public Post{
private:
    vector<Tag*> tags;
    vector<Keyword*> keywords;
public:
    Question(string content , string user);
    void set_tag(Tag* tag);
    void set_keywords(Keyword* keyword);
    vector<Tag*> get_tags();
    vector<Keyword*> get_keywords();
};

#endif