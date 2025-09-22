#include "./Block.hpp"

Block::Block(int row , int col , Color color , Piece* piece): row(row) , col(col) , color(color) , piece(piece){}

Block::get_row(){return this->row;}
Block::get_col(){return this->col;}
Block::get_color(){return this->color;}
Block::get_piece(){return this->piece;}