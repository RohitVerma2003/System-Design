#pragma once
#include <string>
using namespace std;

class FileSystemItem{
public:
    virtual void print_structure(string indent) = 0;
    virtual int get_size() = 0;
    virtual void delete_item() = 0;
    virtual ~FileSystemItem(){}
};