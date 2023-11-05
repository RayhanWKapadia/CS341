// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rkapadia
#include <iostream>
#include <string>
#include "Node.h"
#include "LinkedNode.h"
#include "LinkedList.h"
#include "DoublyLinkedList.h"
#include <fstream>
#include <stdlib.h>

int main(){
	//Phase 1
	std::cout<<"\nPhase 1: "<<std::endl;
	Node * node10 = new Node(7);
	Node * node20 = new Node(10);
	Node * node30 = new Node(15);
	node20->setValue(4);
	std::cout<<"Value of node 2: "<<node20->getValue()<<std::endl;

	//Phase 2
	std::cout<<"\nPhase 2: "<<std::endl;
	LinkedNode * nodeone = new LinkedNode(5, nullptr, nullptr);
	LinkedNode * node2 = new LinkedNode(10, nullptr, nullptr);
	LinkedNode * node3 = new LinkedNode(15, nullptr, nullptr);
	std::cout<<"Does nodeone have a next linkednode? "<<nodeone->hasNextLinkedNode()<<std::endl;
	nodeone->setNextLinkedNode(node2);
	node2->setNextLinkedNode(node3);
	LinkedNode * current = nodeone;
	while(current != nullptr){
		std::cout<<"Value "<<current->getValue()<<std::endl;
		current = current->getNextLinkedNode();		
	}
	
	
	//Phase 3
	std::cout<<"\nPhase 3: "<<std::endl;
	LinkedList * myList = new LinkedList();
	std::cout<<"EMPTY? "<<myList->isEmpty()<<std::endl;
	myList->insert(10);
	myList->insert(20);
	myList->insert(50);
	std::cout<<"HEAD VALUE "<<myList->getHead()->getData()<<std::endl;
	std::cout<<"TAIL VALUE "<<myList->getTail()->getData()<<std::endl;
	std::cout<<"LENGTH: "<<myList->getLength()<<std::endl;
	std::cout<<"EMPTY? "<<myList->isEmpty()<<std::endl;
	myList->printList();
	
	//Phase 4
	std::cout<<"\nPhase 4: "<<std::endl;
	DoublyLinkedList * myDoublyList = new DoublyLinkedList();
	std::cout<<"EMPTY? "<<myDoublyList->isEmpty()<<std::endl;
	//LinkedNode * node1 = new LinkedNode(3, nullptr, nullptr);
	//myDoublyList->setHead(node1);
	//myDoublyList->setTail(node1);
	myDoublyList->insertAfterLinkedNode(nullptr, 100);
	//myDoublyList->setLength(1);
	myDoublyList->insertAfterLinkedNode(myDoublyList->getHead(), 3);
	myDoublyList->insertAfterLinkedNode(myDoublyList->getTail(), 3);
	myDoublyList->insertAfterLinkedNode(myDoublyList->getHead(), 3);
	myDoublyList->insertAfterLinkedNode(myDoublyList->getHead(), 3);
	myDoublyList->insertAfterLinkedNode(myDoublyList->getHead(), 3);
	myDoublyList->insertBeforeLinkedNode(myDoublyList->getHead(), 3);
	
	
	myDoublyList->insertLinkedNode(myDoublyList->getHead(), 1000);
	myDoublyList->insertLinkedNode(myDoublyList->getTail(), 2000);
	std::cout<<"HEAD VALUE "<<myDoublyList->getHead()->getData()<<std::endl;
	std::cout<<"TAIL VALUE "<<myDoublyList->getTail()->getData()<<std::endl;
	std::cout<<"LENGTH: "<<myDoublyList->getLength()<<std::endl;
	std::cout<<"EMPTY? "<<myDoublyList->isEmpty()<<std::endl;
	myDoublyList->printList();
	
	DoublyLinkedList * myDoublyList2 = new DoublyLinkedList();
	myDoublyList2->insertBeforeLinkedNode(nullptr, 100);
	myDoublyList2->insertAfterLinkedNode(myDoublyList2->getHead(), 3);
	myDoublyList2->insertAfterLinkedNode(myDoublyList2->getTail(), 3);
	myDoublyList2->insertAfterLinkedNode(myDoublyList2->getHead(), 3);
	myDoublyList2->insertAfterLinkedNode(myDoublyList2->getHead(), 3);
	myDoublyList2->insertAfterLinkedNode(myDoublyList2->getHead(), 3);
	myDoublyList2->insertBeforeLinkedNode(myDoublyList2->getHead(), 3);
	
	
	myDoublyList2->insertLinkedNode(myDoublyList2->getHead(), 1000);
	myDoublyList2->insertLinkedNode(myDoublyList2->getTail(), 2000);
	std::cout<<"HEAD VALUE "<<myDoublyList2->getHead()->getData()<<std::endl;
	std::cout<<"TAIL VALUE "<<myDoublyList2->getTail()->getData()<<std::endl;
	std::cout<<"LENGTH: "<<myDoublyList2->getLength()<<std::endl;
	std::cout<<"EMPTY? "<<myDoublyList2->isEmpty()<<std::endl;
	myDoublyList2->printList();
	
	delete node10;
	delete node20;
	delete node30;
	delete nodeone;
	delete myList;
	delete myDoublyList;
	delete myDoublyList2;	
		
	
	
	//Phase 5 and running program
	DoublyLinkedList *mdl=new DoublyLinkedList;
	mdl->setLength(1);
	int totalCounts(0);
	int countHops=0;
	std::ifstream readFile;
	std::string fileinputName = "";
	std::ofstream fileoutput;
	std::string fileoutputName = "";
	std::cout<<"Enter file name!"<<std::endl;
	std::cin>>fileinputName;
	readFile.open(fileinputName.c_str());
	if(readFile.fail())
	{
		std::cout<<"Please enter in a valid file!"<<std::endl;
		std::cin>>fileinputName;
		readFile.open(fileinputName.c_str());
		int loop=0;
		while(readFile.fail()&& loop==0)
		{
			std::cout<<"Please enter in a valid file!"<<std::endl;
			std::cin>>fileinputName;
			readFile.open(fileinputName.c_str());
			if(readFile.fail())
			{
				loop=0;
			}
			else
			{
				loop=1;
			}
		}
		int myVal(0);
		readFile >> myVal;
		LinkedNode * node1 = new LinkedNode(myVal, nullptr, nullptr);
		mdl->setHead(node1);
		mdl->setTail(node1);
		while(!readFile.eof())
		{
			readFile >> myVal;
			mdl->insertAfterLinkedNode(node1, myVal);
			node1=node1->getNextLinkedNode();
		}
		mdl->printList();
	}
	else
	{
		int myVal(0);
		readFile >> myVal;
		LinkedNode * node1 = new LinkedNode(myVal, nullptr, nullptr);
		mdl->setHead(node1);
		mdl->setTail(node1);
		while(!readFile.eof())
		{
			readFile >> myVal;
			mdl->insertAfterLinkedNode(node1, myVal);
			node1=node1->getNextLinkedNode();
		}
		mdl->printList();
		std::cout<<"LENGTH: "<<mdl->getLength()<<std::endl;
		
	}
	readFile.close();
	
	std::cout<<"\nGive me a file to insert into your DLL!"<<std::endl;
	std::cin>>fileinputName;
	readFile.open(fileinputName.c_str());
	if(readFile.fail())
	{
		std::cout<<"Please enter in a valid file!"<<std::endl;
		std::cin>>fileinputName;
		readFile.open(fileinputName.c_str());
		int loop=0;
		while(readFile.fail()&& loop==0)
		{
			std::cout<<"Please enter in a valid file!"<<std::endl;
			std::cin>>fileinputName;
			readFile.open(fileinputName.c_str());
			if(readFile.fail())
			{
				loop=0;
			}
			else
			{
				loop=1;
			}
		}
		int insertVal(0);
		while(!readFile.eof())
		{
			//std::cout<<"WHILE LOOP"<<std::endl;
			LinkedNode *head = mdl->getHead();
			LinkedNode *tail = mdl->getTail();
			LinkedNode *tempPtr = mdl->getHead();
			LinkedNode *tempPtr2 = mdl->getTail();
			int headCount(0);
			int exit=0;
			int tailCount(0);
			readFile >> insertVal;
			//std::cout<<insertVal<<std::endl;
			if(insertVal<=head->getData())
			{
				//std::cout<<"Head value:"<<head->getData()<<std::endl;
				headCount++;
				mdl->insertBeforeLinkedNode(head, insertVal);	
			}
			else if(insertVal>=tail->getData())
			{
				//std::cout<<"Tail value:"<<tail->getData()<<std::endl;
				tailCount++;
				mdl->insertAfterLinkedNode(tail, insertVal);	
			}
			else
			{
				int con1=0;
				int con2=0;
				while (insertVal >= tempPtr->getData() || insertVal <= tempPtr2->getData()) 
				{
				    if (insertVal >= tempPtr->getData()) 
					{
				        tempPtr = tempPtr->getNextLinkedNode();
				       // std::cout << "tempPtr: " << tempPtr->getData() << std::endl;
				        headCount++;
				    }

				    if (insertVal <= tempPtr2->getData()) 
					{
				  
				        tempPtr2 = tempPtr2->getPrevLinkedNode();
				        //std::cout << "tempPtr2: " << tempPtr2->getData() << std::endl;
				        tailCount++;
				    }
					
			        if (insertVal < tempPtr->getData()) 
					{
					    //std::cout << "Insert "<<insertVal<< " before: " << tempPtr->getData() << std::endl;
					    mdl->insertBeforeLinkedNode(tempPtr, insertVal);
					    totalCounts = totalCounts + headCount;
			            break;
			        }
			        if (insertVal > tempPtr2->getData()) 
					{
					    //std::cout << "Insert "<<insertVal<< " After: "  << tempPtr2->getData()<< std::endl;
					    mdl->insertAfterLinkedNode(tempPtr2, insertVal);
					    totalCounts = totalCounts + tailCount;
			            break;
			        }
				}
			}			
		}
	}
	else
	{
		int insertVal(0);
		while(!readFile.eof())
		{
			//std::cout<<"WHILE LOOP"<<std::endl;
			LinkedNode *head = mdl->getHead();
			LinkedNode *tail = mdl->getTail();
			LinkedNode *tempPtr = mdl->getHead();
			LinkedNode *tempPtr2 = mdl->getTail();
			int headCount(0);
			int exit=0;
			int tailCount(0);
			readFile >> insertVal;
			std::cout<<insertVal<<std::endl;
			if(insertVal<=head->getData())
			{
				//std::cout<<"Head value:"<<head->getData()<<std::endl;
				headCount++;
				mdl->insertBeforeLinkedNode(head, insertVal);	
			}
			else if(insertVal>=tail->getData())
			{
				//std::cout<<"Tail value:"<<tail->getData()<<std::endl;
				tailCount++;
				mdl->insertAfterLinkedNode(tail, insertVal);	
			}
			else
			{
				int con1=0;
				int con2=0;
				while (insertVal >= tempPtr->getData() || insertVal <= tempPtr2->getData()) 
				{
				    if (insertVal >= tempPtr->getData()) 
					{
				        tempPtr = tempPtr->getNextLinkedNode();
				       // std::cout << "tempPtr: " << tempPtr->getData() << std::endl;
				        headCount++;
				    }

				    if (insertVal <= tempPtr2->getData()) 
					{
				  
				        tempPtr2 = tempPtr2->getPrevLinkedNode();
				        //std::cout << "tempPtr2: " << tempPtr2->getData() << std::endl;
				        tailCount++;
				    }
					
			        if (insertVal < tempPtr->getData()) 
					{
					    //std::cout << "Insert "<<insertVal<< " before: " << tempPtr->getData() << std::endl;
					    mdl->insertBeforeLinkedNode(tempPtr, insertVal);
					    totalCounts = totalCounts + headCount;
			            break;
			        }
			        if (insertVal > tempPtr2->getData()) 
					{
					   // std::cout << "Insert "<<insertVal<< " After: "  << tempPtr2->getData()<< std::endl;
					    mdl->insertAfterLinkedNode(tempPtr2, insertVal);
					    totalCounts = totalCounts + tailCount;
			            break;
			        }
				}
			}			
		}
	}
	
	
	mdl->printList();
	std::cout<<"LENGTH: "<<mdl->getLength()<<std::endl;
	
	
	readFile.close();
	std::cout<<"\nFile output name"<<std::endl;
	std::cin>>fileoutputName;
	fileoutput.open(fileoutputName.c_str());
	
	if(fileoutput.fail())
	{
		std::cout<<"\nFailed to open the selected file"<<std::endl;
		std::cout<<"Please enter in a valid file!"<<std::endl;
		std::cin>>fileoutputName;
		fileoutput.open(fileoutputName.c_str());
		while(fileoutput.fail())
		{
			std::cout<<"Please enter in a valid file!"<<std::endl;
			std::cin>>fileoutputName;
			fileoutput.open(fileoutputName.c_str());
			LinkedNode* printer = mdl->getHead();
			while(printer !=nullptr)
			{
				fileoutput<<printer->getData()<<" ";
				printer=printer->getNextLinkedNode();
			}
		}
	}
	else
	{
		LinkedNode* printer = mdl->getHead();
		while(printer !=nullptr)
		{
			fileoutput<<printer->getData()<<" ";
			printer=printer->getNextLinkedNode();
		}
	}
	fileoutput.close();
	
	fileoutput.open("README.txt", std::ios_base::app);
	if(fileoutput.fail())
	{
		std::cout<<"\nSource file could not be found"<<std::endl;
	}
	else
	{
		fileoutput<<"\nTotal number of Big Dawg Hops: "<<totalCounts<<std::endl;
	}
	fileoutput.close();

	
	delete mdl;
	return 0;
}