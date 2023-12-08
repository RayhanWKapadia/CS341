// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rkapadia

#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H
#include "BinaryTree.h"

class RedBlackTree: public BinaryTree
{
	public:
		RedBlackTree();
		RedBlackTree(const RedBlackTree * tree);
		virtual ~RedBlackTree();
		virtual void insert(int data);
		void printTree(TreeNode * newNode);
		void printRedNodes(TreeNode * root);
		void printBlackNodes(TreeNode * root);
		
	private:
		void rotateLeft(TreeNode *& root, TreeNode *& newNode);
		void rotateRight(TreeNode *& root, TreeNode *& newNode);	
		void changeColors(TreeNode * newNodeParentSibling, TreeNode * newNodeGrandParent, TreeNode * newNodeParent, TreeNode * newNode);
		void balanceColor(TreeNode *& root, TreeNode *& newNode);
			
};

#endif
