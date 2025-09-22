#include "./contants.hpp"
#include <string>
using namespace std;

class Piece{
private:
    Color color;
public:
    Piece(Color color): color(color){}
    
    string get_color(){
        return this->color;
    }
}