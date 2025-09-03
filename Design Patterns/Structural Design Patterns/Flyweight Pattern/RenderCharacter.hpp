#include "CharacterFlyweight.hpp"

class RenderCharacter{
private:
    CharacterFlyweight* glyph;
    int x , y;
public:
    RenderCharacter(CharacterFlyweight* glyph , int x , int y): glyph(glyph) , x(x) , y(y){}

    void render(){
        this->glyph->draw(this->x , this->y);
    }
};
