#pragma once
#include<iostream>
#include<string>
#include<thread>
#include <chrono>
#include "IImage.h"
using namespace std;

class HighResolutionImage : public IImage{
private:
    string filename;
    char* image_data;

    void load_image_from_disk(){
        cout<<"Loading image: "<<this->filename<<" from disk (this may take a few moments...)"<<endl;
        this_thread::sleep_for(chrono::seconds(2));
        this->image_data = new char[10 * 1024 * 1024];
        cout<<"Image "<<this->filename<<" loaded successfully..."<<endl;
    }
public:
    HighResolutionImage(string fileName) : filename(fileName){
        this->load_image_from_disk();
    }

    ~HighResolutionImage(){
        delete[] this->image_data;
    }

    void display() override{
        cout<<"Displaying image: "<<this->filename<<endl;
    }

    string get_file_name() override{
        return this->filename;
    }
};