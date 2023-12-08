// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rkapadia

#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include "TreeNode.h"

class BinaryTree
{
	public:
		BinaryTree();
		BinaryTree(const BinaryTree * tree);
		virtual ~BinaryTree();
		TreeNode * getRoot();
		void setRoot(TreeNode * root);
		//TreeNode * insertBinaryTree(TreeNode * root, TreeNode * newNode);
		void insert(int data);
		TreeNode * insertNode(TreeNode * root, TreeNode * newNode);
		void inorder(TreeNode * root);
		void preorder(TreeNode * root);
		void postorder(TreeNode * root);
		
	private:
		TreeNode * root_;
};
#endif
