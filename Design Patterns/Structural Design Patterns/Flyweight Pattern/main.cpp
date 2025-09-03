#include "TextEditor.hpp"
#include <string>
using namespace std;

int main(){
    TextEditor editor;

    string word1 = "Hello";
    for(int i = 0 ; i < (int)word1.length() ; i++){
        editor.add_character(10 * i + 5 , 10 , word1[i] , "Aerial" , "#0000" , 12);
    }

    string word2 = "Rohit";
    for(int i = 0 ; i < (int)word2.length() ; i++){
        editor.add_character(10 * i + 5 , 10 , word2[i] , "Roman Times" , "#1234" , 15);
    }

    editor.render_document();
    return -1;
}