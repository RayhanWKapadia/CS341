// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rkapadia
#include "Node.h"
Node::Node(int val) : data_(val)
{
}
int Node::getValue()
{
	return data_;
}
void Node::setValue(int val)
{
	data_ = val;
}
