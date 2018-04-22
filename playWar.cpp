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

#include<iostream>

#include "Deck.h"
#include "Hand.h"

using namespace std;
void war(Hand &player1Hand, Hand &player2Hand, Hand &player1Table, Hand &player2Table, int &wars, string &whoLost);

int main() {
    Hand player1Hand;
    Hand player2Hand;
    Hand player1Table;
    Hand player2Table;
    Deck deck;
    deck.shuffle();
    for(int i = 0; i < deck.getDeckSize()/2 ; i++) {//deals the entirety of the deck with even indexed cards going to player 1 and odd indexed cards to player 2
        player1Hand.addCard(deck.dealCard());
        player2Hand.addCard(deck.dealCard());
    }
    cout <<  "Hand of Player 1:" << endl << player1Hand.toString() << endl;
    cout << "Hand of Player 2:" << endl << player2Hand.toString() << endl;
    int round = 0;
    int wars = 0;
    string whoLost;//creates a string whoLost in case a player loses during a war to be edited then
    while ((round < 5000) && (!player1Hand.isEmpty()) && (!player2Hand.isEmpty()) && (whoLost.empty())){//sets 5000 turn limit and continues war until either player is out of cards in their hand
        round++;
        Card player1Card = player1Hand.getNext();
        Card player2Card = player2Hand.getNext();
        if (player1Card.getValue() > player2Card.getValue()){
            player1Hand.addCard(player1Card);
            player1Hand.addCard(player2Card);
        }
        else if (player1Card.getValue() < player2Card.getValue()){
            player2Hand.addCard(player2Card);
            player2Hand.addCard(player1Card);
        }
        else{//if the card values are equal, begin a war
            wars++;
            player1Table.addCard(player1Card);//adds the cards to the 'table' hands to keep track which cards have been played and in what order
            player2Table.addCard(player2Card);
            war(player1Hand, player2Hand, player1Table, player2Table, wars, whoLost);//calls the war helper function for wars
        }
    }
    if ((player1Hand.isEmpty() && !player2Hand.isEmpty()) || whoLost == "Player1"){//print statements for any of the win/draw conditions
        cout << "Player 1 lost after " << round << " rounds." << endl;
        cout << "There were " << wars << " wars" << endl;
    }
    else if ((player2Hand.isEmpty() && !player1Hand.isEmpty()) || whoLost == "Player2"){
        cout << "Player 2 lost after " << round << " rounds." << endl;
        cout << "There were " << wars << " wars" << endl;
    }
    else if (whoLost == "Draw"){
        cout << "Both players ran out of cards at the same time during a war. It is a draw." << endl;
        cout << "There were " << round << " rounds and " << wars << " wars" << endl;
    }

    else{
        cout << "The game was a draw after 5000 rounds." << endl;
        cout << "There were " << wars << " wars" << endl;

    }
}

void war(Hand &player1Hand, Hand &player2Hand, Hand &player1Table, Hand &player2Table, int &wars, string &whoLost){
    if (!player1Hand.isEmpty() && !player2Hand.isEmpty()) {//before adding the face down card, checks if either player is empty
        player1Table.addCard(player1Hand.getNext());//addds the face down card to the table
        player2Table.addCard(player2Hand.getNext());
        if (!player1Hand.isEmpty() && !player2Hand.isEmpty()) {//before flipping over the card, checks if now either player is empty
            Card temp1 = player1Hand.getNext();
            Card temp2 = player2Hand.getNext();
            if (temp1.getValue() == temp2.getValue()) {//if the cards have equal value, call war again with an updated war count and adding the cards to the table hands
                player1Table.addCard(temp1);
                player2Table.addCard(temp2);
                wars++;
                war(player1Hand, player2Hand, player1Table, player2Table, wars, whoLost);
            } else if (temp1.getValue() > temp2.getValue()) {//if player 1 wins, adds player 1s table cards and then player 2s table cards to his hand
                player1Table.addCard(temp1);
                player2Table.addCard(temp2);
                while (!player1Table.isEmpty()) {
                    player1Hand.addCard(player1Table.getNext());
                }
                while (!player2Table.isEmpty()) {
                    player1Hand.addCard(player2Table.getNext());
                }
            }
            else {//opposite if player 2 wins
                player1Table.addCard(temp1);
                player2Table.addCard(temp2);
                while (!player2Table.isEmpty()) {
                    player2Hand.addCard(player2Table.getNext());
                }
                while (!player1Table.isEmpty()) {
                    player2Hand.addCard(player1Table.getNext());
                }
            }
        }
    }
    if (player1Hand.isEmpty() && !player2Hand.isEmpty()){//if either of the players ran out of cards , changes the whoLost string to that player to be checked in the main loop
        whoLost = "Player1";
    }
    else if (player2Hand.isEmpty() && !player1Hand.isEmpty()){
        whoLost = "Player2";
    }
    else if (player2Hand.isEmpty() && player1Hand.isEmpty()){
        whoLost = "Draw";
    }
}