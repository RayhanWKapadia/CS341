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
		DoublyLinkedList(DoublyLinkedList *other);
		~DoublyLinkedList();
		void insertLinkedNode(LinkedNode *node, int data);
		void insertAfterLinkedNode(LinkedNode *node, int data);
		void insertBeforeLinkedNode(LinkedNode *node, int data);
		void printList();
};
#endif