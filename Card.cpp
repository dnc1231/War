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
#include "Card.h"

using namespace std;
//constructor for empy argument card
Card::Card(){
    srand(time(0));
    int suit = rand() % 4;//random number 0 to 3
    int value = rand() % 14 + 1;//random number 1 to 13
    Card(suit, value);
}
//constructor for argument card
Card::Card(int suit, int value) {
    try {
        if ( suit < 0 || suit > 3 || value < 1 || value > 13 ){
            int exception;
            throw (exception);
        }
        this->suit = suit;
        this->value = value;
    }
    catch (int exception){
        //do something?
        //Card();
    }
}
//getter for suit
int Card::getSuit() {
    return suit;
}
//getter for card value
int Card::getValue() {
    if (value == 1){
        return 14;
    }
    else {
        return value;
    }/
}
//returns a string of the cards representation
string Card::toString() const {
    string card;
    if (this->value == ACE){
        card.append("Ace");
    }
    else if (this->value == 2){
        card.append("2");
    }
    else if (this->value == 3) {
        card.append("3");
    }
    else if (this->value == 4){
        card.append("4");
    }
    else if (this->value == 5) {
        card.append("5");
    }
    else if (this->value == 6){
        card.append("6");
    }
    else if (this->value == 7){
        card.append("7");
    }
    else if (this->value == 8){
        card.append("8");
    }
    else if (this->value == 9){
        card.append("9");
    }
    else if (this->value == 10){
        card.append("10");
    }
    else if (this->value == JACK){
        card.append("Jack");
    }
    else if (this->value == QUEEN){
        card.append("Queen");
    }
    else if (this->value == KING){
        card.append("King");
    }
    card.append(" of ");
    if (this->suit == CLUBS){
        card.append("Clubs");
    }
    else if (this->suit == DIAMONDS){
        card.append("Diamonds");
    }
    else if (this->suit == HEARTS){
        card.append("Hearts");
    }
    else if (this->suit == SPADES){
        card.append("Spades");
    }
    return card;
}
//returns a string of the cards suit
string Card::getSuitAsString() const{
    if (this->suit == CLUBS){
        return "Clubs";
    }
    else if (this->suit == DIAMONDS){
        return "Diamonds";
    }
    else if (this->suit == HEARTS){
        return "Hearts";
    }
    else{
        return "Spades";
    }
}
//returns a string of the cards value
string Card::getValueAsString() const{
    if (this->value == ACE){
        return "Ace";
    }
    else if (this->value == 2){
        return "2";
    }
    else if (this->value == 3) {
        return "3";
    }
    else if (this->value == 4){
        return "4";
    }
    else if (this->value == 5) {
        return "5";
    }
    else if (this->value == 6){
        return "6";
    }
    else if (this->value == 7){
        return "7";
    }
    else if (this->value == 8){
        return "8";
    }
    else if (this->value == 9){
        return "9";
    }
    else if (this->value == 10){
        return "10";
    }
    else if (this->value == JACK){
        return "Jack";
    }
    else if (this->value == QUEEN){
        return "Queen";
    }
    else{
        return "King";
    }
}
//checks if the cards are the same suit
bool Card::sameSuit(Card& other){
    if (this->suit == other.getSuit()){
        return true;
    }
    else return false;
}
//checks if the cards are the same value
bool Card::sameValue(Card& other){
    if (this->value == other.getValue()){
        return true;
    }
    else return false;
}
//checks if the two cards are the same, == overload
bool operator ==(Card& c1, Card& c2){
    if (c1.sameSuit(c2) && c1.sameValue(c2)){
        return true;
    }
    else return false;
}
//outputs the card to the output, << overload
ostream& operator <<(ostream& output, const Card& c){
    output << c.toString();
}