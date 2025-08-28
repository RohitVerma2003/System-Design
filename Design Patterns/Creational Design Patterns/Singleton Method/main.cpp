#include <iostream>
#include "Singleton.h"
#include <mutex>
using namespace std;

Singleton* Singleton::instance = NULL;
mutex Singleton::lock;

int main(){
    Singleton* instance1 = Singleton::getInstance();
    Singleton* instance2 = Singleton::getInstance();
    cout<<instance1<<endl;
    cout<<instance2<<endl;
    return 0;
}