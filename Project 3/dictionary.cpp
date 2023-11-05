// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rkapadia

#include "dictionary.h"
#include <cstring>

//Constructor
Dictionary::Dictionary() {
   BitArray data_(0);
   lookupTable_=new int[256];
    
}

//Destructor
Dictionary::Dictionary(const Dictionary &dict) {
	for(int i=0; i<DICTIONARY_SIZE; i++)
		{
			lookupTable_[i]=dict.lookupTable_[i];
		}
}

Dictionary::~Dictionary() {
	delete [] lookupTable_;
}

void Dictionary::initialize(char *word, int size) {
    data_.initialize(word, size);
    data_.print();
	initializeLookupTable();
}

int Dictionary::rank_range(int start, int end, int bit) {
    if (start < 0) start = 0;
    if (end > data_.length()) end = data_.length();

    int count = 0;
	//Adjusting numbers right here!
	//start++;
    for (int i = start; i <= end; i++) {
        if (data_.get(i) == bit) {
            count++;
        }
    }
    return count;
}

int Dictionary::select_range(int start, int end, int k, int bit) {
    int numCounter = 0;
    int place = -1;
    for (int j = start; j <= end; j++) {
        if (data_.get(j) == bit) {
            numCounter = numCounter + 1;
            if (numCounter == k) {
                place = j;
                break;
            }
        }
    }
    if (numCounter != k) {
        return 0;  
    } else {
        return place;
    }
}

int Dictionary::rank(int end, int bit) {
    int holder2 = 0;
	int increment=0;
	int firstval=0;
	int secondval=0;
	int thirdval=0;
	int fourthval=0;
	firstval=end;
	secondval=firstval%8;
	fourthval=firstval-secondval;
	thirdval=firstval-secondval;
	thirdval=thirdval/8;
	
	while(data_.get8(increment)!=0 &&increment<thirdval)
	{
		unsigned char myChar = data_.get8(increment);
		holder2 += lookupTable_[myChar]; //Count the set bits in this byte.
		increment++;
		//"Increment value "<< increment <<std::endl;
	}
    for (int j=fourthval; j<=end; j++) 
	{
        if (data_.get(j) == bit) 
		{
            holder2++;
        }
    }	
    /*if (bit != 1) {
        holder2 = end - holder2; //Invert if counting 0s.
    }*/
    return holder2; 
}

int Dictionary::select(int k, int bit) 
{
	int val=data_.length();
	//std::cout<<data_.length()<<std::endl;
	int increment=0;
	int counter=0;
	int currentIndex=7;
    int location = 0;
	while(data_.get8(increment)!=0)
	{
		counter += rank(currentIndex, bit);
		//If the k is less than 7 automaticall traverse and grab in the BYTE
		if(counter>=k)
		{
		    int myVal = 0;
		    for (int i = 0; i < currentIndex; i++) {
		        if (data_.get(i) == bit) {
		            myVal=myVal+1;
		            if (myVal == k) {
		                location = i;
		                break;
		            }
		        }
		    }
	}
		increment++;
		currentIndex+=8;
}
	
return location;
}

void Dictionary::printLookupTable(std::ostream & output)
{
	for(int i=0; i<DICTIONARY_SIZE; i++)
	{
		output << "Index:" << i << " = " << lookupTable_[i] << std::endl;
	}
}

//My method of creating a lookup table!
void Dictionary::initializeLookupTable() {
    for (int i = 0; i < DICTIONARY_SIZE; i++) {
        char byte = i;
        int count = 0;
        for (int j = 0; j < 8; j++) {
            if (byte & 1) {
                count++;
            }
            byte >>= 1;
        }
        lookupTable_[i] = count;
    }
}





