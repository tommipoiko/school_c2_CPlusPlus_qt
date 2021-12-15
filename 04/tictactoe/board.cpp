#include "board.hh"
#include <iostream>
#include <string>
#include <vector>

Board::Board()
{
    int rnd = 0;
    while (rnd < 3) {
        y_coord_.push_back(".");
        ++rnd;
    }

    rnd = 0;
    while (rnd < 3) {
        x_coord_.push_back(y_coord_);
        ++rnd;
    }
}

void Board::print_board()
// Tulostaa laudan sen nykyisessä tilassaan.
{
    std::string xline = "";
    int xrnd = 0;
    int yrnd = 0;
    int xwidth = x_coord_.size();
    int yheight = y_coord_.size();
    while (yrnd <= yheight) {
        xline = "";
        while (xrnd <= xwidth) {
            if (yrnd == 0) {
                if (xrnd == 0) {
                    xline += " ";
                } else {
                    xline += " ";
                    xline += std::to_string(xrnd%10);
                }
            } else {
                if (xrnd == 0) {
                    xline += std::to_string(yrnd%10);
                } else {
                    xline += " ";
                    xline += x_coord_.at(xrnd-1).at(yrnd-1);
                }
            }

            ++xrnd;
        }
        std::cout << xline << std::endl;

        ++yrnd;
        xrnd = 0;
    }
}

bool Board::check_board(Board& board, std::string x, std::string y)
// Tarksitaa annettujen arvojen kelpoisuus. Palauttaa pääohjelmaan kieltävän tai
// jatkamista kertovan totuusarvon.
{
    for (char merkki : x) {
        if (isdigit(merkki) == false) {
            std::cout << "Coordinate outside the board" << std::endl;
            return false;
        }
    }
    for (char merkki : y) {
        if (isdigit(merkki) == false) {
            std::cout << "Coordinate outside the board" << std::endl;
            return false;
        }
    }
    int x_size = x_coord_.size()+1;
    int y_size = y_coord_.size()+1;
    if ((stoi(x) < x_size && stoi(y) < y_size) && (stoi(x) > 0 && stoi(y) > 0)) {
        if (x_coord_.at(stoi(x)-1).at(stoi(y)-1) != ".") {
            std::cout << "The given place is already occupied" << std::endl;
            return false;
        }
        return true;
    } else if (stoi(x) == 0 or stoi(y) == 0) {
        if (stoi(x) < x_size and stoi(y) < y_size) {
            board.expand_ul();
        } else {
            std::cout << "Coordinate outside the board" << std::endl;
            return false;
        }
    } else if ((stoi(x) == x_size and stoi(y) < y_size) or (stoi(x) < x_size and stoi(y) == y_size) or (stoi(x) == x_size and stoi(y) == y_size)) {
        board.expand_dr();
    } else if (stoi(x) > x_size or stoi(y) > y_size) {
        std::cout << "Coordinate outside the board" << std::endl;
        return false;
    } else if ((stoi(x) == 0 and stoi(y) > y_size) or (stoi(x) > x_size and stoi(y) == 0)) {
        std::cout << "Coordinate outside the board" << std::endl;
        return false;
    } else {
        return false;
    }
    return true;
}

void Board::enter_to_board(std::string x, std::string y, std::string player)
// Lisää pelaajan ikonin lautaan.
{
    if (stoi(x) > 0 && stoi(y) > 0) {
        x_coord_.at(stoi(x)-1).at(stoi(y)-1) = player;
    } else if (stoi(x) > 0 && stoi(y) == 0) {
        x_coord_.at(stoi(x)).at(stoi(y)) = player;
    } else if (stoi(x) == 0 && stoi(y) > 0) {
        x_coord_.at(stoi(x)).at(stoi(y)) = player;
    } else if (stoi(x) == 0 && stoi(y) == 0) {
        x_coord_.at(stoi(x)).at(stoi(y)) = player;
    }
    print_board();
    std::cout << std::endl;
}

int Board::check_win(std::string player)
// Tarkistaa voittotilanteen.
{
    int h_ctr = 0;
    int v_ctr = 0;
    int d_ctr = 0;
    int full = 0;

    int vrnd = 0;
    int hrnd = 0;
    int drnd = 0;

    int h_length = x_coord_.size();
    int v_length = y_coord_.size();
    int d_length = x_coord_.size();
    int full_length = h_length * v_length;

    while (vrnd < v_length) {
        h_ctr = 0;
        hrnd = 0;
        while (hrnd < h_length) {
            if (x_coord_.at(hrnd).at(vrnd) == player) {
                ++h_ctr;
                ++full;
            }
            if (h_ctr == h_length) {
                return 1;
            }
            if (full == full_length) {
                return 4;
            }
            ++hrnd;
        }
        ++vrnd;
    }

    hrnd = 0;

    while (hrnd < h_length) {
        v_ctr = 0;
        vrnd = 0;
        while (vrnd < v_length) {
            if (x_coord_.at(hrnd).at(vrnd) == player) {
                ++v_ctr;
                ++full;
            }
            if (v_ctr == v_length) {
                return 2;
            }
            if (full == full_length) {
                return 4;
            }
            ++vrnd;
        }
        ++hrnd;
    }

    while (drnd < d_length) {
        if (x_coord_.at(drnd).at(drnd) == player) {
            ++d_ctr;
        }
        if (d_ctr == d_length) {
            return 3;
        }
        ++drnd;
    }

    d_ctr = 0;
    drnd = h_length-1;
    int second = 0;

    while (drnd >= 0) {
        if (x_coord_.at(drnd).at(second) == player) {
            ++d_ctr;
        }
        if (d_ctr == d_length) {
            return 3;
        }
        --drnd;
        ++second;
    }

    return 5;
}

void Board::expand_dr()
// Laajentaa lautaa tarvittaessa oikealle alas.
{
    int xrnd = 0;
    int width = x_coord_.size();

    while (xrnd < width) {
        x_coord_.at(xrnd).push_back(".");
        ++xrnd;
    }

    int rnd = 0;
    std::vector < std::string > temp;
    while (rnd < width+1) {
        temp.push_back(".");
        ++rnd;
    }

    y_coord_ = temp;
    x_coord_.push_back(y_coord_);

}

void Board::expand_ul()
// Laajentaa lautaa tarvittaessa vasemmalle ylös.
{
    int xrnd = 0;
    int width = x_coord_.size();

    while (xrnd < width) {
        x_coord_.at(xrnd).insert(x_coord_.at(xrnd).begin(), ".");
        ++xrnd;
    }

    int rnd = 0;
    std::vector < std::string > temp;
    while (rnd < width+1) {
        temp.insert(temp.begin(), ".");
        ++rnd;
    }

    y_coord_ = temp;
    x_coord_.insert(x_coord_.begin(), y_coord_);
}
