// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rkapadia
#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <ostream>

#include "set.h"

// Defines the size of the dictionary.
#define DICTIONARY_SIZE 256

/**
 * @class Dictionary
 *
 * A Dictionary class that supports rank, select, rank_range, and select_range.
 *
 * Suppose that the bit b you are working with is 1. In that case:
 *		1) Rank tells you how many 1s there are in the range [i, j).
 *		2) Select finds the bit position of the kth 1 in the range [i,j).
 *
 * Suppose you have the following sequence of bits:
 *
 *			|01110100|01100101|01110011|01110100|
 * Rank: 17
 * Rank Range (15-31): 9
 * Select(5,1): 8
 * Select Range(0,15,2,1): 3
 */
class Dictionary {
	public:
        /// Constructor
        Dictionary();                                        
		
		/**
		* Copy constructor
		*
		* We need this since we have dynamically allocated
		* memory on this Class.
		*
		* @param[in]     dict         The source dictionary.
		*/
		Dictionary (const Dictionary & dict);
		
		/// Destructor
		~Dictionary();    

		/**
	     * Initializes the underlying BitArray with a character 
		 * array (word) and the size of the word (int).
	     *
		 * @param[in]      word		char *
	     * @param[in]	   size		int
	    */	
		void initialize(char * word, int size);
		
		/**
	     * Returns how many of the bit b are in the interval 
		 * [start,end).
	     *
		 * @param[in]	   int	start
		 * @param[in]	   int	end 
		 * @param[in]	   int	bit		DEFAULT 1
		 *
	     * @return          int
	    */ 
		int rank_range(int start, int end, int bit = 1);             
		
		/**
	     * Returns the position of the kth bit b in the 
		 * interval [start,end).
	     *
		 * @param[in]	   int	start
		 * @param[in]	   int	end 
		 * @param[in]	   int	k 
		 * @param[in]	   int	bit		DEFAULT 1
		 *
	     * @return          int
	    */ 
		int select_range(int start, int end, int k, int bit = 1);
		
		/**
	     * Returns how many of the bit b are in the interval 
		 * [0,end).
	     *
		 * @param[in]	   int	end 
		 * @param[in]	   int	bit		DEFAULT 1
		 *
	     * @return          int
	    */ 
		int rank(int end, int bit = 1);
		
		/**
	     * Returns the position of the kth bit b in the 
		 * interval [start,end).
	     *
		 * @param[in]	   int	k 
		 * @param[in]	   int	bit		DEFAULT 1
		 *
	     * @return          int
	    */ 
		int select(int k, int bit = 1);
		
		/**
	     * Uses an output stream to write the contents
		 * of the Lookup Table.
		 * You will need this in Phase V.
	     *
		 * @param[in]      std::ostream
	    */	
		void printLookupTable(std::ostream & output);
	
	protected:
		BitArray data_;	// Instance of a BitArray.
		int * lookupTable_;	// Lookup Table (Dynamically Allocated Array)
       
	private:
		// HELPER METHODS GO HERE.
		void initializeLookupTable();
}; 

#endif
