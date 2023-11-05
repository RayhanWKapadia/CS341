// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rkapadia
#ifndef BITARRAY_H
#define BITARRAY_H

#include <iostream>

// ONLY TO BE USED FOR PRINT METHOD!
#include <bitset>

// We want to define the size of a byte.
#define BIT_IN_BYTE 8

/**
 * @class BitArray
 *
 * The BitArray class represents an integer element as a single bit
 * in a long character array of bits. The idea is that the number 15, 
 * for example, is represented as either 0 (not in the bit array) or 
 * 1 (in the bit array). The value of such a data structure is to save 
 * space used. A normal int typically requires 32 bits, but we are now
 * "storing" each number in just one bit.
 */
class BitArray 
{
	public:
		/**
		 * Initializing constructor.
		 *
		 * @param[in]      size		int		DEFAULT = 0
		*/
		BitArray(int size = 0);                      
		
		/**
		* Copy constructor
		*
		* We need this because we have dynamically allocated
		* memory on this Class.
		*
		* const - We will NOT change the source BitArray.
		*
		* @param[in]     array         The source BitArray.
		*/
		BitArray(const BitArray & array);
		
		/// Destructor
		~BitArray();                             
		
		/**
	     * Sets all of the bits to 0.
	    */
		void clear(); 

		/**
	     * Initializes the BitArray with a character array 
		 * (word) and the size of the word (int).
	     *
		 * @param[in]      word		char *
	     * @param[in]	   size		int
	    */		
		void initialize(char * word, int size);
		
		/**
	     * Prints the bits within the BitArray.
		 *
		 * e.g., |01110100|01100101|01110011|01110100|
	    */
		void print();

		/**
	     * Returns the length of the BitArray in terms
		 * of bits.
		 *
		 * inline - Compiler Optimization
		 *
		 * const - We will not change the LENGTH.
	     *
	     * @return          int
	    */ 
		inline int length() const { return LENGTH; }
		
		/**
	     * Returns the number of bytes of the BitArray.
		 *
		 * inline - Compiler Optimization
		 *
		 * const - We will not change the BYTES.
	     *
	     * @return          int
	    */ 
		inline int bytes() const { return BYTES; }

		/**
	     * Returns TRUE if the bit at the specified position
		 * is set (1), FALSE otherwise.
		 *
		 * const - We will NOT change the value of the bit.
	     *
		 * @param[in]	   int
		 *
	     * @return          bool
	    */ 
		bool get(int position) const; 
		
		/**
	     * Sets a bit value (default: 1) at the specified position.
		 * Returns TRUE if successful - FALSE otherwise.
		 *
		 * YOU CANNOT USE THE bool get(int position) const METHOD HERE!
		 *
		 * @param[in]	   int
		 *
	     * @return          bool
	    */
		bool set(int position, int bit = 1);
		
		/**
	     * Flips the bit at the specified position: 1->0, 0->1.
		 * Returns TRUE if successful - FALSE otherwise.
		 *
		 * YOU CANNOT USE THE bool get(int position) const METHOD HERE!
		 *
		 * @param[in]	   int
		 *
	     * @return          bool
	    */
		bool flip(int position); 

		/**
	     * Flips the 1's and 0's in the BitArray.
	    */
		void complement(); 
		
		/**
	     * Returns the character in the byte (8 bits)
		 * within the BitArray given a specified position.
		 *
		 * const - We will NOT change the value.
	     *
		 * @param[in]	   int
		 *
	     * @return          char
	    */ 
		char get8(int position) const;
			
		/**
	     * Sets the character in given byte with a specified
		 * index for the character array.
		 *
		 * NOTE: You will not "need" this method until Phase III.
	     *
		 * @param[in]	   character
		 * @param[in]	   int
	    */ 
		void set8(char c, int index);
		
	protected:
		int LENGTH;	// Length of BitArray in terms of bits.
		int BYTES; // Number of bytes required for BitArray.
		char * data_; // Bit Array
		
	private:
		// HELPER METHODS GO HERE
};

#endif
