// Honor Pledge:
 //
 // I pledge that I have neither given nor
 // received any help on this assignment.
 //
 // rkapadia

 #include <iostream>
 #include <fstream>
 #include <string>
 #include <cstdlib>  
 #include <ctime>  
 #include "Car.h"
 //This is the simulate racing function. It will eventually end at 200 laps and the race is over.
 std::string simulaterace(Car yourArray[], int yourLines)
 {
 	srand(time(0));
 	int turn=0;
 	std::string winner= " ";
 	int key=0;
 	std::string winnername = " ";
 	int hold=0;
 	while (key==0)
 	{
 		for(int i=0; i<yourLines; i++)
 		{
 			if(yourArray[i].getControl()>5)
 			{
 				int random = rand() % 10 + 1;
 				turn=(yourArray[i].getControl())/random;
 				//hold=hold+turn+yourArray[i].getSpeed();
 				yourArray[i].setLapNumber(yourArray[i].getLapNumber()+turn+yourArray[i].getSpeed());
 				if(yourArray[i].getLapNumber()>=200)
 				{
 					yourArray[i].setLapNumber(200);
 					winner = yourArray[i].getName();
 					key=1;
 					break;
 				}
 			}
 			else if (yourArray[i].getControl()<=5)
 			{
 				int holder = yourArray[i].getSpeed();
 				yourArray[i].setLapNumber(yourArray[i].getLapNumber()+holder);
 				if(yourArray[i].getLapNumber()>=200)
 				{
 					yourArray[i].setLapNumber(200);
 					winner = yourArray[i].getName();
 					key=1;
 					break;
 				}
 			}
 			//Uncomment this to ensure that the laps are incrementing properly!
 			//std::cout<<yourArray[3].getName()<<": "<<yourArray[3].getLapNumber()<<std::endl;
 		}
 	}
 	std::cout<<"\n"<<std::endl;
 	std::cout<<"*** "<< winner <<" has won the 2023 Indianapolis 500! ***"<<std::endl;
 	std::cout<<"\nDriver Name: Lap Number"<<std::endl;
 	std::cout<<"**********************"<<std::endl;
 	for(int i=0; i<yourLines; i++)
 		{
 			std::cout<<yourArray[i].getName()<<": "<<yourArray[i].getLapNumber()<<std::endl;
 		}
 		std::string response = " ";
 		return response;
 	}
 //This is the main function. Everything convereges herea dn will be done through this
 int main()
 {
 	int lines=0;
 	std::string myFile;
 	std::ifstream indy500("indy500.txt");
 	while(std::getline (indy500, myFile))
 	{
 		lines++;
 		//Uncomment the next line to see the entire file
 		//std::cout<<myFile<<std::endl;
 	}
 	indy500.close();
 	Car myArray[lines];
 	int value;
 	std::string holder;
 	std::ifstream indy5002;
 	//Ensuring there is no failure when reading in.
 	indy5002.open("indy500.txt", std::ios::in);
 	if(indy5002.fail())
 	{
 		std::cout<<"Error there seems to be an issue with the file"<<std::endl;
 	}
 	//std::getline(indy5002, holder);
 	value=0;
 	std::string namer;
 	int speeder, controler;
 	//Read in the text file and start creating my racers.
 	while(value < lines && indy5002 >> namer>> speeder >> controler)
 	{
 		myArray[value].setName(namer);
 		myArray[value].setSpeed(speeder);
 		myArray[value].setControl(controler);
 		myArray[value].setLapNumber(0);
 		value++;
 	}
 	//These lines are purely for testing and breaking the code
 	/*for(int i=0; i<lines; i++)
 	{
 	std::cout<<"DRIVER: "<<myArray[i].getName()<<" SPEED: "<<myArray[i].getSpeed()<<" CONTROL: "<<myArray[i].getControl()<<" Lap number: "<<myArray[i].getLapNumber()<<" # of racers "<<lines<<std::endl;
 	}*/
 	std::cout<<"***Welcome to the 2023 Indianapolis 500 Race!***\n"<<std::endl;
 	for(int i=0; i<lines; i++)
 	{
 		std::cout<<"***--> Racing..."<<std::endl;
 	}
 	indy5002.close();
 	indy500.close();
 	/*//These lines are used for testing if there are any bugs or potential edge cases
 	std::cout<<"DRIVER: "<<myArray[3].getName()<<" SPEED: "<<myArray[3].getSpeed()<<" CONTROL: "<<myArray[3].getControl()<<" Lap number: "<<myArray[3].getLapNumber()<<" # of racers "<<lines<<std::endl;*/
 	//std::cout<<"MY RANDOM  NUMBER!!!!! "<< 1 + (rand() % 10)<<std::endl;*/
 	std::cout<<simulaterace(myArray, lines)<<std::endl;
 	std::cout<<"Thank you for using my race simulation program - goodbye"<<std::endl;
 	return 0;
 }
