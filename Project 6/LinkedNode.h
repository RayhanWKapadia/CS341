// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
#ifndef LINKEDNODE_H
#define LINKEDNODE_H
#include "Node.h"
#include "HashEntry.h"
class LinkedNode : public Node{
	public:
		LinkedNode(HashEntry entry, LinkedNode *nextLinkedNode, LinkedNode *prevLinkedNode);
		LinkedNode(const LinkedNode * other);
		//LinkedNode(LinkedNode *other);
		~LinkedNode();
		LinkedNode *getNextLinkedNode();
		LinkedNode *getPrevLinkedNode();
		void setNextLinkedNode(LinkedNode *nextLinkedNode);
		void setPrevLinkedNode(LinkedNode *prevLinkedNode);
		bool hasNextLinkedNode();
		bool hasPrevLinkedNode();
		int getData();
		void setData(int d);
		HashEntry getEntry();
		
	protected:
		LinkedNode(){}
	private:
		int data_;
		LinkedNode *nextLinkedNode_;
		LinkedNode *prevLinkedNode_;
		HashEntry entry_;

};

#endif