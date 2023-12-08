// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rkapadia
#ifndef HASHTABLECHAINING_H
#define HASHTABLECHAINING_H
#include "HashTable.h"
#include "HashEntry.h"
#include "DoublyLinkedList.h"

#include <iostream>

class HashTableChaining :public HashTable
{
	public:
		HashTableChaining(int size);		
		~HashTableChaining();
		void insert(int key, int value);
		int search(int key);
		void remove(int key);
		void print();
		int size_;
		int index_;
		//getters
		int getSize();
		bool hasSpace();
		//setters
		void setSize(int size);
	private:
		DoublyLinkedList * myEntry_;
		
};

#endif