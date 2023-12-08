// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rkapadia
#ifndef HASHENTRY_H
#define HASHENTRY_H
#include "HashTable.h"
#include <iostream>
enum Status {empty, occupied, removed};
class HashEntry
{
public:
	HashEntry();
	HashEntry(int key, int value);
	~HashEntry();
	//getters
	int getValue();
	int getKey();
	Status getStatus();
	//setters
	void setKey(int key);
	void setValue(int value);
	void setStatus(Status status);
	
	void setState(std::string state);
	std::string getState();
	Status status_;
	
	
private:
	int key_;
	int value_;
	//Status status_;
	std::string state_;
};

#endif