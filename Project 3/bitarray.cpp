// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rkapadia

#include "bitarray.h"
#include <iostream>

//This is the implementation of the bitarray class.
BitArray::BitArray(int size) {
	//Most of these comments are ultimately redundent but they can cause memory leak.
	//They can help largely in seting wher ethe Bytes and Lengths go.
    //LENGTH = size;
	//std::cout<<LENGTH<<std::endl;
	//std::cout<<size<<std::endl;
    //BYTES = (size + BIT_IN_BYTE - 1) / BIT_IN_BYTE;
    data_ = nullptr;
    //clear();
}

BitArray::BitArray(const BitArray &array) {
    //LENGTH = array.LENGTH;
    //BYTES = array.BYTES;
    //data_ = new char[BYTES];
    for (int i = 0; i < BYTES; i++) {
        data_[i] = array.data_[i];
    }
}

BitArray::~BitArray() {
    delete[] data_;
}

void BitArray::clear() {
    for (int i = 0; i < BYTES; i++) {
        data_[i] = 0;
    }
}

void BitArray::initialize(char *word, int size) {
    clear();
	
	BYTES=size;
	data_=new char[size];
	LENGTH=BYTES*BIT_IN_BYTE;
	//BYTES=size*BIT_IN_BYTE;
	//data_=new char[size];
	//LENGTH=BYTES;

	for (int i = 0; i < size; i++) {
	        unsigned char c = word[i];
	        for (int j = 0; j < BIT_IN_BYTE; j++) {
	            if (c & (1 << (BIT_IN_BYTE - 1 - j))) {
	                set(i * BIT_IN_BYTE + j);
	            }
	        }
	    }
}

void BitArray::print() {
    for (int i = 0; i < LENGTH; i++) {
        if (get(i)) {
            std::cout << '1';
        } else {
            std::cout << '0';
        }
        if ((i + 1) % BIT_IN_BYTE == 0) {
            std::cout << "|";
        }
    }
    std::cout << "\n";
}

bool BitArray::get(int position) const {
    if (position < 0 || position >= LENGTH) {
        return false;
    }
    int byteIndex = position / BIT_IN_BYTE;
    int bitIndex = position % BIT_IN_BYTE;
    return (data_[byteIndex] & (1 << bitIndex)) != 0;
}

bool BitArray::set(int position, int bit) {
    if (position < 0 || position >= LENGTH || (bit != 0 && bit != 1)) 
	{
        return false; 
    }
    int byteIndex = position / BIT_IN_BYTE;
    int bitIndex = position % BIT_IN_BYTE;
	
    if (bit == 0) 
	{
        data_[byteIndex] &= ~(1 << bitIndex);
    } 
	
	else 
	{
        data_[byteIndex] |= (1 << bitIndex);
    }
    return true;
}

bool BitArray::flip(int position) {
    if (position < 0 || position >= LENGTH) {
        return false;
    }
    int byteIndex = position / BIT_IN_BYTE;
    int bitIndex = position % BIT_IN_BYTE;
    data_[byteIndex] ^= (1 << bitIndex);
    return true;
}

//Complement function
void BitArray::complement() {
    for (int i = 0; i < BYTES; i++) {
        data_[i] = ~data_[i];
    }
}

char BitArray::get8(int position) const {
    if (position < 0 || position >= BYTES) {
        return 0; 
    }
    return data_[position];
}

//Alternate way to do a reversed set8 function
/*void BitArray::set8(char c, int index) {
    if (index >= 0 && index < BYTES) {
        unsigned char reversedByte = 0;
        for (int i = 0; i < BIT_IN_BYTE; i++) {
            if (c & (1 << i)) {
                reversedByte |= (1 << (BIT_IN_BYTE - 1 - i));
            }
        }
        data_[index] = reversedByte;
    }
}*/

void BitArray::set8(char c, int index)
{
	data_[index]=c;
}

