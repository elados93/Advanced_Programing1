
// Created by Elad Aharon on 17/11/17.
// ID: 311200786
//

#include "GameState.h"

GameState::GameState(Board *board1) : board(board1) {}

GameState::GameState(GameState &gameState) {

    board = new Board(*gameState.board);

    for (unsigned int i = 0; i < gameState.vec1.size(); i++) {
        Point *pointToBeAdded = new Point(*gameState.vec1.at(i));
        this->vec1.push_back(pointToBeAdded);
    }

    for (unsigned int i = 0; i < gameState.vec2.size(); i++) {
        Point *pointToBeAdded = new Point(*gameState.vec2.at(i));
        this->vec2.push_back(pointToBeAdded);
    }

}

GameState::~GameState() {
    delete (board);

    for (unsigned int i = 0; i < vec1.size(); i++) {
        delete (vec1.at(i));
    }
    vec1.clear();

    for (unsigned int i = 0; i < vec2.size(); i++) {
        delete (vec2.at(i));
    }
    vec2.clear();

}

GameState &GameState::operator=(const GameState &copyGameState) {
    if (this != &copyGameState) {

        delete (board);

        for (unsigned int i = 0; i < vec1.size(); i++) {
            delete (vec1.at(i));
        }
        vec1.clear();

        for (unsigned int i = 0; i < vec2.size(); i++) {
            delete (vec2.at(i));
        }
        vec2.clear();

        board = new Board(*copyGameState.board);

        for (unsigned int i = 0; i < copyGameState.vec1.size(); i++) {
            Point *p = new Point(*copyGameState.vec1.at(i));
            vec1.push_back(p);
        }

        for (unsigned int i = 0; i < vec2.size(); i++) {
            Point *p = new Point(*copyGameState.vec2.at(i));
            vec2.push_back(p);
        }

    }

    return *this;
}
