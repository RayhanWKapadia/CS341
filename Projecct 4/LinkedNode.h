// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
#ifndef LINKEDNODE_H
#define LINKEDNODE_H
#include "Node.h"
class LinkedNode : public Node{
	public:
		//LinkedNode();
		LinkedNode(int data, LinkedNode *nextLinkedNode, LinkedNode *prevLinkedNode);
		LinkedNode(LinkedNode *other);
		~LinkedNode();
		LinkedNode *getNextLinkedNode();
		LinkedNode *getPrevLinkedNode();
		void setNextLinkedNode(LinkedNode *nextLinkedNode);
		void setPrevLinkedNode(LinkedNode *prevLinkedNode);
		bool hasNextLinkedNode();
		bool hasPrevLinkedNode();
		int getData();
		void setData(int d);
		
	protected:
		LinkedNode(){}
	private:
		int data_;
		LinkedNode *nextLinkedNode_;
		LinkedNode *prevLinkedNode_;

};

#endif