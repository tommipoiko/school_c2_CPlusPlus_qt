#include "board.hh"
#include <iostream>
#include <string>
#include <vector>

/* Ristinolla
 *
 * Kuvaus:
 * Ohjelma kuvaa ristinollapeliä, jossa pelialuetta voi laajentaa.
 * Aluksi peliruutu on perinteinen 3x3-kokoinen. Pelilaudan ruuduilla voi
 * olla kolmenlaisia merkkejä: ristejä (X), nollia (0) tai tyhjää ( ).
 * Risti ja nolla pelaavat vuorotellen ristin aloitettua.
 * Ohjelma kysyy aina vuorossa olevalta maalta ruudun koordinaatteja ja
 * asettaa kyseiseen ruutuun oman maan merkin. Pelin voittaa ensimmäisenä
 * kokonaisen rivin, sarakkeen tai diagonaalin täyttävä maa.
 * Peli voi päättyä tilanteeseen, jossa lauta on täynnä, mutta kumpikaan
 * maa ei ole voittanut.
 * Ohjelma tarkistaa annetut koordinaatit ja ne saavat olla laudan sisällä
 * tai ylittää x- tai y-koordinaatit korkeintaan yhdellä. Tällöin lauta
 * laajenee oikealle ja alas. Jos koordinaatit alittavat laudan koordinaatit
 * korkeintaan yhdellä, pelilauta laajenee vasemmalle ja ylös.
 * Pelin päättyessä ohjelma kertoo ketä voitti tai voittiko ketään.
 *
 * Ohjelman kirjoittaja:
 * Tommi Poikolainen
 * 050093232
 * frtopo
 * tommi.poikolainen@tuni.fi
*/

bool check_command(Board& board, std::string x, std::string y, std::string player)
// Siirtää annetut koordinaatit ja pelaajan arvot tarkastettavaksi. Suorittaa asianmukaiset
// muutokset pelilautaan.
{
    while (true) {
        if (board.check_board(board, x, y) == true) {
            board.enter_to_board(x, y, player);
            return true;
        } else {
            return false;
        }
    }
}

void play_game(Board board)
// Ristinollapelin pääketju.
{
    int turn = 1;
    std::string command = "0 0";
    std::string player = "X";
    std::string x = "";
    std::string y = "";

    while (x != "q") {
        if (turn % 2 == 1) {
            player = "X";
        } else {
            player = "0";
        }
        std::cout << "For " << player << ", enter coordinates: x y> ";
        std::cin >> x;
        if (x == "q") {
            std::cout << "Why on earth you are giving up the game?" << std::endl;
            break;
        }

        std::cin >> y;

        if (check_command(board, x, y, player) == false) {
            continue;
        }

        if (board.check_win(player) == 1) {
            if (player == "X") {
                std::cout << "Cross won horizontally" << std::endl;
            } else {
                std::cout << "Nought won horizontally" << std::endl;
            }
            std::cout << "Game over!" << std::endl;
            return;
        } else if (board.check_win(player) == 2) {
            if (player == "X") {
                std::cout << "Cross won vertically" << std::endl;
            } else {
                std::cout << "Nought won vertically" << std::endl;
            }
            std::cout << "Game over!" << std::endl;
            return;
        } else if (board.check_win(player) == 3) {
            if (player == "X") {
                std::cout << "Cross won diagonally" << std::endl;
            } else {
                std::cout << "Nought won diagonally" << std::endl;
            }
            std::cout << "Game over!" << std::endl;
            return;
        } else if (board.check_win(player) == 4) {
            std::cout << "No empty places" << std::endl;
            std::cout << "Game over!" << std::endl;
            return ;
        }

        ++turn;
    }
}

int main()
// Pääohjelma käynnistää funktioketjun.
{
    Board board = Board();

    std::cout << "Start game:" << std::endl;
    board.print_board();
    std::cout << std::endl;

    play_game(board);

    return EXIT_SUCCESS;
}
