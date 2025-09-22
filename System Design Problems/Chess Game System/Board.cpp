#include "./Board.hpp"

Board::Board(){
    this->board.resize(8 , vector<int>(8 , nullptr));
    Color block_color = Color::BLACK;

    for(int i = 0 ; i < 8 ; i++){
        for(int j = 0 ; j < 8 ; j++){
            board[i][j] =  new Block(i , j , block_color , nullptr);
            
            if(block_color == Color::BLACK) block_color = Color::WHITE;
            else block_color = Color::BLACK;
        }
    }

    //SET PIECES
}