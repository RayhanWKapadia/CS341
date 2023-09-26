// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rkapadia
#ifndef NON_STANDARD_DECK_H
#define NON_STANDARD_DECK_H
#include "deck.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
//This is the header file for the nonstandard deck.

/**
 * @class StandardDeck
 *
 * The StandardDeck class represents a standard deck of 52 cards.
 * 
 */
class NonStandardDeck: public Deck
{
	public:
		/// Default constructor.
		NonStandardDeck();
		
		/// Default destructor.
		~NonStandardDeck();

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

    bool mergeDecks(NonStandardDeck & otherDeck, bool);

    void initializeDeck();

    Card dealCard();

    Card getTop();
    Card getSecondFromTop();

    Card getThirdFromTop();

	
};

#endif
