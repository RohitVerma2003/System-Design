#include "../headers/Vote.hpp"

Vote::Vote(string user_id , string post_id , VoteType vote_type): user_id(user_id) , post_id(post_id) , vote_type(vote_type){}
VoteType Vote::get_vote_type() {return this->vote_type;}