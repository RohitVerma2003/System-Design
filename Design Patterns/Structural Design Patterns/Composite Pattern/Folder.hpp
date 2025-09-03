#include <iostream>
#include <string>
#include <vector>
#include "FileSystemItem.hpp"
using namespace std;

class Folder : public FileSystemItem{
private:
    string name;
    vector<FileSystemItem*> contents;
    
public:
    Folder(string name) : name(name){}

    void add_item(FileSystemItem* item){
        this->contents.push_back(item);
    }

    int get_size() override{
        int ans = 0;
        for(auto content : this->contents){
            ans += content->get_size();
        }
        return ans;
    }

    void delete_item() override{
        for(auto content : this->contents){
            content->delete_item();
        }

        cout<<"Deletng Folder: "<<this->name<<endl;
    }

    void print_structure(string indent) override{
        cout<<indent<<"+ "<<this->name<<"/"<<endl;

        for(auto content : this->contents){
            content->print_structure(indent + " ");
        }
    }
};