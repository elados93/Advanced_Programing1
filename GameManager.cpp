
// Created by Elad Aharon on 03/11/17.
// ID: 311200786
//

#include <iostream>
#include "GameManager.h"

using namespace std;


GameManager::GameManager(Board &board, Player &player1, Player &player2, Printer &printer,
                         GameRules &gameRules) : board(board), player1(player1),
                                                                            player2(player2), printer(printer),
                                                                            gameRules(gameRules),
                                                                            currentPlayer() {
    this->currentPlayer = &this->player1;
    this->lastMove = NULL;
    this->firstRun = true;
}

owner GameManager::getWinner() const {
    int p1Counter = 0, p2Counter = 0;
    int row = board.getRow();
    int col = board.getCol();

    for(int i = 0;i < row;i++) {
        for(int j = 0;j < col;j++) {
            Point p(i, j);
            if (board.getCell(p).getSymbol() == PLAYER_1) {
                p1Counter++;
            } else {
                p2Counter++;
            }
        }
    }
    if (p1Counter > p2Counter) {
        return PLAYER_1;
    }

    if (p1Counter < p2Counter) {
        return PLAYER_2;
    }

    return NONE;
}

status GameManager::checkStatus() {
    gameRules.makePossibleMoves(PLAYER_1);
    gameRules.makePossibleMoves(PLAYER_2);

    bool isFirstEmpty = gameRules.getPossibleMoves(PLAYER_1).empty();
    bool isSecondEmpty = gameRules.getPossibleMoves(PLAYER_2).empty();

    if (board.isBoardFull() || (isFirstEmpty && isSecondEmpty) ) {
        owner result = getWinner();
        if (result == NONE) {
            return DRAW;
        } else {
            return WIN;
        }
    }

    return RUNNING;
}

void GameManager :: run() {
    status status1 = checkStatus();

    while (status1 == RUNNING) {
        playOneTurn();
        if (currentPlayer == &player1) {
            currentPlayer = &player2;
        } else {
            currentPlayer = &player1;
        }
        status1 = checkStatus();
    }

    printer.printBoard();
    delete(lastMove);

    if (checkStatus() == WIN) {
        owner winner = getWinner();
        if (winner == PLAYER_1) {
            printer.printEndOfGame(player1, status1);
        }

        if (winner == PLAYER_2) {
            printer.printEndOfGame(player2, status1);
        }

        char dummy;
        cin >> dummy;
    }

    if (status1 == DRAW) {
        printer.printEndOfGame(player1, DRAW);
    }
}

void GameManager::playOneTurn() {
    printer.printBoard();
    possible_outcome result;

    vector <Point*> playerPossibleMoves;
    if (currentPlayer == &player1) {
        playerPossibleMoves = gameRules.getPossibleMoves(PLAYER_1);
    } else {
        playerPossibleMoves = gameRules.getPossibleMoves(PLAYER_2);
    }

    // If there isn't moves just get a dummy character.
    if (playerPossibleMoves.empty()) {
        printer.printNextPlayerMove(*currentPlayer, playerPossibleMoves);
        char dummy; // Input any key from the user
        cin >> dummy;

        if (lastMove != NULL) {
            delete(lastMove);
        }

        lastMove = NULL;
        return;
    }

    if (firstRun) {

        // The first turn in the game player1 play.
        printer.printNextPlayerMove(player1, playerPossibleMoves);

        if (lastMove != NULL) {
            delete(lastMove);
        }
        // Get a point from the player.
        lastMove = new Point(player1.getMove());
        result = gameRules.makeMove(*lastMove, PLAYER_1);
        firstRun = false;

    } else {

        if (currentPlayer == &player1) {

            // Player 1 turn.
            printer.printLastMove(player2, lastMove);
            if (lastMove != NULL) {
                delete(lastMove);
            }

            printer.printNextPlayerMove(player1, playerPossibleMoves);
            lastMove = new Point (player1.getMove());
            result = gameRules.makeMove(*lastMove, PLAYER_1);

        } else {
            // Player 2 turn.
            printer.printLastMove(player1, lastMove);
            if (lastMove != NULL) {
                delete(lastMove);
            }

            printer.printNextPlayerMove(player2, playerPossibleMoves);
            lastMove = new Point(player2.getMove());
            result = gameRules.makeMove(*lastMove, PLAYER_2);

        }

    }

    if (result != SUCCESS) {
        inputUntilValid(result);
    }
}

void GameManager::inputUntilValid(possible_outcome result) {
    owner currentP;

    if (currentPlayer == &player1) {
        currentP = PLAYER_1;
    } else {
        currentP = PLAYER_2;
    }

    while (result != SUCCESS) {
        printer.printError(result);
        if (lastMove != NULL) {
            delete(lastMove);
        }
        lastMove = new Point(currentPlayer->getMove());
        result = gameRules.makeMove(*lastMove, currentP);
    }
}




