#include "CharacterFlyweightFactory.hpp"
#include "RenderCharacter.hpp"
#include "CharcterGlyph.hpp"
#include "CharacterFlyweight.hpp"
#include <vector>
#include <string>
using namespace std;

class TextEditor{
private:
    CharacterFlyweightFactory factory;
    vector<RenderCharacter> documents;

public:
    void add_character(int x , int y , char ch , string font_family , string color , int font_size){
        CharacterFlyweight* glyph = factory.get_flyweight(ch , font_family , color , font_size);
        documents.push_back(RenderCharacter(glyph , x , y));
    }

    void render_document(){
        for(auto document : documents){
            document.render();
        }
    }
};