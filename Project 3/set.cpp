// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rkapadia

#include "set.h"
#include <cmath>

//Constructor
Set::Set(int size) : data_(size) {}

//Destructor
Set::~Set() {
}

void Set::initialize(char*word, int size) {
    data_.initialize(word, size);
}

int Set::getCardinality() const {
	int myVal=0;
	int myLength=data_.length();
	for(int i=0; i<myLength; i++){
		data_.get(i);
		if(data_.get(i)){
			myVal++;
		}
	}	
	return myVal;
}

BitArray & Set::getData()
{
	data_.print();
	return data_;
}

//Union of binary!
bool Set::setUnion(Set &B) {
	char dataChar = ' ';
	char BChar = ' ';
	
	if(data_.length()==B.data_.length())
	{
		for(int i=0; i<data_.length(); i++)
		{
			dataChar = data_.get(i);
			BChar=B.data_.get(i);
			dataChar=dataChar|BChar;
			data_.set(i,dataChar);
		}
	data_.print();
	return true;
	}
	else
	{
		return false;
	}
}

//Intersection of binary
bool Set::setIntersection(Set &B) {
	char dataChar = ' ';
	char BChar = ' ';
	if(data_.length()==B.data_.length()){
		for(int j=0;j<data_.length();j++)
		{
			dataChar=data_.get(j);
			BChar=B.data_.get(j);
			dataChar=dataChar&BChar;
			data_.set(j,dataChar);
		}
		data_.print();
		return true;
	}
	
	else
	{
		return false;
	}
	
}