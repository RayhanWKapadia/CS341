// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rkapadia
#ifndef HASHTABLEARRAY_H
#define HASHTABLEARRAY_H
#include "HashTable.h"
#include "HashEntry.h"

#include <iostream>

class HashTableArray :public HashTable
{
	public:
		HashTableArray(int size);		
		~HashTableArray();
		void insert(int key, int value);
		int search(int key);
		void remove(int key);
		void print();
		int size_;
		int index_;
		int selection;
		//getters
		int getSize();
		bool hasSpace();
		void setSelection(int val);
		//setters
		void setSize(int size);
		void clear();
		
	private:
		HashEntry * myEntry_;
		
};

#endif