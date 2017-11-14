
// Created by Elad Aharon on 03/11/17.
// ID: 311200786
//

#ifndef EX02_HUMANPLAYER_H
#define EX02_HUMANPLAYER_H

#include "Point.h"
#include "Player.h"


class HumanPlayer : public Player{
public:
    HumanPlayer(char s);

    /**
     * Get the move from the user according to the rules of the game.
     * @return The valid input point from user.
     */
    virtual Point getMove();
};


#endif //EX02_HUMANPLAYER_H
