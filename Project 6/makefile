# Honor Pledge:
#
# I pledge that I have neither given nor
# received any help on this assignment.
#
# rkapadia
#This makefile is responsbiel for connecting all the files necessary to run the hash project.
Hash.exe: driver.o HashTable.o HashTableArray.o HashEntry.o Node.o LinkedNode.o LinkedList.o DoublyLinkedList.o HashTableChaining.o HashTableCuckoo.o
	g++ driver.o HashTable.o HashTableArray.o HashEntry.o Node.o LinkedNode.o LinkedList.o DoublyLinkedList.o HashTableChaining.o HashTableCuckoo.o -o Hash.exe

driver.o: driver.cpp
	g++ -c driver.cpp -o driver.o

HashTable.o: HashTable.cpp
	g++ -c HashTable.cpp -o HashTable.o

HashTableArray.o: HashTableArray.cpp
	g++ -c HashTableArray.cpp -o HashTableArray.o
	
HashEntry.o: HashEntry.cpp
	g++ -c HashEntry.cpp -o HashEntry.o
	
Node.o: Node.cpp
	g++ -c Node.cpp -o Node.o

LinkedNode.o: LinkedNode.cpp
	g++ -c LinkedNode.cpp -o LinkedNode.o
	
LinkedList.o: LinkedList.cpp
	g++ -c LinkedList.cpp -o LinkedList.o

DoublyLinkedList.o: DoublyLinkedList.cpp
	g++ -c DoublyLinkedList.cpp -o DoublyLinkedList.o

HashTableChaining.o: HashTableChaining.cpp
	g++ -c HashTableChaining.cpp -o HashTableChaining.o

HashTableCuckoo.o: HashTableCuckoo.cpp
	g++ -c HashTableCuckoo.cpp -o HashTableCuckoo.o
	
clean:
	rm *.o Hash.exe

run: Hash.exe
	./Hash.exe