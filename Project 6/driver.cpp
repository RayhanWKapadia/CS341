// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rkapadia
#include "HashTable.h"
#include "HashTableArray.h"
#include "HashTableChaining.h"
#include <iostream>
#include <fstream>
#include <string>
#include "HashTableCuckoo.h"
//valgrind --log-file=valgrind->txt --leak-check=full Hash->exe
int main() {
	HashTableArray * linearTable = nullptr;
	HashTableArray * quadTable = nullptr;
	HashTableCuckoo * cuckooTable = nullptr;
	HashTableChaining * chainTable = nullptr;
	
		int answer=0;
		int condition=0;
		int sizeAns=0;
		std::cout<<"Welcome to Blue IV's Can of Who Hash!"<<std::endl;
		std::cout<<"1) Linear Probing"<<std::endl;
		std::cout<<"2) Quadratic Probing"<<std::endl;
		std::cout<<"3) Separate Chaining"<<std::endl;
		std::cout<<"4) Cuckoo Hashing"<<std::endl;
		std::cout<<"5) Quit Program"<<std::endl;
		while(answer!=5)
		{
			std::cout<<"Please enter your answer: ";
			std::cin>>answer;
			std::cout<<" "<<std::endl;
			if(answer!=1 && answer!=2 && answer!=3 && answer!=4 && answer!=5)
			{
				std::cout<<"Enter a number from 1 and 5!"<<std::endl;
			}
			else if(answer!=5)
			{
				std::cout<<"Please enter the size of the Hash Table you wish to create: ";
				std::cin>>sizeAns;
				if(answer==1)
				{
					std::ifstream file1("extra.txt");
					delete linearTable;
					linearTable = new HashTableArray(sizeAns);
					linearTable->setSize(sizeAns);
					linearTable->setSelection(1);
					
					while(!file1.eof())
					{
						int key=0;
						int value=0;
						file1>>key >>value;
						linearTable->insert(key, value);
					}
					linearTable->print();
					int answerTwo=0;
					while(answerTwo!=4)
					{
						std::cout<<" "<<std::endl;
						std::cout<<"1) Search For Entry"<<std::endl;
						std::cout<<"2) Remove Entry"<<std::endl;
						std::cout<<"3) Print Hash Table"<<std::endl;
						std::cout<<"4) Return to Main Menu"<<std::endl;
						std::cout<<"Please enter your answer: ";
						std::cin>>answerTwo;
						std::cout<<" "<<std::endl;
						if(answerTwo!=1 && answerTwo!=2 &&answerTwo!=3 && answerTwo!=4)
						{
							std::cout<<"Enter a number from 1 and 4!"<<std::endl;
						}
						else if(answerTwo!=4)
						{
							if(answerTwo==1)
							{
								int myKey=0;
								std::cout<<"Search (Please enter a Key): ";
								std::cin>>myKey;
								std::cout<<" "<<std::endl;
								linearTable->search(myKey);
							}
							else if(answerTwo==2)
							{
								int myKey=0;
								std::cout<<"Remove (Please enter a Key): ";
								std::cin>>myKey;
								std::cout<<" "<<std::endl;
								linearTable->remove(myKey);
								linearTable->print();
								
							}
							else if(answerTwo==3)
							{
								linearTable->print();
							}
								
						
						}
						file1.close();						
					}
delete linearTable;	
				}//if ans==1
				
				else if (answer==2)
				{		
					std::ifstream file2("extra.txt");	
					std::ifstream filetempo("extra.txt");		
					int count=0;
					int tempsize=0;
					std::string line;
					while (std::getline(filetempo, line)) 
					{
						count++;
					}
					if (count>=sizeAns)
					{
						sizeAns=count*2;
					}
					delete quadTable;
					quadTable = new HashTableArray(sizeAns);
					quadTable->setSelection(2);
					int key=0;
					int value=0;
					while(file2.eof()!=true)
					{
						int key=0;
						int val=0;
						file2>>key >>value;
						quadTable->insert(key, value);
					}
					quadTable->print();
					int answerTwo=0;
					while(answerTwo!=4)
					{
						std::cout<<" "<<std::endl;
						std::cout<<"1) Search For Entry"<<std::endl;
						std::cout<<"2) Remove Entry"<<std::endl;
						std::cout<<"3) Print Hash Table"<<std::endl;
						std::cout<<"4) Return to Main Menu"<<std::endl;
						std::cout<<"Please enter your answer:";
						std::cin>>answerTwo;
						std::cout<<" "<<std::endl;
						if(answerTwo!=1 && answerTwo!=2 &&answerTwo!=3 && answerTwo!=4)
						{
							std::cout<<"Enter a number from 1 and 4!"<<std::endl;
						}
						else if(answerTwo!=4)
						{
							if(answerTwo==1)
							{
								int myKey=0;
								std::cout<<"Search (Please enter a Key): ";
								std::cin>>myKey;
								std::cout<<" "<<std::endl;
								quadTable->search(myKey);
							}
							else if(answerTwo==2)
							{
								int myKey=0;
								std::cout<<"Remove (Please enter a Key): ";
								std::cin>>myKey;
								std::cout<<" "<<std::endl;
								quadTable->remove(myKey);
								quadTable->print();
								
							}
							else if(answerTwo==3)
							{
								quadTable->print();
							}
					
						}
						filetempo.close();
						file2.close();		
					}	
				}
				else if(answer==3)
				{
					std::ifstream filetempo3("extra.txt");		
					int count=0;
					int tempsize=0;
					std::string line;
					/*while (std::getline(filetempo3, line)) 
					{
						count++;
					}
					if (count>=sizeAns)
					{
						sizeAns=count*2;
					}*/
					
					std::ifstream file3("extra.txt");
					int key=0;
					int value=0;	
					delete chainTable;
					chainTable = new HashTableChaining(sizeAns);
					
					while(file3.eof()!=true)
					{
						int key=0;
						int val=0;
						file3>>key >>value;
						chainTable->insert(key, value);
					}
					chainTable->print();
					int answerTwo=0;
					while(answerTwo!=4)
					{
						std::cout<<" "<<std::endl;
						std::cout<<"1) Search For Entry"<<std::endl;
						std::cout<<"2) Remove Entry"<<std::endl;
						std::cout<<"3) Print Hash Table"<<std::endl;
						std::cout<<"4) Return to Main Menu"<<std::endl;
						std::cout<<"Please enter your answer:";
						std::cin>>answerTwo;
						std::cout<<" "<<std::endl;
						if(answerTwo!=1 && answerTwo!=2 &&answerTwo!=3 && answerTwo!=4)
						{
							std::cout<<"Enter a number from 1 and 4!"<<std::endl;
						}
						else if(answerTwo!=4)
						{
							if(answerTwo==1)
							{
								int myKey=0;
								std::cout<<"Search (Please enter a Key): ";
								std::cin>>myKey;
								std::cout<<" "<<std::endl;
								chainTable->search(myKey);
							}
							else if(answerTwo==2)
							{
								int myKey=0;
								std::cout<<"Remove (Please enter a Key): ";
								std::cin>>myKey;
								std::cout<<" "<<std::endl;
								chainTable->remove(myKey);
								//chainTable->print();
								
							}
							else if(answerTwo==3)
							{
								chainTable->print();
							}
					
						}						
						file3.close();
						filetempo3.close();
					}

delete chainTable;	
				}
				
				else if(answer==4)
				{
					std::ifstream filetempo2("extra.txt");
					int count=0;
					int tempsize=0;
					std::string line;
					while(std::getline(filetempo2, line)) 
					{
						count++;
					}
					if (count>=sizeAns)
					{
						sizeAns=count*2;
					}
					delete cuckooTable;
					cuckooTable = new HashTableCuckoo(sizeAns);
					
					int key=0;
					int value=0;
					std::ifstream file4("extra.txt");
					while(file4.eof()!=true)
					{
						int key=0;
						int val=0;
						file4>>key >>value;
						cuckooTable->insert(key, value);
					}
					cuckooTable->print();
					int answerTwo=0;
					while(answerTwo!=4)
					{
						std::cout<<" "<<std::endl;
						std::cout<<"1) Search For Entry"<<std::endl;
						std::cout<<"2) Remove Entry"<<std::endl;
						std::cout<<"3) Print Hash Table"<<std::endl;
						std::cout<<"4) Return to Main Menu"<<std::endl;
						std::cout<<"Please enter your answer:";
						std::cin>>answerTwo;
						std::cout<<" "<<std::endl;
						if(answerTwo!=1 && answerTwo!=2 &&answerTwo!=3 && answerTwo!=4)
						{
							std::cout<<"Enter a number from 1 and 4!"<<std::endl;
						}
						
						else if(answerTwo!=4)
						{
							if(answerTwo==1)
							{
								int myKey=0;
								std::cout<<"Search (Please enter a Key): ";
								std::cin>>myKey;
								std::cout<<" "<<std::endl;
								cuckooTable->search(myKey);
							}
							else if(answerTwo==2)
							{
								int myKey=0;
								std::cout<<"Remove (Please enter a Key): ";
								std::cin>>myKey;
								std::cout<<" "<<std::endl;
								cuckooTable->remove(myKey);
								cuckooTable->print();
							}
							else if(answerTwo==3)
							{
								cuckooTable->print();
							}
					
						}
						file4.close();
						filetempo2.close();						
					}	
				}
				std::cout<<"1) Linear Probing"<<std::endl;
				std::cout<<"2) Quadratic Probing"<<std::endl;
				std::cout<<"3) Separate Chaining"<<std::endl;
				std::cout<<"4) Cuckoo Hashing"<<std::endl;
				std::cout<<"5) Quit Program"<<std::endl;
			}
		}

			//delete linearTable;	

			//delete cuckooTable;	

			//delete chainTable;	

			//delete quadTable;	
			
			
			
			
	
    return 0;
}
