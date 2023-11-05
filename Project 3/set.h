// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rkapadia
#ifndef SET_H
#define SET_H

#include "bitarray.h"

/**
 * @class Set
 *
 * The Set class represents the mathematical concept of a set, where the universe of items corresponds
 * to a BitArray within the class. The presence of a 1 in the given index indicates that the number is
 * is a member of the set - if the value is 0, the number is not a member of the set.
 */
class Set {
    public:
		/**
		 * Initializing constructor. Builds a BitArray
		 * instance of 'size.'
		 *
		 * @param[in]      size		int		DEFAULT = 0
		*/
		Set(int size = 0);                           

		/// Destructor
		~Set();                                  
	   
		/**
	     * Initializes the underlying BitArray with a
		 * character array (word) and the size of the
		 * word (int).
	     *
		 * @param[in]      word		char *
	     * @param[in]	   size		int
	    */
	    void initialize(char * word, int size);

		/**
	     * Returns the cardinality of the set - here the 
		 * cardinality is represented by the number of 1's
		 * in the underlying BitArray.
		 *
		 * const - We will not change the underlying BitArray.
	     *
	     * @return          int
	    */ 
		int getCardinality() const;
	   
		/**
	     * Returns a reference to the underyling BitArray data_
	     *
	     * @return          BitArray &
	    */ 
		BitArray & getData();                 

		/**
	     * Computes the Union of "this" set (A) and B.
		 * 
		 * A = A U B	(A.setUnion(B);)
		 *
		 * Returns TRUE if successful - false is unable.
	     *
		 * @param[in]	   Set &
		 *
	     * @return          bool
	    */ 
		bool setUnion(Set & B);
		
		/**
	     * Computes the Intersection of "this" set (A) and B.
		 * 
		 * A = A X B	(A.setIntersection(B);)
		 *
		 * Returns TRUE if successful - false is unable.
	     *
		 * @param[in]	   Set &
		 *
	     * @return          bool
	    */ 
		bool setIntersection(Set & B);
	   
	protected:
       BitArray data_;	// Instance of a BitArray. 
};

#endif
