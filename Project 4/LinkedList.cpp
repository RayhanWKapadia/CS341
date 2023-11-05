// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rkapadia
#include "LinkedList.h"
#include <iostream>
LinkedList::LinkedList(){
	tail_=nullptr;
	head_=nullptr;
	length_=0;
}

LinkedList::~LinkedList(){
	if(head_!=nullptr){
		delete head_;
	}
}

LinkedList::LinkedList(LinkedList *other) :length_(other->getLength()), tail_(other->getTail()), head_(other->getHead()){
	
}

bool LinkedList::isEmpty(){
	if(length_==0){
		std::cout<<"true"<<std::endl;
		return true;
	}
	else{
		std::cout<<"false"<<std::endl;
		return false;
	}
}

int LinkedList::getLength(){
	return length_;
}
void LinkedList::setLength(int L){
	length_=L;
}

void LinkedList::insert(int element){
	LinkedNode * newLinkedNode= new LinkedNode(element, nullptr, nullptr);
	if(head_==nullptr){
		head_=newLinkedNode;
		tail_=newLinkedNode;
		length_=length_+1;
	}
	else{
		tail_->setNextLinkedNode(newLinkedNode);
		tail_ = newLinkedNode;
		length_=length_+1;
	}
}

void LinkedList::printList(){
	LinkedNode *temp = head_;
	std::cout<<temp->getValue()<< "->";
	while(temp!=nullptr){
		temp = temp->getNextLinkedNode();
		if(temp!=nullptr){
			if (temp==tail_)
			{
				std::cout<<temp->getValue()<<std::endl;
				break;
			}
				std::cout<<temp->getValue()<<"->";
			
		}
	}
}

LinkedNode * LinkedList::getTail(){
	return tail_;
}

LinkedNode * LinkedList::getHead(){
	return head_;
}

void LinkedList::setHead(LinkedNode * node){
	head_=node;
}

void LinkedList::setTail(LinkedNode * node){
	tail_=node;
}