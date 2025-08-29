#include<iostream>
#include "./Classes/BoldText.h"
#include "./Classes/ItalicText.h"
#include "./Classes/UnderlineText.h"
#include "./Classes/PlainText.h"
using namespace std;

class TextRenderer{
public:
    static void main(){
        PlainText* text = new PlainText("Rohit Verma");
        cout<<"Plain: ";
        text->render();
        cout<<endl;

        BoldText bold(text);
        cout<<"Bold: ";
        bold.render();
        cout<<endl;

        ItalicText italics(text);
        cout<<"Italics: ";
        italics.render();
        cout<<endl;

        UnderlineText underline(text);
        cout<<"Underline: ";
        underline.render();
        cout<<endl;

        ItalicText bold_italics(&bold);
        UnderlineText bold_italics_underline(&bold_italics);
        cout<<"Custom: ";
        bold_italics_underline.render();
        cout<<endl;
    }
};

int main(){
    TextRenderer::main();
    return -1;
}