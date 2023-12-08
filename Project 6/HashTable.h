#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>

/**
 * @class HashTable
 *
 * Abstract Class
 */
class HashTable
{
	public:
		/// Constructor
		HashTable(){}
		
		/// Destructor
		virtual ~HashTable(){}
		
		/**
		 * Inserts a new Key,Value pairing into our Hash Table.
		 *
		 * @param[in]          Integer		key
		 * @param[in]          Integer		value
		 */
		virtual void insert(int key, int value) = 0;
		
		/**
		 * Searches for a Hash Entry, based upon the key 
		 * from our Hash Table.
		 *
		 * @param[in]          Integer		key
		 */
		virtual int search(int key) = 0;
		
		/**
		 * Removes a Hash Entry, based upon the key from our 
		 * Hash Table.
		 *
		 * @param[in]          Integer		key
		 */
		virtual void remove(int key) = 0;
		
		/**
		 * Prints the contents of our Hash Table.
		 */
		virtual void print() = 0;
		
};

#endif