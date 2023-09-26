// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rkapadia
#include "card.h"
//This is the implementation of the card class.
std::string Card::SUIT[] = {"No Suit", "Spades", "Hearts", "Diamonds", "Clubs"};

std::string Card::FACE[] = {"Joker", "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

Card::Card()
{
	suitVal_=0;
	faceVal_=0;
}

Card::Card(int s, int f)
{
  initialize(s, f);
}

Card::~Card()
{

}

std::string Card::getSuit()
{
	return SUIT[suitVal_];
}

std::string Card::getFace()
{
	return FACE[faceVal_];
}

std::string Card::print() 
{
    if (suitVal_ == 0) 
    {
        return "Joker";
    } 
      
    else 
    {
        return FACE[faceVal_] + " of " + SUIT[suitVal_];
    }
}

void Card::initialize(int s, int f) 
{
    if (s >= 0 && s < 5 && f >= 1 && f <= 13) 
	{
        suitVal_ = s;
        faceVal_ = f;
    } 
    
    else {
        suitVal_ = 0;
        faceVal_ = 0;
    }
}