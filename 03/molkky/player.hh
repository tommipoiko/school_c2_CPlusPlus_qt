#ifndef PLAYER_HH
#define PLAYER_HH
#include <iostream>
#include <string>

class Player
{
public:
    Player();
    Player(std::string name);
    std::string get_name();
    void add_points(int pts);
    bool has_won();
    int get_points();

private:
    std::string name_;
    int points_;

};

#endif // PLAYER_HH
