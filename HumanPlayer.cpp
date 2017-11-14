
// Created by Elad Aharon on 03/11/17.
// ID: 311200786
//

#include <iostream>
#include <limits>
#include "HumanPlayer.h"
using namespace std;

HumanPlayer :: HumanPlayer(char s) {
    this->symbol = s;
};

Point HumanPlayer::getMove() {
    int x,y;

    while (true) {
        cout << "Enter a number: ";
        cin >> x >> y;

        if (!cin.fail()) {
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
            return Point(x - 1, y - 1);
        }

        // user didn't input a number
        cout << "Please enter numbers only." << endl;
        cin.clear(); // reset failbit
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
    }
}




