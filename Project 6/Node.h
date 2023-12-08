// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rkapadia
#ifndef NODE_H
#define NODE_H
#include "HashEntry.h"
class Node{
	public:
		Node(HashEntry entry);
		~Node() {}
		int getValue();
		void setValue(int data);
	private:
		int data_;
		HashEntry entry_;
	
	protected:
		Node(){}
		
	
};
#endif