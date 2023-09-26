 # Honor Pledge:
 #
 # I pledge that I have neither given nor
 # received any help on this assignment.
 #
 # rkapadia
 #This is my makefile. It is tailored to work with driver.cpp and Car.cpp.
 #Car.h is already connected!
 Race.exe: driver.o Car.o
 	g++ driver.o Car.o -o Race.exe

 driver.o: driver.cpp
 	g++ -c driver.cpp -o driver.o

 Car.o: Car.cpp
 	g++ -c Car.cpp -o Car.o

 clean:
 	rm *.o Race.exe

 run:
 	Race.exe
