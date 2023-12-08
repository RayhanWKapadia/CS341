// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rkapadia
#include "HashTableArray.h"
#include <cstdlib>


HashTableArray::HashTableArray(int size)
{
    myEntry_ = new HashEntry[size];
	size_=size;
}


HashTableArray::~HashTableArray() 
{
	if(myEntry_!=nullptr)
	{
	    delete[] myEntry_;
	}
}
void HashTableArray::clear() {
    if (myEntry_ != nullptr) {
        delete[] myEntry_;
        myEntry_ = nullptr;
        size_ = 0;  // Optionally reset the size to 0 or any default size
    }
}
bool HashTableArray::hasSpace()
{
    for (int i = 0; i < size_; ++i) 
	{
        if (myEntry_[i].getStatus() == empty) 
		{
			return true;
        }
    }
	return false;
	
}
void HashTableArray::setSelection(int val) {
	selection=val;
}


void HashTableArray::insert(int key, int value) {
    HashEntry newEntry(key, value);
    int hash = key % size_;
	int tick=0;
	//Linear probing
if(selection==1)
{
	if(hasSpace()==true)
	{
		if(myEntry_[hash].getStatus()==occupied)
			{
				for (int i = hash+1; i < size_; i++) 
			{
				if(myEntry_[i].getStatus()==empty || myEntry_[i].getStatus()==removed)
				{
					myEntry_[i] = newEntry;
					myEntry_[i].setStatus(occupied);
					tick=1;
					return;
				}
			}
			if(tick!=1)
			{
				for (int i = 0; i < size_; i++) 
				{
					if(myEntry_[i].getStatus()==empty || myEntry_[i].getStatus()==removed)
					{
						myEntry_[i] = newEntry;
						myEntry_[i].setStatus(occupied);
						tick=1;
						return;
					}
				}
			}
		}
		else
		{
			myEntry_[hash] = newEntry;
			myEntry_[hash].setStatus(occupied);
		}

	}
	else 
	{
		std::cout<<"There is no space in your map!"<<std::endl;
		std::cout<<"Resizing your array..."<<std::endl;
		HashEntry * resizedEntry_ = new HashEntry[size_+1];
		for(int i=0; i<size_; i++)
		{
			resizedEntry_[i]=myEntry_[i];
		}
		size_=size_+1;
		delete[] myEntry_;
		myEntry_=resizedEntry_;
		insert(key, value);
		
	}
	
}
	//Quadratic probing
if(selection==2)
{
	//int count=1;
	int count=0;
	int leftover=0;
	int originalHash = key % size_;

	if(hasSpace()==true)
	{
		if(myEntry_[hash].getStatus()==occupied)
		{
			//maybe add another if the hash becomes larger than the size
			while(hash<size_)//for (int i = hash; i < size_; i++) 
			{
				count++;
				hash=abs((originalHash+(count*count))%size_);
				if(myEntry_[hash].getStatus()==empty || myEntry_[hash].getStatus()==removed)
				{
					myEntry_[hash] = newEntry;
					myEntry_[hash].setStatus(occupied);
					tick=1;
					return;
				
				}
			}
			if(tick!=1)
			{
				leftover=abs(hash-size_);
				while(leftover<size_)
				{
					leftover=(leftover+count*count)%size_;
					if(myEntry_[leftover].getStatus()==empty || myEntry_[leftover].getStatus()==removed)
					{
						myEntry_[leftover] = newEntry;
						myEntry_[leftover].setStatus(occupied);
						tick=1;
						return;
					}
					count++;
				}
			}
		}
		else
		{
			myEntry_[hash] = newEntry;
			myEntry_[hash].setStatus(occupied);
		}

	}
	else
	{
		std::cout<<"There is no space in your map!"<<std::endl;
		std::cout<<"Resizing your array..."<<std::endl;
		HashEntry * resizedEntry_ = new HashEntry[size_+1];
		for(int i=0; i<size_; i++)
		{
			resizedEntry_[i]=myEntry_[i];
		}
		size_=size_+1;
		delete[] myEntry_;
		myEntry_=resizedEntry_;
		insert(key, value);
		//delete resizedEntry_;
		
	}
}

}

int HashTableArray::search(int key) 
{
	int tick=0;
    for (int i = 0; i < size_; ++i) 
	{
        if (myEntry_[i].getKey() == key) 
		{
            std::cout<<"The value of the key is: " <<myEntry_[i].getValue()<<std::endl;
			std::cout<<" "<<std::endl;
			return  myEntry_[i].getValue();
			tick=1;
        }
    }
	if (tick!=1)
	{
		std::cout<<"Key not found!"<<std::endl;
	}
    return -1;
}

void HashTableArray::remove(int key) 
{
    for (int i = 0; i < size_; ++i) 
	{
        if (myEntry_[i].getKey() == key) 
		{
			myEntry_[i].setStatus(empty);
            myEntry_[i].setKey(0);
			myEntry_[i].setValue(0);
            index_--;
            return;
        }
    }
    std::cout << "Key not found. Cannot remove." << std::endl;
}

//Prints everything
/*void HashTableArray::print() 
{
    for (int i = 0; i < size_; ++i) 
	{

		    std::cout << "Key: " << myEntry_[i].getKey() << ", Value: " << myEntry_[i].getValue() << std::endl;

    }
}*/
//Prints correct assignment

void HashTableArray::print() 
{
    for (int i = 0; i < size_; ++i) 
	{
		if(myEntry_[i].getStatus()==occupied)
		{
		    std::cout << "[" <<i<< "]: "<<myEntry_[i].getKey()<<std::endl;;
			
		}
		else
		{
			std::cout << "[" <<i<< "]: "<<std::endl;;		
		}

    }
}

int HashTableArray::getSize() 
{
    return size_;
}

void HashTableArray::setSize(int size) 
{
    size_=size;

}