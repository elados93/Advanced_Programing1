// Created by Elad Aharon on 28/10/17.
// ID: 311200786

#include "Board.h"
#include "ReversiDefaultRules.h"
#include "HumanPlayer.h"
#include "ConsolePrinter.h"
#include "GameManager.h"
#include "AIPlayer.h"
#include "iostream"

using namespace std;

int main() {

    Board *board = new Board(4, 4);
    GameState gameState1(board);
    ReversiDefaultRules *gameRules = new ReversiDefaultRules();
    cout << "Welcome to Reversi Game! :)" << endl;
    cout << "Please choose 1 for a game VS the computer or 2 for a game Vs a Human Player" << endl;
    int inputAIGameOrNot;
    bool aiPlayerSwitch = false;

    do {
        cin >> inputAIGameOrNot;
        switch (inputAIGameOrNot) {
            case 1:
                aiPlayerSwitch = true;
                break;
            case 2:
                aiPlayerSwitch = false;
                break;
            default:
                break;
        }
    } while ((inputAIGameOrNot != 1) && (inputAIGameOrNot != 2));

    HumanPlayer p1('x');
    AIPlayer pAI('o', *gameRules);
    HumanPlayer p3('o');

    if (aiPlayerSwitch) {// a game VS the computer
        ConsolePrinter printer(*board, p1, pAI);
        GameManager game(gameState1, p1, pAI, printer, *gameRules, aiPlayerSwitch);
        game.run(); // Run the game.
    } else {// playing Reversi with two Human players
        ConsolePrinter printer(*board, p1, p3);
        GameManager game(gameState1, p1, p3, printer, *gameRules, aiPlayerSwitch);
        game.run(); // Run the game.
    }

    delete (gameRules);
    return 0;
}