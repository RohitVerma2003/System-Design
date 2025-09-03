#include "CharacterFlyweight.hpp"
#include "CharcterGlyph.hpp"
#include <unordered_map>
#include <string>
using namespace std;

class CharacterFlyweightFactory{
private:
    unordered_map<string , CharacterFlyweight*> flyweight_map;
public:
    ~CharacterFlyweightFactory(){
        for(auto flyweight : this->flyweight_map) delete flyweight.second;
    }

    CharacterFlyweight* get_flyweight(char symbol , string font_family , string color , int font_size){
        string key = to_string(symbol) + font_family + color + to_string(font_size);

        if(this->flyweight_map.find(key) == this->flyweight_map.end()){
            this->flyweight_map[key] = new CharacterGlyph(symbol , font_family , color , font_size);
        }

        return this->flyweight_map[key];
    }

    int get_flyweight_size(){
        return this->flyweight_map.size();
    }
};