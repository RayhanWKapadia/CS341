// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rkapadia
#include "BinaryTree.h"
#include "TreeNode.h"
#include "RedBlackTree.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>

int main()
{
	//Create binary tree
	//BinaryTree * newTree = new BinaryTree();
	//TreeNode * newNode = new TreeNode(15);
	//newTree->setRoot(newNode);
	//std::cout << "Root: " << newTree->getRoot()->getValue() << std::endl;
	//Phase 1 - Read in a file
	/*
	int myVal=0;
		std::ifstream readFile;
		std::string fileinputName = "data.txt";
		readFile.open(fileinputName.c_str());
		if(readFile.fail())
		{
			std::cout<<"Failed to open given file"<<std::endl;
		}
		else
		{
			while(!readFile.eof())
			{
				readFile >> myVal;
				newTree->insert(myVal);
			}
		}
		readFile.close();
		std::cout<<"ROOT"<<std::endl;
		//3
		std::cout<<newTree->getRoot()->getValue()<<std::endl;
		//18
		std::cout<<newTree->getRoot()->getRightChild()->getValue()<<std::endl;
		//22
		std::cout<<newTree->getRoot()->getRightChild()->getRightChild()->getValue()<<std::endl;
		//29
		std::cout<<newTree->getRoot()->getRightChild()->getRightChild()->getRightChild()->getValue()<<std::endl;
		//7
		std::cout<<newTree->getRoot()->getRightChild()->getLeftChild()->getValue()<<std::endl;
		//10
		std::cout<<newTree->getRoot()->getRightChild()->getLeftChild()->getRightChild()->getValue()<<std::endl;
		//8
		std::cout<<newTree->getRoot()->getRightChild()->getLeftChild()->getRightChild()->getLeftChild()->getValue()<<std::endl;
		//15
		std::cout<<newTree->getRoot()->getRightChild()->getLeftChild()->getRightChild()->getRightChild()->getValue()<<std::endl;
		delete newTree;*/
	
		/*std::cout<<RB->getRoot()->getValue()<<std::endl;
		std::cout<<RB->getRoot()->getLeftChild()->getValue()<<std::endl;
		std::cout<<RB->getRoot()->getLeftChild()->getLeftChild()->getValue()<<std::endl;
		std::cout<<RB->getRoot()->getLeftChild()->getRightChild()->getValue()<<std::endl;
		std::cout<<RB->getRoot()->getLeftChild()->getRightChild()->getRightChild()->getValue()<<std::endl;
		
		
		std::cout<<RB->getRoot()->getRightChild()->getValue()<<std::endl;
		std::cout<<RB->getRoot()->getRightChild()->getLeftChild()->getValue()<<std::endl;
		std::cout<<RB->getRoot()->getRightChild()->getRightChild()->getValue()<<std::endl;
		std::cout<<RB->getRoot()->getRightChild()->getRightChild()->getRightChild()->getValue()<<std::endl;
		std::cout<<RB->getRoot()->getRightChild()->getRightChild()->getLeftChild()->getValue()<<std::endl;
		*/
		
		
		
		
		
		
		/*
		std::cout<<RB->getRoot()->getValue()<<std::endl;
		//std::cout<<RB->getRoot()->getValue()->getColor()<<std::endl;
		
		
		std::cout<<RB->getRoot()->getLeftChild()->getValue()<<std::endl;
				
		std::cout<<RB->getRoot()->getRightChild()->getValue()<<std::endl;
				
		std::cout<<RB->getRoot()->getRightChild()->getLeftChild()->getValue()<<std::endl;
		std::cout<<RB->getRoot()->getRightChild()->getLeftChild()->getRightChild()->getValue()<<std::endl;
		std::cout<<RB->getRoot()->getRightChild()->getLeftChild()->getLeftChild()->getValue()<<std::endl;
		
		
		
		std::cout<<RB->getRoot()->getRightChild()->getRightChild()->getValue()<<std::endl;
		std::cout<<RB->getRoot()->getRightChild()->getRightChild()->getRightChild()->getValue()<<std::endl;
		
		RB->preorder(RB->getRoot());
		*/
		
		
	//Phase 5 working for the binary search tree
	//3 18 7 10 22 8 15 29
	//More advanced testing
	//15 16 201 79 73 10 1 0 2 4
	
	RedBlackTree * RB = new RedBlackTree();
	int myVal=0;
	std::ifstream readFile;
	std::string fileinputName = "data.txt";
	readFile.open(fileinputName.c_str());
	if(readFile.fail())
	{
		std::cout<<"Failed to open given file"<<std::endl;
	}
	else
	{
		while(!readFile.eof())
		{
			readFile >> myVal;
			RB->insert(myVal);
		}
	}
	readFile.close();
	
	RB->printTree(RB->getRoot());
	std::cout<<"Red Nodes: ";
	RB->printRedNodes(RB->getRoot());
	
	std::cout<<"\nBlack Nodes: ";
	RB->printBlackNodes(RB->getRoot());

	std::cout<<"\nRoot: "<<RB->getRoot()->getValue()<<std::endl;
		
		delete RB;
return 0;
}
