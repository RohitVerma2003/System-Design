#ifndef ANSWER_HPP
#define ANSWER_HPP

#include <string>
#include "./Post.hpp"
using namespace std;

class Answer : public Post{
private:
    string question_id;
public:
    Answer(string content , string user , string post);
};

#endif