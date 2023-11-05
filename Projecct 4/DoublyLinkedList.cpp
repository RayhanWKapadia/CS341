// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rkapadia
#include "DoublyLinkedList.h"
#include <iostream>

DoublyLinkedList::DoublyLinkedList(): LinkedList() {
}



DoublyLinkedList::~DoublyLinkedList() {
	
	
}

void DoublyLinkedList::insertLinkedNode(LinkedNode *node, int data)
{
	insertAfterLinkedNode(node, data);
}

void DoublyLinkedList::insertBeforeLinkedNode(LinkedNode*node, int data){
	LinkedNode *BeforeNode = new LinkedNode(data, nullptr, nullptr);
	if(node==nullptr)
	{
		head_=BeforeNode;
		tail_=BeforeNode;
	}
	else if(node->getPrevLinkedNode()==nullptr)
	{
		BeforeNode->setNextLinkedNode(node);
		node->setPrevLinkedNode(BeforeNode);
		head_=BeforeNode;
		
	}
	else if(node->getPrevLinkedNode()==nullptr && node->getNextLinkedNode()==nullptr)
	{
		BeforeNode->setNextLinkedNode(node);
		node->setPrevLinkedNode(BeforeNode);
		head_=BeforeNode;
		tail_=node;
	}
	else
	{
		node->getPrevLinkedNode()->setNextLinkedNode(BeforeNode);
		BeforeNode->setPrevLinkedNode(node->getPrevLinkedNode());
		node->setPrevLinkedNode(BeforeNode);
		BeforeNode->setNextLinkedNode(node);	
	}
	length_++;
}

void DoublyLinkedList::insertAfterLinkedNode(LinkedNode*node, int data){
	LinkedNode *AfterNode = new LinkedNode(data, nullptr, nullptr);
	if(node==nullptr)
	{
		tail_=AfterNode;
		head_=AfterNode;
	}
	else if(node->getNextLinkedNode()==nullptr)
	{
		AfterNode->setPrevLinkedNode(node);
		node->setNextLinkedNode(AfterNode);
		tail_=AfterNode;
		AfterNode->setNextLinkedNode(nullptr);
	}
	else if(node->getNextLinkedNode()==nullptr && node->getPrevLinkedNode()==nullptr)
	{
		AfterNode->setPrevLinkedNode(node);
		node->setNextLinkedNode(AfterNode);
		tail_=AfterNode;
		AfterNode->setNextLinkedNode(nullptr);
		head_=node;
	}
	else
	{
		AfterNode->setNextLinkedNode(node->getNextLinkedNode());
		AfterNode->setPrevLinkedNode(node);
		node->getNextLinkedNode()->setPrevLinkedNode(AfterNode);
		node->setNextLinkedNode(AfterNode);
	}
	length_++;
	
}

void DoublyLinkedList::printList(){
	LinkedNode *temp = head_;
	while(temp!=nullptr){
		if (temp==tail_)
		{
			std::cout<<temp->getValue()<<std::endl;
			break;
		}

			std::cout<<temp->getValue()<<"<->";
			temp=temp->getNextLinkedNode();

		}
}


