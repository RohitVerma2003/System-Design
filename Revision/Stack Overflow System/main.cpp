#include "./headers/StackOverflow.hpp"
#include "./headers/Question.hpp"
#include "./headers/Answer.hpp"
#include <iostream>
using namespace std;

int main(){
    StackOverflow& system = StackOverflow::getInstance();
    StackOverflow& system2 = StackOverflow::getInstance();

    cout<<"Systems: "<<&system<<" "<<&system2<<endl;

    User* user = system.create_user("Rohit" , "rohit@gmail.com");
    cout<<"User Created: "<<user->get_id()<<" "<<user->get_name()<<endl;

    User* user2 = system.create_user("Verma" , "verma@gmail.com");
    cout<<"User Created: "<<user2->get_id()<<" "<<user2->get_name()<<endl;

    Post* post1 = new Question("React DOM Problems" , user->get_id());
    cout<<"Post created: "<<post1->get_id()<<" "<<post1->get_content()<<endl;

    system.add_post(post1);
    cout<<"Post added: "<<system.search_post(post1->get_id())->get_id()<<" "<<post1->get_content()<<endl;

    Comment* comm1 = new Comment("React DOM is difficult" , post1->get_id() , user->get_id());
    system.add_comment(comm1 , post1->get_id());
    cout<<"Comment added: "<<comm1->get_id()<<" , Post ID: "<<comm1->get_post_id()<<" , User ID: "<<comm1->get_user_id()<<endl;

    Post* ans1 = new Answer("React Dom Answer" , user2->get_id() , post1->get_id());
    system.add_post(ans1);
    cout<<"Answer added: "<<system.search_post(ans1->get_id())->get_id()<<" "<<ans1->get_content()<<endl;


    cout<<"============"<<endl;

    cout<<"Post: "<<post1->get_id()<<" "<<post1->get_content()<<endl;
    cout<<"Post Comments Counts: "<<post1->get_comments_counts()<<" Comments: ";
    for(auto c : post1->get_comments()) cout<<c->get_id()<<" -> "<<c->get_comment()<<" , ";
    cout<<endl;
    cout<<"Post Answers: "<<system.search_post(ans1->get_id())->get_content()<<endl;
    return 0;
}