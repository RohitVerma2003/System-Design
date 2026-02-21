#include "../headers/Answer.hpp"

Answer::Answer(string content, string user, string post): Post(content , user) , question_id(post){}