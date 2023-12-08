// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rkapadia

#ifndef TREE_NODE_H
#define TREE_NODE_H
#include "Node.h"
#include <string>

class TreeNode : public Node
{
	public:
		TreeNode(int data);
		//TreeNode(TreeNode * node const);
		virtual ~TreeNode();
		// Getters/Setters
		void setParent(TreeNode * parent);
		void setLeftChild(TreeNode * leftChild);
		void setRightChild(TreeNode * rightChild);
		TreeNode * getParent();
		TreeNode * getLeftChild();
		TreeNode * getRightChild();
		std::string getColor();
		void setColor(std::string mycolor);
		TreeNode * getParentSib(TreeNode * particularNode);
		
		
		
	protected:
		TreeNode();
	private:
		TreeNode * parent_;
		TreeNode * leftChild_;
		TreeNode * rightChild_;
		std::string color_;
};
#endif
