#include <iostream>
#include <string>
#include "FileSystemItem.hpp"
using namespace std;

class File : public FileSystemItem{
private:
    string name;
    int size;
public:
    File(string name , int size) : name(name) , size(size){}

    int get_size() override{
        return this->size;
    }

    void delete_item() override{
        cout<<"Deleting the file: "<<this->name<<endl;
    }

    void print_structure(string indent){
        cout<<indent<<"- "<<this->name<<" ("<<this->get_size()<<" KB)"<<endl;
    }
};