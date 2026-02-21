#ifndef POST_HPP
#define POST_HPP

#include <string>
#include <vector>
#include <random>
#include "../headers/Comment.hpp"
#include "../headers/Vote.hpp"
using namespace std;

class Post{
private:
    string id , content , user_id;
    vector<Comment*> comments;
    vector<Vote*> votes;
public:
    Post(string content , string user);
    void add_vote(Vote* vote);
    void add_comment(Comment* comm);
    string get_id();
    string get_content();
    string get_user_id();
    int get_vote_counts();
    int get_comments_counts();
    vector<Comment*> get_comments();
    vector<Vote*> get_votes();
};

#endif