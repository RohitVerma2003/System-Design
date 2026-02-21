#include "../headers/Post.hpp"

Post::Post(string content, string user){
    this->content = content;
    this->user_id = user;

    int num = rand() % 100000;
    this->id = to_string(num);
}

void Post::add_vote(Vote *vote){this->votes.push_back(vote);}

void Post::add_comment(Comment *comm){this->comments.push_back(comm);}

string Post::get_id(){return this->id;}

string Post::get_user_id(){return this->content;}

string Post::get_content(){return this->content;}

int Post::get_vote_counts(){return this->votes.size();}

int Post::get_comments_counts(){return this->comments.size();}

vector<Comment *> Post::get_comments(){return this->comments;}

vector<Vote *> Post::get_votes(){return this->votes;}
