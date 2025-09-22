#include "./Player.hpp"

Player::Player(string name , Color color): name(name) , piece_color(color){}

string Player::get_name(){return this->name;}
Color Player::get_color(){return this->piece_color;}