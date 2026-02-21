#ifndef VOTE_HPP
#define VOTE_HPP

#include <string>
#include "../enum.hpp"
using namespace std;

class Vote{
private:
    string user_id , post_id;
    VoteType vote_type;
public:
    Vote(string user_id , string post_id , VoteType vote_type);
    VoteType get_vote_type();
};

#endif