# Honor Pledge:
#
# I pledge that I have neither given nor
# received any help on this assignment.
#
# rkapadia
# Compiles linked-list assignment.
LL.exe: driver.o Node.o LinkedNode.o LinkedList.o DoublyLinkedList.o
	g++ driver.o Node.o LinkedNode.o LinkedList.o DoublyLinkedList.o -o LL.exe

driver.o: driver.cpp
	g++ -c driver.cpp -o driver.o

Node.o: Node.cpp
	g++ -c Node.cpp -o Node.o

LinkedNode.o: LinkedNode.cpp
	g++ -c LinkedNode.cpp -o LinkedNode.o
	
LinkedList.o: LinkedList.cpp
	g++ -c LinkedList.cpp -o LinkedList.o

DoublyLinkedList.o: DoublyLinkedList.cpp
	g++ -c DoublyLinkedList.cpp -o DoublyLinkedList.o

clean:
	rm -f *.o LL.exe

run: LL.exe
	./LL.exe