// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rkapadia
#include "HashTableChaining.h"

HashTableChaining::HashTableChaining(int size)
{
    myEntry_ = new DoublyLinkedList[size];
	size_=size;
}


HashTableChaining::~HashTableChaining() 
{
	if(myEntry_!=nullptr)
	{
	    delete[] myEntry_;
	}
}

void HashTableChaining::insert(int key, int value) {
	HashEntry newEntry(key, value);
	int hash = key % size_;
	myEntry_[hash].insertLinkedNode(myEntry_[hash].getTail(), newEntry);
}
/*
To resolve the issue:
- dll and ll destructors need to be virtual
- driver delete table 
*/
int HashTableChaining::search(int key) 
{
    for (int i = 0; i < size_; ++i) 
	{
			if(myEntry_[i].listSearch2(key) == key)
			{
	            std::cout<<"The value of the key is: " << myEntry_[i].valueSearch(key) <<std::endl;
				return myEntry_[i].valueSearch(key);
			}
    }
	std::cout<<"Key not found!"<<std::endl;
	return -1;
}

void HashTableChaining::remove(int key) {
    int hash = key % size_;
    int value;  // Variable to store the value if found
    if (myEntry_[hash].listSearch2(key)==key) {
        myEntry_[hash].deleteNode(key);
		print();
    }
	else 
	{
        std::cout << "Entry was not found!" << std::endl;
    }
}


void HashTableChaining::print() 
{
    for (int i = 0; i < size_; ++i) 
	{
		if(myEntry_[i].getLength()==0)
		{
		    std::cout << "[" <<i<< "]: "<<std::endl;
			//std::cout<<myEntry_[i].getLength()<<std::endl;
			
		}
	
		else
		{
			std::cout << "[" <<i<< "]: ";
			myEntry_[i].printList();	
			//std::cout<<" "<<std::endl;
			//std::cout<<myEntry_[i].getLength()<<std::endl;
			
		}

    	}
}

int HashTableChaining::getSize() 
{
    return size_;
}

void HashTableChaining::setSize(int size) 
{
   // if (size_ == 0) 
	//{
		delete myEntry_;
        size_ = size;
        myEntry_ = new DoublyLinkedList[size];
   /* } 
	else 
	{
        std::cout << "Size can only be set once. Current size: " << size_ << std::endl;
    }*/
}