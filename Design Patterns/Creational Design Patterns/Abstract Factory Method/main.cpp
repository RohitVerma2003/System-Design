#include<iostream>
#include "Interfaces/Application.h"
#include "Classes/WindowFactory.h"
#include "Interfaces/GUIFactory.h"
using namespace std;

int main(){
    GUIFactory* factory = new WindowFactory();
    Application app(factory);
    app.renderUI();
    app.clickButton();

    return 0;
}