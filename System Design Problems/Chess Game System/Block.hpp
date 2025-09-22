#include "./Piece.hpp"

class Block{
private:
    int row , col;
    Color color;
    Piece* piece;
public:
    Block(int row , int col , Color color , Piece* piece);
    
    int get_row();
    int get_col();
    Color get_color();
    Piece* get_piece();
}