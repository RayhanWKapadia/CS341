// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rkapadia
#include "HashEntry.h"


HashEntry::HashEntry() : HashEntry(0,0)
{
	
}
HashEntry::HashEntry(int key, int value)
{
	key_=key;
	status_=empty;
	value_=value;
	state_="empty";
}
HashEntry::~HashEntry()
{
	
}

//getters
int HashEntry::getValue()
{
	return value_;
}
int HashEntry::getKey()
{
	return key_;
}
Status HashEntry::getStatus()
{
	return status_;
}
//setters
void HashEntry::setKey(int key)
{
	key_=key;
}
void HashEntry::setValue(int value)
{
	value_=value;
}
void HashEntry::setStatus(Status status)
{
	status_=status;
}

void HashEntry::setState(std::string state)
{
	state_=state;
}
std::string HashEntry::getState()
{
	return state_;
}
