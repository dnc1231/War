// EE 312 Project 10 -- The Game of War

/* Student information for project:
 *
 * On my honor, Daniel Canterino, this programming project is my own work
 * and I have not provided this code to any other student.
 *
 * Name: Daniel Canterino
 * email address: dnc1231@verizon.net
 * UTEID: djc3323
 * Section 5 digit ID: 16115
 * Number of slip days used on this assignment. 0
 */

#ifndef _DECK_H
#define _DECK_H

#include<string>
#include<vector>
#include "Card.h"

int const SHUFFLE = 5000;

using namespace std;

class Deck {
private:
    vector<Card> myDeck;
    int top;
    int deckSize;
public:
    Deck();
    void shuffle();
    Card& dealCard();
    int getTop();
    int getDeckSize();
    string toString();
};

#endif
