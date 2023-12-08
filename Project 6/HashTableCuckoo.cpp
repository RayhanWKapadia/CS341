// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rkapadia
#include "HashTableCuckoo.h"


HashTableCuckoo::HashTableCuckoo(int size)
{
    firstHashArray = new HashEntry[size];
    secondHashArray= new HashEntry[size];
	size_=size;
	runningCount=0;
}


HashTableCuckoo::~HashTableCuckoo() 
{
	if(firstHashArray!=nullptr)
	{
    	delete[] firstHashArray;
	}
	if(firstHashArray!=nullptr)
	{
    	delete[] secondHashArray;
	}
}
int HashTableCuckoo::firstHashFunction(int key)
{
	return key %size_;
}
int HashTableCuckoo::secondHashFunction(int key)
{
	return (key/size_)%size_;
}
bool HashTableCuckoo::hasSpace()
{
    for (int i = 0; i < size_; ++i) 
	{
        if (firstHashArray[i].getStatus() == empty) 
		{
			return true;
        }
    }
	return false;
	
}

void HashTableCuckoo::insert(int key, int value) 
{
	
    int firstHashInt = firstHashFunction(key);
	int secondHashIntCompare = secondHashFunction(key);
	HashEntry newEntry(key, value);
	if(runningCount>size_/2)
	{
		std::cout<<"There is no space in your map!"<<std::endl;
		std::cout<<"Resizing your arrays..."<<std::endl;
		HashEntry * resizedEntry_ = new HashEntry[size_*2];
		for(int i=0; i<size_; i++)
		{
			resizedEntry_[i]=firstHashArray[i];
		}
		//size_=size_+1;
		delete[] firstHashArray;
		firstHashArray=resizedEntry_;


		resizedEntry_ = new HashEntry[size_*2];
		for(int i=0; i<size_; i++)
		{
			resizedEntry_[i]=secondHashArray[i];
		}
		delete[] secondHashArray;
		size_=size_*2;
		secondHashArray=resizedEntry_;
		runningCount=0;
	}
		if (firstHashArray[firstHashInt].getStatus()==empty || firstHashArray[firstHashInt].getStatus()==removed)
		{
		firstHashArray[firstHashInt] = newEntry;
		firstHashArray[firstHashInt].setStatus(occupied);
		runningCount++;
		return;
		}
		else
		{
			HashEntry tempFirstHash = firstHashArray[firstHashInt];
			int secondHashInt = secondHashFunction(tempFirstHash.getKey());
			firstHashArray[firstHashInt]= newEntry;
			firstHashArray[firstHashInt].setStatus(occupied);
		
		if(secondHashArray[secondHashInt].getStatus()==empty || secondHashArray[secondHashInt].getStatus()==removed)
		{
			secondHashArray[secondHashInt]=tempFirstHash;
			secondHashArray[secondHashInt].setStatus(occupied);
			runningCount++;
			return;
		}
		//resize when over 50%
		else
		{
			HashEntry tempSecondHash = secondHashArray[secondHashInt];
			secondHashArray[secondHashInt] = tempFirstHash;
			secondHashArray[secondHashInt].setStatus(occupied);
			
			int hashfunction3 = firstHashFunction(tempSecondHash.getKey());
			if(firstHashArray[hashfunction3].getStatus() == occupied)
			{
				std::cout<<"There is no space in your map!"<<std::endl;
				std::cout<<"Resizing your arrays..."<<std::endl;
				HashEntry * resizedEntry_ = new HashEntry[size_*2];
				for(int i=0; i<size_; i++)
				{
					resizedEntry_[i]=firstHashArray[i];
				}
				//size_=size_+1;
				delete[] firstHashArray;
				firstHashArray=resizedEntry_;
		
		
				resizedEntry_ = new HashEntry[size_*2];
				for(int i=0; i<size_; i++)
				{
					resizedEntry_[i]=secondHashArray[i];
				}
				delete[] secondHashArray;
				size_=size_*2;
				secondHashArray=resizedEntry_;
		
		
				insert(key, value);
			}
			
				firstHashArray[hashfunction3] = tempSecondHash;
				firstHashArray[hashfunction3].setStatus(occupied);
				runningCount++;		
		}
		
	}
}

int HashTableCuckoo::search(int key) 
{
    for (int i = 0; i < size_; ++i) 
	{
        if (firstHashArray[i].getKey() == key) 
		{
            std::cout<<"The value of the key is: " << firstHashArray[i].getValue()<<std::endl;
            return firstHashArray[i].getValue();
        }
    }
    for (int i = 0; i < size_; ++i) 
	{
        if (secondHashArray[i].getKey() == key) 
		{
            std::cout<<"The value of the key is: " << secondHashArray[i].getValue()<<std::endl;
            return secondHashArray[i].getValue();
        }
    }
    return -1;
}

void HashTableCuckoo::remove(int key) 
{
	//FINISH THIS FUNCTION!
	//JUST LOOP THROUGH
    for (int i = 0; i < size_; ++i) 
	{
        if (firstHashArray[i].getKey() == key) 
		{
            //return firstHashArray[i].getValue();
			firstHashArray[i].setKey(0);
			firstHashArray[i].setStatus(removed);
        }
    }
    for (int i = 0; i < size_; ++i) 
	{
        if (secondHashArray[i].getKey() == key) 
		{
            //return firstHashArray[i].getValue();
			secondHashArray[i].setKey(0);
			secondHashArray[i].setStatus(removed);
        }
    }
	
}

//Prints everything
void HashTableCuckoo::print() 
{
    for (int i = 0; i < size_; ++i) 
	{
		if(firstHashArray[i].getStatus()==occupied)
		{
		    std::cout << "[" <<i<< "]: "<<firstHashArray[i].getKey()<<std::endl;
		}
		else
		{
		    std::cout << "[" <<i<< "]: "<<std::endl;
			
		}
	}
    std::cout << "______________________ "<<std::endl;
	
    for (int i = 0; i < size_; ++i) 
	{
		if(secondHashArray[i].getStatus()==occupied)
		{
		    std::cout << "[" <<i<< "]: "<<secondHashArray[i].getKey()<<std::endl;
		}
		else
		{
		    std::cout << "[" <<i<< "]: "<<std::endl;
			
		}
	}
}

int HashTableCuckoo::getSize() 
{
    return size_;
}

void HashTableCuckoo::setSize(int size) 
{
    size_=size;
}