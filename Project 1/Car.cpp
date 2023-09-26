//Honor Pledge:
 //
 // I pledge that I have neither given nor
 // received any help on this assignment.
 //
 // rkapadia
 #include <iostream>
 #include <string>
 #include "Car.h"
 //Default constructor is standard practice
 Car::Car()
 {
 	std::string name_="Default";
 	int speed_=0;
 	int control_=0;
 }
 Car::Car(std::string n, int s, int c, int l){
 	std::string name_=n;
 	int speed_=s;
 	int control_=c;
 	int lapnumber_=l;
 }
 //Always use a destructor. This is also good practice!
 //These are also the deifinitions of my functions!
 Car::~Car(){}
 std::string Car::getName()
 {
 	return name_;
 }
 int Car::getSpeed()
 {
 	return speed_;
 }
 int Car::getControl()
 {
 	return control_;
 }
 int Car::getLapNumber()
 {
 	return lapnumber_;
 }
 void Car::setName(std:: string n)
 {
 	name_=n;
 }
 void Car::setSpeed(int s)
 {
 	speed_=s;
 }
 void Car::setControl(int c)
 {
 	control_=c;
 }
 void Car::setLapNumber(int l)
 {
 	lapnumber_=l;
 }
