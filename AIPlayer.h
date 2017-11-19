
// Created by Elad Aharon on 14/11/17.
// ID: 311200786
//

#include "Player.h"
#include "GameRules.h"
#include "GameState.h"

#ifndef EX02_AIPLAYER_H
#define EX02_AIPLAYER_H


class AIPlayer : public Player {

public:
    AIPlayer(char s, GameRules &gameRules1);
    Point getMove(GameState &gameState);
    char getSymbol() const;

private:
    GameRules &gameRules;
    char symbol;

    int playDemo(GameState &demoGame);
};



#endif //EX02_AIPLAYER_H
