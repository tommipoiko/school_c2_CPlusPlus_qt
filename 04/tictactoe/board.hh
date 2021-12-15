#ifndef BOARD_HH
#define BOARD_HH
#include <iostream>
#include <string>
#include <vector>

class Board
{
public:
    Board();
    void print_board();
    bool check_board(Board& board, std::string x, std::string y);
    void enter_to_board(std::string x, std::string y, std::string player);
    int check_win(std::string player);
    void expand_dr();
    void expand_ul();

private:
    std::vector< std::vector < std::string > > x_coord_;
    std::vector< std::string > y_coord_;
};

#endif // BOARD_HH
