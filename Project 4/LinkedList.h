// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rkapadia
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "LinkedNode.h"
#include <iostream>
class LinkedList: public LinkedNode
{
	public:
		LinkedList();
		LinkedList(LinkedList *other);
		~LinkedList();
		bool isEmpty();
		int getLength();
		void setLength(int L);
		LinkedNode * getHead();
		LinkedNode * getTail();
		void setHead(LinkedNode*node);
		void setTail(LinkedNode*node);
		void insert(int element);
		virtual void printList();
		
	protected:
		LinkedNode * head_;
		LinkedNode * tail_;
		int length_;

	
};
#endif