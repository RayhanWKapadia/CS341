// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rkapadia
#include "TreeNode.h"
TreeNode::TreeNode() : Node(), parent_(nullptr), leftChild_(nullptr), rightChild_(nullptr)
{
	
}
TreeNode::TreeNode(int data) : Node(data), parent_(nullptr), leftChild_(nullptr), rightChild_(nullptr), color_("red")
{
	
}
TreeNode::~TreeNode()
{
	if (leftChild_ != nullptr)
	{
		delete leftChild_;
	}
	if (rightChild_ != nullptr)
	{
		delete rightChild_;
	}
}
void TreeNode::setParent(TreeNode * parent)
{
	parent_ = parent;
}
void TreeNode::setLeftChild(TreeNode * leftChild)
{
	leftChild_ = leftChild;
}
void TreeNode::setRightChild(TreeNode * rightChild)
{
	rightChild_ = rightChild;
}
TreeNode * TreeNode::getParent()
{
	return parent_;
}
TreeNode * TreeNode::getLeftChild()
{
	return leftChild_;
}
TreeNode * TreeNode::getRightChild()
{
	return rightChild_;
}
std::string TreeNode::getColor()
{
	return color_;
}
void TreeNode::setColor(std::string mycolor)
{
	color_=mycolor;
}

TreeNode * TreeNode::getParentSib(TreeNode * particularNode)
{
	return leftChild_;
}


