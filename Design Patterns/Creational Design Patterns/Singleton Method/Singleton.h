#pragma once
#include <mutex>
using namespace std;

class Singleton{
private:
    static Singleton* instance;
    static mutex lock;
    Singleton(){};

public:
    static Singleton* getInstance() {
        if(instance == NULL){
            lock_guard<mutex> guard(lock);
            if(instance == NULL){
                instance = new Singleton();
            }
        }

        return instance;
    }
};