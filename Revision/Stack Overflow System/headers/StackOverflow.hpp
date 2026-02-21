#ifndef STACKOVERFLOW_HPP
#define STACKOVERFLOW_HPP

#include "./Post.hpp"
#include "./Vote.hpp"
#include "./Comment.hpp"
#include "./User.hpp"
#include <unordered_map>
#include <string>
#include <mutex>
#include <atomic>
using namespace std;

class StackOverflow{
private:
    unordered_map<string , Post*> posts;
    unordered_map<string , User*> users;
    
    StackOverflow();
    StackOverflow(const StackOverflow&) = delete;
    StackOverflow& operator=(const StackOverflow&) = delete;
public:
    static StackOverflow& getInstance();
    User* create_user(string name , string email);
    void add_post(Post* post);
    void add_comment(Comment* comment , string post_id);
    void add_vote(Vote* vote , string post_id);
    Post* search_post(string id);
    User* get_user(string id);
};

#endif