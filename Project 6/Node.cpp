// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rkapadia
#include "Node.h"
Node::Node(HashEntry entry){
	entry_=entry;
}

int Node::getValue(){
	return data_;
}

void Node::setValue(int data){
	data_ = data;
}