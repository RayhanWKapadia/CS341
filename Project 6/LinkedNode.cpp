// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rkapadia
#include "LinkedNode.h"


LinkedNode::LinkedNode(HashEntry entry, LinkedNode *nextLinkedNode, LinkedNode *prevLinkedNode){
	entry_=entry;
	nextLinkedNode_=nextLinkedNode;
	prevLinkedNode_=prevLinkedNode;
}



LinkedNode::~LinkedNode(){
	if(nextLinkedNode_ != nullptr){
		delete nextLinkedNode_;
	}
}

LinkedNode * LinkedNode::getNextLinkedNode(){
	return nextLinkedNode_;
}

void LinkedNode::setNextLinkedNode(LinkedNode *node){
	nextLinkedNode_=node;
}

bool LinkedNode::hasNextLinkedNode(){
	bool nextLinkedNode(false);
	if(nextLinkedNode_!=nullptr){
		nextLinkedNode=true;
	}
	return nextLinkedNode;
	//return (nextLinkedNode_ !=nullptr);
}

LinkedNode * LinkedNode::getPrevLinkedNode(){
	return prevLinkedNode_;
}

void LinkedNode::setPrevLinkedNode(LinkedNode *node){
	prevLinkedNode_=node;
}

bool LinkedNode::hasPrevLinkedNode(){
	return (prevLinkedNode_ !=nullptr);
}

HashEntry LinkedNode::getEntry(){
	return entry_;
}