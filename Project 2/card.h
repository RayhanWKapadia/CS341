// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rkapadia
#ifndef CARD_H
#define CARD_H
//This is the basic header file for the card class.
#include <string>

/**
 * @class Card
 *
 * The Card class is an object that represents a single card in from a standard deck of cards.
 * 
 * It is mainly used to store and print the contents of a card. It also allows you to initialize in two ways:
 * 		1) Via the initialize method (that sets both values at once). 
 * 		2) Via a non-default constructor, if you happen to want to do it when you declare a Card instance.
 */

class Card {        
	public:
		/// Default constructor.
		Card();	

	  /**
	   * Initializing constructor.
	   *
	   * @param[in]      Suit
	   * @param[in]		 Face
	   */		
		Card(int, int);
		
		/// Destructor
		~Card();					
    	
		/**
		 * Returns the string corresponding to the suit of the card
		 *
		 * @return          Suit
		*/  
		std::string getSuit();	
		
		/**
	     * Returns the string corresponding to the face of the card
	     *
	     * @return          Face
	    */ 
		std::string getFace();		
        
		/**
	     * Returns a string with the full name of the card. (e.g., "Ace of Spades")
	     *
	     * @return          String
	    */ 
		std::string print();
		
		/**
	     * Initializes the Card with a Suit and Face value.
	     *
		 * @param[in]      Suit
	     * @param[in]	   Face
	    */
		void initialize(int, int);
		
	private:
		int suitVal_;				 // Index of the Suit array that corresponds to the Suit of the Card.
		int faceVal_;				 // Index of the Face array that corresponds to the Face of the Card.
		static std::string SUIT[5];  // Static array of Suit values.
		static std::string FACE[14]; // Static array of Face values.
};

#endif