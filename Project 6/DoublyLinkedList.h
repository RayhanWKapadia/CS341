// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rkapadia
#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include "LinkedList.h"
class DoublyLinkedList: public LinkedList
{
	public:
		DoublyLinkedList();
		virtual ~DoublyLinkedList();
		void insertLinkedNode(LinkedNode *node, HashEntry entry);
		void deleteNode(int key);
		void printList();
		void printLL();
		int listSearch(int key);
		int valueSearch(int key);
		int listSearch2(int key);
		
		
};
#endif