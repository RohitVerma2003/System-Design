#pragma once
#include <string>
using namespace std;

class IImage{
public:
    virtual void display() = 0;
    virtual string get_file_name() = 0;
    virtual ~IImage() {}
};