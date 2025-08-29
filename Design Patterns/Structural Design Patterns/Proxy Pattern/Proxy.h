#pragma once
#include <iostream>
#include <string>
#include "IImage.h"
#include "HighResolutionImage.h"
using namespace std;

class Proxy : public IImage{
private:
    string filename;
    HighResolutionImage* realImage;
public:
    Proxy(string filename) : filename(filename) , realImage(nullptr) {
        cout<<"Proxy is created for "<<filename<<".Real image is not loaded yet."<<endl;
    }

    ~Proxy(){
        delete this->realImage;
    }

    void display() override{
        if(!this->realImage) this->realImage = new HighResolutionImage(this->filename);
        this->realImage->display();
    }

    string get_file_name() override{
        return this->filename;
    }
};