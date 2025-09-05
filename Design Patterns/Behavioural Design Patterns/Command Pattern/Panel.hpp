#include <iostream>
#include <vector>
#include "Command.hpp"
using namespace std;

class Panel{
private:
    Command* command;
    vector<Command*> history;
public:
    Panel():command(nullptr){}

    ~Panel(){
        delete this->command;

        for(auto comm : this->history){
            delete comm;
        }
    }

    void set_command(Command* comm){
        this->command = comm;
    }

    void press(){
        if(this->command){
            this->command->execute();
            this->history.push_back(command);
        }else{
            cout<<"No commands assign yet..."<<endl;
        }
    }

    void undo(){
        if(this->history.empty()){
            cout<<"No commands in history..."<<endl;
        }else{
            this->history.back()->undo();
            this->history.pop_back();
        }
    }
};