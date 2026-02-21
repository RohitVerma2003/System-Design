#include "../headers/StackOverflow.hpp"

StackOverflow::StackOverflow() {}

StackOverflow& StackOverflow::getInstance() {
    static StackOverflow instance; 
    return instance;
}

User *StackOverflow::create_user(string name, string email){
    User* user = new User(name , email);
    this->users[user->get_id()] = user;
    return user;
}

void StackOverflow::add_post(Post *post){
    this->posts[post->get_id()] = post;
}

void StackOverflow::add_comment(Comment *comment, string post_id){
    Post* post = this->posts[post_id];
    if(post) post->add_comment(comment);
}

void StackOverflow::add_vote(Vote *vote, string post_id){
    Post* post = this->posts[post_id];
    if(post) post->add_vote(vote);
}

Post *StackOverflow::search_post(string id){
    return this->posts[id];
}

User *StackOverflow::get_user(string id){
    return this->users[id];
}
