// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rkapadia
//This is the parent class of this entire game. It runs everything and serves as the basis.
#include "deck.h"

Deck::Deck() 
{
}

Deck::~Deck() 
{
}

bool Deck::isEmpty() 
{
    return (getNumCards() == 0);
}

int Deck::getNumCards() 
{

    return 0;
}

void Deck::displayCard(int i) 
{
}

void Deck::printDeck() 
{
}

bool Deck::addCard(Card c)
{
    return false;
}

void Deck::shuffle() 
{
}

bool Deck::mergeDecks(Deck& otherDeck, bool) 
{
    return false;
}

void Deck::initializeDeck() 
{
}

Card Deck::dealCard() 
{
    return Card(); 
}

Card Deck::getTop() 
{
    return Card(); 
}

Card Deck::getSecondFromTop() 
{
    return Card(); 
}

Card Deck::getThirdFromTop() 
{
    return Card(); 
}