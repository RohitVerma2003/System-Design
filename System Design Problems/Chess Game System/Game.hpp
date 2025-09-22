#include "./Board.hpp"
#include "Player.hpp"

class Game{
private:
    Player* white_player , black_player;
    Player* current_player;
    Board* board;
public:
    Game(): white_player(new Player("001" , Color::WHITE)) , black_player(new Player("002" , Color::BLACK)) , current_player(white_player) , board(new Board()){}

    Player* get_white_player();
    Player* get_black_player();
    Board* get_board();
    void make_move();
    bool is_valid_move();
    bool is_game_over();
    bool is_check_mate();
    bool is_draw();
    void make_resign(Player* by);
    bool is_check();
}