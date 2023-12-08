// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rkapadia
#ifndef HASHTABLECUCKOO_H
#define HASHTABLECUCKOO_H
#include "HashTable.h"
#include "HashEntry.h"
#include "DoublyLinkedList.h"

#include <iostream>

class HashTableCuckoo :public HashTable
{
	public:
		HashTableCuckoo(int size);		
		~HashTableCuckoo();
		void insert(int key, int value);
		int search(int key);
		void remove(int key);
		void print();
		int size_;
		int index_;
		//getters
		int getSize();
		int runningCount;
		bool hasSpace();
		//setters
		void setSize(int size);
		int firstHashFunction(int key);
		int secondHashFunction(int key);
		void resizeArrays(int newSize);
		
	private:
		HashEntry * firstHashArray;
		HashEntry * secondHashArray;
		
		
		
};

#endif