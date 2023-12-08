// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rkapadia
#include "BinaryTree.h"
#include <iostream>
#include <string>
BinaryTree::BinaryTree() : root_ (nullptr)
{
}
BinaryTree::~BinaryTree()
{
	if (root_ != nullptr)
	{
		delete root_;
	}
}
void BinaryTree::setRoot(TreeNode * root)
{
	root_ = root;
}
TreeNode * BinaryTree::getRoot()
{
	return root_;
}
void BinaryTree::insert(int data)
{
	TreeNode * newNode = new TreeNode(data);
	root_=insertNode(root_, newNode);
	//getRoot()->setColor("black");
}
//Inserts a node into a binary search tree ensuring it is valid, but not balanced.
TreeNode * BinaryTree::insertNode(TreeNode * root, TreeNode * newNode)
{
	if (root == nullptr)
	{
		return newNode;
	}
	else
	{
		if(newNode->getValue()>root->getValue())
		{
			root->setRightChild(insertNode(root->getRightChild(), newNode));
			root->getRightChild()->setParent(root);
			
		}
		else if (newNode->getValue()<root->getValue())
		{
			root->setLeftChild(insertNode(root->getLeftChild(), newNode));
			root->getLeftChild()->setParent(root);
		}
		
	}
	return root;
}
//Done in class. Do not change.
//Prints the trees in the correct orders.
void BinaryTree::inorder(TreeNode * root)
{
	if(root==nullptr)
	{
		return;
	}
	inorder(root->getLeftChild());
	std::cout<<root->getValue()<<" ";
	inorder(root->getRightChild());
	
}
void BinaryTree::preorder(TreeNode * root)
{
	if(root==nullptr)
	{
		return;
	}
	std::cout<<root->getValue()<<" ";
	preorder(root->getLeftChild());
	preorder(root->getRightChild());
}
void BinaryTree::postorder(TreeNode * root)
{
	if(root==nullptr)
	{
		return;
	}
	postorder(root->getLeftChild());
	postorder(root->getRightChild());
	std::cout<<root->getValue()<<" ";	
}
