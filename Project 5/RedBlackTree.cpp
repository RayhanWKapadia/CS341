// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rkapadia
#include "RedBlackTree.h"
#include <iostream>
#include <string>
RedBlackTree::RedBlackTree() : BinaryTree(){
}

RedBlackTree::~RedBlackTree(){

}

//Inserts into the node. You do not need anything else. It should also used the binary tree class.
void RedBlackTree::insert(int data){
	TreeNode * newNode = new TreeNode(data);
	setRoot(insertNode(getRoot(),newNode));
	TreeNode * myRoot = getRoot();
	balanceColor(myRoot, newNode);
	getRoot()->setColor("black");
}

//Rptates the tree rightwards. The function is also private
void RedBlackTree::rotateRight(TreeNode *& root, TreeNode *& newNode){
	//TreeNode * holder = newNode->getRightChild();
	TreeNode * holder = newNode->getLeftChild();
	newNode->setLeftChild(holder->getRightChild());
	
	//if(newNode->getLeftChild()!=nullptr&&newNode!=root)
	if(newNode->getLeftChild()!=nullptr){
		newNode->getLeftChild()->setParent(newNode);
	}

	holder->setParent(newNode->getParent());
	
	if(newNode->getParent()==nullptr){
		root = holder;
		setRoot(root);
	}

	else if(newNode->getParent()->getLeftChild()==newNode){
		
		newNode->getParent()->setLeftChild(holder);
	}
	
	else{
		newNode->getParent()->setRightChild(holder);
	}
	
	newNode->setParent(holder);
	
	holder->setRightChild(newNode);
}

//Rotate the tree leftwards. The function is also private.
void RedBlackTree::rotateLeft(TreeNode *& root, TreeNode *& newNode){
	
	TreeNode * holder = newNode->getRightChild();
	//newNode->setRightChild(root);
	newNode->setRightChild(holder->getLeftChild());
	
	if(newNode->getRightChild()!=nullptr){
		
		newNode->getRightChild()->setParent(newNode);
	}

	holder->setParent(newNode->getParent());
	
	if(newNode->getParent()==nullptr){
		//Changes the root of the tree
		root = holder;
		//Should swap it
		setRoot(root);
	}
	
	else if(newNode->getParent()->getLeftChild()==newNode){
		newNode->getParent()->setLeftChild(holder);
	}
	else{
		newNode->getParent()->setRightChild(holder);
	}
	newNode->setParent(holder);
	holder->setLeftChild(newNode);
	
}
//This function will serve to balance any issues regarding color. 
void RedBlackTree::balanceColor(TreeNode *& root, TreeNode *& newNode){
	std::string myColor="empty";
	TreeNode * newNodeParent = nullptr, *newNodeGrandParent=nullptr;
	/*
	if(newNode!=root)
	{
		return;}
	*/
	//while(newNode->getParent()->getColor()=="red" && newNode->getColor() !="black" )
	//	while(newNode!=root        &&    newNode->getColor() !="black"     &&         newNode->getParent()->getColor()=="red"){
	while(newNode!=root && newNode->getParent()->getColor()=="red" && newNode->getColor() !="black" ){
		//grandparent=newNode->getParent()->getParent();
		newNodeGrandParent = newNode->getParent()->getParent();
		newNodeParent = newNode->getParent();
		
		if(newNodeParent ==newNodeGrandParent->getLeftChild()){
			TreeNode * newNodeParentSibling = newNodeGrandParent->getRightChild();
			
			
			if(newNodeParentSibling != nullptr && newNodeParentSibling->getColor()=="red"){
				
				//change 
				/*newNodeParentSibling->setColor("black");
				newNodeGrandParent->setColor("red");
				newNodeParent->setColor("black");*/
				
				changeColors(newNodeParentSibling, newNodeGrandParent, newNodeParent, newNode);
				//newnode->setColor("black")
				//newNode->setnewNodeParent->setColor("black");
				newNode=newNodeGrandParent;
			}
			else{
				
				if(newNode==newNodeParent->getRightChild()){
					rotateLeft(root,newNodeParent);
					//Rotate left because the newnode is the right child
					newNode=newNodeParent;
					newNodeParent=newNode->getParent();
				}
				
				else{
					//rotateRight(root,newNodeParent)
					rotateRight(root, newNodeGrandParent);
					//myColor="black"
					myColor=newNodeParent->getColor();
					newNodeParent->setColor(newNodeGrandParent->getColor());
					newNodeGrandParent->setColor(myColor);
					newNode=newNodeParent;	
				}
			}
		}
		else{
			TreeNode * newNodeParentSibling = newNodeGrandParent->getLeftChild();
			//if(newNodeParentSibling != nullptr &&newNodeParentSibling->getColor()=="red"){
			if(newNodeParentSibling != nullptr && newNodeParentSibling->getColor()=="red"){
				//newNodeParentSibling("red");
				//newNodeGrandParent->setColor("black");
				//newNodeParent->setColor("");
				newNodeParentSibling->setColor("black");
				newNodeGrandParent->setColor("red");
				newNodeParent->setColor("black");
				newNode=newNodeGrandParent;
			}
			
			else{
				if(newNode==newNodeParent->getLeftChild()){
					rotateRight(root,newNodeParent);
					//Must rotate right here because the leftchild is the same as the newNode
					newNode=newNodeParent;
					newNodeParent=newNode->getParent();
				}
				
				else{
					//rotateRight(root, newNodeGrandParent)
					rotateLeft(root, newNodeGrandParent);
					//myColor="black"
					myColor=newNodeParent->getColor();
					newNodeParent->setColor(newNodeGrandParent->getColor());
					//newNodeParent->setColor("black")
					newNodeGrandParent->setColor(myColor);
					//newNodeGrandParent->setColor("black")
					newNode=newNodeParent;
				}
			}
		}
	}
}

//Uses pre order to bring the entire tree. Everything is given!
void RedBlackTree::printTree(TreeNode * newNode)
{
	if(newNode==nullptr)
	{
		return;
	}
	if(newNode->getColor()=="black")
	{
		std::cout<<"Black: "<<newNode->getValue()<<" "<<std::endl;
	}
	else if(newNode->getColor()=="red")
	{
		std::cout<<"Red: "<<newNode->getValue()<<" "<<std::endl;
		
	}
	printTree(newNode->getLeftChild());
	printTree(newNode->getRightChild());
}

//Prints the tree in-order
void RedBlackTree::printRedNodes(TreeNode * root)
{
	if(root==nullptr)
	{
		return;
	}
	printRedNodes(root->getLeftChild());
		if(root->getColor()=="red")
		{
			std::cout<<root->getValue()<<" ";
		}
		printRedNodes(root->getRightChild());

}
//Prints the tree pre-order
void RedBlackTree::printBlackNodes(TreeNode * root)
{
	if(root==nullptr)
	{
		return;
	}
		if(root->getColor()=="black")
		{
			std::cout<<root->getValue()<<" ";
		}
		printBlackNodes(root->getLeftChild());
		printBlackNodes(root->getRightChild());

}
void RedBlackTree::changeColors(TreeNode * newNodeParentSibling, TreeNode * newNodeGrandParent, TreeNode * newNodeParent, TreeNode * newNode)
{

		newNodeParentSibling->setColor("black");
		newNodeGrandParent->setColor("red");
		newNodeParent->setColor("black");
		newNode=newNodeGrandParent;
}
















