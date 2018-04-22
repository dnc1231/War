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

#include<cstdlib>
#include<time.h>

#include "Deck.h"
//deck constructor
Deck::Deck(){
    Card card;
    for (int i = 0; i < 4; i++){
        for (int j = 1; j < 14; j++){
            card = Card(i,j);
            myDeck.push_back(card);
        }
    }
    top = 0;
    deckSize = myDeck.size();
}
//shuffles the deck by swapping two cards at random within the deck
void Deck::shuffle(){
    Card temp;
    srand(time(0));
    for (int i = 0; i < SHUFFLE; i++){
        int random1 = rand() % deckSize;
        int random2 = rand() % deckSize;
        temp = myDeck[random1];
        myDeck[random1] = myDeck[random2];
        myDeck[random2] = temp;
    }
}
//deals the top card from the deck
Card& Deck::dealCard(){
    Card &card = myDeck[top];
    top++;
    return card;
}
//returns the top index
int Deck::getTop(){
    return top;
}
//returns the deck size
int Deck::getDeckSize(){
    return deckSize;
}
//returns a string of the entire decks contents
string Deck::toString(){
    string string;
    for (int i = top; i < deckSize; i++){
        string.append(myDeck[i].toString());
        if (i != (deckSize - 1)){
            string.append("\n");
        }
    }
    return string;
}