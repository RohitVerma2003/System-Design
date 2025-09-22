#include "./contants.hpp"
#include <string>
using namespace std;

class Player{
private:
    string name;
    Color piece_color;
public:
    Player(string name , Color color);
    string get_name();
    Color get_color();
}