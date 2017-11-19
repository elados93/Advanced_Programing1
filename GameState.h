
// Created by Elad Aharon on 17/11/17.
// ID: 311200786

#ifndef EX02_GAMESTATE_H
#define EX02_GAMESTATE_H

#include "ReversiDefaultRules.h"
#include "Board.h"

class GameState {

public:
    GameState(Board *board1);
    GameState(GameState &gameState);

    virtual ~GameState();

    GameState& operator = (const GameState& copyGameState);

    friend class ReversiDefaultRules;
    friend class AIPlayer;
    friend class GameManager;

private:
    Board *board;
    vector<Point*> vec1; // Vector with all the possible points of player 1.
    vector<Point*> vec2; // Vector with all the possible points of player 2.
};


#endif //EX02_GAMESTATE_H
