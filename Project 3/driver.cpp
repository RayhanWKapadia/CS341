// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rkapadia

#include "set.h"
#include "bitarray.h"
#include "dictionary.h"
#include <iostream>
#include <cstring>

int main() {
	//The following phases are purely for tesitng purposes. There 
	
	//Phase 1 and 2
    char testData[] = "test";
    BitArray *myBitArray = new BitArray(strlen(testData)*8);
    myBitArray->initialize(testData, 4);
    std::cout << "Initial BitArray:" << std::endl;
    myBitArray->print();
    bool is0thBitSet = myBitArray->get(0);
    bool is10thBitSet = myBitArray->get(10);
    std::cout << "0th Bit Set: ";
    if (is0thBitSet) {
        std::cout << "True" << std::endl;
    } else {
        std::cout << "False" << std::endl;
    }
    std::cout << "10th Bit Set: ";
    if (is10thBitSet) {
        std::cout << "True" << std::endl;
    } else {
        std::cout << "False" << std::endl;
    }
    std::cout << "Setting 0th position to 1..." << std::endl;
    myBitArray->set(0, 1);
    myBitArray->print();
    std::cout << "Setting 10th position to 0..." << std::endl;
    myBitArray->set(10, 0);
    myBitArray->print();
    std::cout << "Complement:" << std::endl;
    myBitArray->complement();
    myBitArray->print();
    std::cout << "Clear BitArray:" << std::endl;
    myBitArray->clear();
    myBitArray->print();
	
	std::cout<<"----------------------------------------------------------------------------------------------------"<<std::endl;
	
	//Set 8 
	
	
	
	std::cout<<"Set 8 test!"<<std::endl;	
	BitArray tester;
    char testerData[] = "test";
	tester.initialize(testerData, 4);
	std::cout<<"Before"<<std::endl;
	tester.print();
	
	std::cout<<"After set8:"<<std::endl;
	tester.set8('W', 3);
	tester.print();
	std::cout<<"----------------------------------------------------------------------------------------------------"<<std::endl;
	
	//Phase 3
    Set A;
    Set B;
	
    char testDataA[] = "test1";
    A.initialize(testDataA, 4);
	char testDataB[] = "ryan";
    B.initialize(testDataB, 4);
    std::cout << "Set A:" << std::endl;
    A.getData();
    std::cout << "Set B:" << std::endl;
    B.getData();
    int cardinalityA = A.getCardinality();
    int cardinalityB = B.getCardinality();
    std::cout << "Cardinality: " << cardinalityA + cardinalityB << std::endl;
    std::cout << "Set Union (A U B):" << std::endl;
    A.setUnion(B);
	
    Set C;
	Set D;
	
   	char testDataC[] = "test";
    C.initialize(testDataC, 4);
	
    std::cout << "Set Intersection (A X B):" << std::endl;
    C.setIntersection(B);
	std::cout<<"----------------------------------------------------------------------------------------------------"<<std::endl;

	
	//Phase 4 and 5
	//This is the main program that runs the rank and select functions.
	char test[] = "test";
	Dictionary d;
	d.initialize(test, strlen(test));
	std::cout<<"Rank(7, 1) "<<d.rank(7,1)<<std::endl;
	std::cout<<"Rank Range(0, 7, 1) "<<d.rank_range(0, 7, 1)<<std::endl;
	std::cout<<"Select (2,1) "<<d.select(2, 1)<<std::endl;
	std::cout<<"Select Range (0,7,2,1) "<<d.select_range(0,7,2,1)<<std::endl;
	d.printLookupTable(std::cout);
	std::cout<<"----------------------------------------------------------------------------------------------------"<<std::endl;
	
	//Uncomment for implementation of other phases.
	delete myBitArray;

    return 0;
}