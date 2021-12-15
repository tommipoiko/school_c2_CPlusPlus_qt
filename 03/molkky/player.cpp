#include "player.hh"
#include <iostream>
#include <string>

Player::Player():
    name_("")
{

}

Player::Player(std::string name)
{
    name_ = name;
    points_ = 0;
}

std::string Player::get_name()
{
    return name_;
}

void Player::add_points(int pts)
{
    int temporary = 0;
    temporary = points_ + pts;
    if (temporary <= 50) {
        points_ += pts;
    } else {
        points_ = 25;
    }
}

bool Player::has_won()
{
    if (points_ == 50) {
        return true;
    } else {
        return false;
    }
}

int Player::get_points()
{
    return points_;
}
