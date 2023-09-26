# Honor Pledge:
#
# I pledge that I have neither given nor
# received any help on this assignment.
#
# rkapadia
#This makefile is responsbiel for connecting all the files necessary to run the card simulator.
War.exe: driver.o card.o standardDeck.o deck.o nonStandardDeck.o
	g++ driver.o card.o standardDeck.o deck.o nonStandardDeck.o -o War.exe

driver.o: driver.cpp
	g++ -c driver.cpp -o driver.o

deck.o: deck.cpp
	g++ -c deck.cpp -o deck.o
	
card.o: card.cpp
	g++ -c card.cpp -o card.o

standardDeck.o: standardDeck.cpp
	g++ -c standardDeck.cpp -o standardDeck.o

nonStandardDeck.o: nonStandardDeck.cpp
	g++ -c nonStandardDeck.cpp -o nonStandardDeck.o

clean:
	rm *.o War.exe

run:
	War.exe