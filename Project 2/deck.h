// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rkapadia
#ifndef DECK_H
#define DECK_H
#include <iostream>
#include "card.h"
//This is the header for the deck class and is important for implementation.
/**
 * @class Deck
 *
 * The Deck class represents a deck of cards.
 * 
 */
class Deck
{
public:
    /// Default constructor.
    Deck();

    /// Default destructor.
    virtual ~Deck();

    /**
     * Returns True/False (1/0) whether or not the Deck is empty.
     *
     * @return          Boolean
     */
    virtual bool isEmpty() = 0;  // Pure virtual method

    /**
     * Returns the number of cards remaining in the deck.
     *
     * @return          Integer     value
     */
    virtual int getNumCards() = 0;  // Pure virtual method

    /**
     * Displays the i'th card in the Deck.
     *
     * @param[in]      Index
     */
    virtual void displayCard(int i) = 0;  // Pure virtual method

    /**
     * Prints the contents of the Deck. This method should call the 
     * print() method on each Card.
     */
    virtual void printDeck() = 0;  // Pure virtual method

    virtual bool addCard(Card c) = 0;  // Pure virtual method

    virtual void shuffle() = 0;  // Pure virtual method

    virtual bool mergeDecks(Deck& deck, bool);  // Pure virtual method

    virtual void initializeDeck() = 0;  // Pure virtual method

    virtual Card dealCard() = 0;  // Pure virtual method

    virtual Card getTop() = 0;  // Pure virtual method
    virtual Card getSecondFromTop() = 0;  // Pure virtual method
    virtual Card getThirdFromTop() = 0;  // Pure virtual method
	
protected:
	Card * deck_;
	int numCards_;
	int capacity_;
};

#endif