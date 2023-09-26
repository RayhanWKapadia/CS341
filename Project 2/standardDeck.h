// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rkapadia
#ifndef STANDARD_DECK_H
#define STANDARD_DECK_H
#include "deck.h"
#include <cstdlib>
#include <iostream>

#define DECK_SIZE 52
//This is the header of the standard deck class.
/**
 * @class StandardDeck
 *
 * The StandardDeck class represents a standard deck of 52 cards.
 * 
 */
class StandardDeck: public Deck
{
	public:
		/// Default constructor.
		StandardDeck();
		
		/// Default destructor.
		~StandardDeck();

		/**
	     * Returns True/False (1/0) whether or not the Deck is empty.
	     *
	     * @return          Boolean
	    */ 
		bool isEmpty();

		/**
	     * Returns the number of cards remaining in the deck.
	     *
	     * @return          Integer		value
	    */ 
		int getNumCards();

		/**
	     * Displays the i'th card in the Deck.
	     *
		 * @param[in]      Index
	    */
		void displayCard(int i);

		/**
	     * Prints the contents of the Deck. This method should call the 
		 * print() method on each Card.
	    */
		void printDeck();

    bool addCard(Card c);

    void shuffle();

    bool mergeDecks(StandardDeck & otherDeck, bool);

    void initializeDeck();

    Card dealCard();

    Card getTop();
    Card getSecondFromTop();

    Card getThirdFromTop();
};

#endif
