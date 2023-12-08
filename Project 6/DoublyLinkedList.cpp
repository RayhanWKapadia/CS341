// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rkapadia
#include "DoublyLinkedList.h"
#include <iostream>

DoublyLinkedList::DoublyLinkedList(): LinkedList() 
{
}



DoublyLinkedList::~DoublyLinkedList() {
	
	
}
void DoublyLinkedList::deleteNode(int key)
{
	if(key==getHead()->getEntry().getKey())
	{
		LinkedNode * myHead = getHead();
		if(myHead->getNextLinkedNode()==nullptr)
		{
			//Maybe try just make everything completely null;
			length_--;
			delete myHead;
			//LinkedNode* temp = nullptr;
			setHead(nullptr);
			setTail(nullptr);
		} 
		else
		{
			
			LinkedNode * newNode=getHead()->getNextLinkedNode();
			setHead(newNode);
			newNode->setPrevLinkedNode(nullptr);
			//Set the next linked Node
			myHead->setNextLinkedNode(nullptr);
			delete myHead;
			length_--;
		}
	}
	else if(getTail()->getEntry().getKey()==key)
	{		
		LinkedNode * myTail = getTail();
		//Set tail no need to set nullptr
		LinkedNode * newNode2=getTail()->getPrevLinkedNode();
		setTail(newNode2);
		newNode2->setNextLinkedNode(nullptr);
		//new addition
		myTail->setPrevLinkedNode(nullptr);
		delete myTail;
		length_--;
	}
	else
	{
		int holder=1;
		LinkedNode * temp =getHead()->getNextLinkedNode();
		while(temp!=getTail())
		{
			if(key==temp->getEntry().getKey())
			{
				holder=0;
				break;
			}
			temp=temp->getNextLinkedNode();
		}
		if(holder==0)
		{
			temp->getPrevLinkedNode()->setNextLinkedNode(temp->getNextLinkedNode());
			//Swapping the nodes!
			temp->getNextLinkedNode()->setPrevLinkedNode(temp->getPrevLinkedNode());
			temp->setPrevLinkedNode(nullptr);
			//testing this half
			temp->setNextLinkedNode(nullptr);
			delete temp;
			length_--;
			//std::cout<<"test2"<<std::endl;
		}
		else
		{
			std::cout<<"Key "<<key<<" not found!"<<std::endl;
		}
	}
}


void DoublyLinkedList::insertLinkedNode(LinkedNode *node, HashEntry entry)
{
	LinkedNode *AfterNode = new LinkedNode(entry, nullptr, nullptr);
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
		//Change the tail
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
void DoublyLinkedList::printLL()
{
	
	LinkedNode * temp = getHead();	
	//linkedNode*
	if(temp!=nullptr)
	{
		std::cout<<temp->getEntry().getKey();
	}
	while(temp!=nullptr)
	{
		temp=temp->getNextLinkedNode();
		//Temp points to nextnode
		
		if(temp!=nullptr)
		{
			std::cout<<"<-->"<<temp->getEntry().getKey();
		}
	}
	std::cout<<" "<<std::endl;
}

void DoublyLinkedList::printList(){
	LinkedNode *temp = head_;
	while(temp!=nullptr){
		if (temp==tail_)
		{
			std::cout<<temp->getEntry().getKey()<<std::endl;
			break;
		}
		//break statement above
			std::cout<<temp->getEntry().getKey()<<"<->";
			temp=temp->getNextLinkedNode();

		}
}
int DoublyLinkedList::listSearch(int key) {
    LinkedNode *temp = getHead();
	int holder=0;
    while (temp != nullptr && holder==0) 
	{
        if (temp->getEntry().getKey()==key) {
			holder=1;
        } else {
            temp = temp->getNextLinkedNode();
        }
    }
	if(holder==0)
	{
		//return a value
		return -1;
		std::cout<<"Doesn't exit"<<std::endl;
	}
  return key;
}


int DoublyLinkedList::valueSearch(int key) {
    LinkedNode *temp = getHead();
	int holder=0;
    while (temp != nullptr && holder==0) 
	{
        if (temp->getEntry().getKey()==key) {
			holder=1;
			return temp->getEntry().getValue();
        } 
		//Split between temp
		
		else {
            temp = temp->getNextLinkedNode();
        }
    }
	if(holder==0)
	{
		return -1;
		std::cout<<"Doesn't exit"<<std::endl;
	}
  return -1;
}


int DoublyLinkedList::listSearch2(int key) {
    LinkedNode *temp = getHead();
	int holder=0;
    while (temp != nullptr && holder==0) 
	{
        if (temp->getEntry().getKey()==key) {
			holder=1;
			//Must return a value here. Int
			return temp->getEntry().getKey();
        } else {
            temp = temp->getNextLinkedNode();
        }
    }
	if(holder==0)
	{
		return -1;
		std::cout<<"Doesn't exit"<<std::endl;
	}
  return key;
}











