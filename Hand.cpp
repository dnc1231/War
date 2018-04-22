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

#include "Hand.h"

using namespace std;
//constructor for hand class
Hand::Hand(){
    size = 0;
    top = 0;
    myHand.clear();
}
//getter for hand size
int Hand::getSize(){
    size = myHand.size();
    return size;
}
//returns a string of the entire hand
string Hand::toString(){
    string word;
    for (int i = top; i < size; i++){
        word.append(myHand[i].toString());
        word.append("\n");
    }
    return word;
}
//getter for top card index
int Hand::getTop(){
    return top;
}
//returns true if the deck is empty (if the top index is greater than or equal to the size)
bool Hand::isEmpty(){
    if (top >= size){
        return true;
    }
    return false;
}
//adds a card to the bottom of the hand
void Hand::addCard(Card& c){
    myHand.push_back(c);
    size = myHand.size();
}
//returns the next card and updates the top index
Card& Hand::getNext(){
    try{
        if(isEmpty()){
            string empty;
            throw (empty);
        }
        Card &c = myHand[top];
        top++;
        return c;
    }
    catch (string& empty){
        //print something?
    }
}