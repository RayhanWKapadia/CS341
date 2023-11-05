# Honor Pledge:
#
# I pledge that I have neither given nor
# received any help on this assignment.
#
# rkapadia
# This makefile is responsible for compiling the BitArray project.
BitArray.exe: driver.o bitarray.o dictionary.o set.o 
	g++ driver.o bitarray.o dictionary.o set.o -o BitArray.exe

driver.o: driver.cpp
	g++ -c driver.cpp -o driver.o

bitarray.o: bitarray.cpp
	g++ -c bitarray.cpp -o bitarray.o

set.o: set.cpp
	g++ -c set.cpp -o set.o

dictionary.o: dictionary.cpp
	g++ -c dictionary.cpp -o dictionary.o

clean:
	rm -f *.o BitArray.exe

run: BitArray.exe
	./BitArray.exe