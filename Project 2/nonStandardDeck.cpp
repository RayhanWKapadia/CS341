// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rkapadia
#include "nonStandardDeck.h"

//This class will simulat the nonstandard deck and is the actual implementation.

NonStandardDeck::NonStandardDeck()
{
	int holder=0;
    std::ifstream file2("deck.txt");
    if (!file2.is_open()) {
        std::cout << "Failed to open file: " << std::endl;
    }
    file2 >> holder;
	file2.close();
	capacity_=holder;
	deck_ = new Card[holder];
	numCards_=0;
}

NonStandardDeck::~NonStandardDeck() 
{
    delete[] deck_;
}

bool NonStandardDeck::isEmpty() 
{
    return numCards_ == 0;
}

void NonStandardDeck::initializeDeck()
{
	    std::ifstream file("deck.txt");
	    if (!file.is_open()) 
		{
	        std::cout << "Failed to open file: " << std::endl;
	    }

	    file >> capacity_;
		numCards_=capacity_; // Read the number of cards
		capacity_--;
	    int s, f;
	    int currentIndex = 0;
	    while (file >> s >> f && currentIndex < numCards_) 
		{
	        deck_[currentIndex].initialize(s, f);
			//std::cout<<deck_[currentIndex].print()<<std::endl;
	        currentIndex++;
	    }
		

	    file.close();
}

int NonStandardDeck::getNumCards() 
{
    return numCards_;
}

void NonStandardDeck::displayCard(int i) 
{
    if (i >= 0 && i < numCards_) {
        std::cout << deck_[i].print() << std::endl;
    } else {
        std::cout << "Invalid card index." << std::endl;
    }
}

void NonStandardDeck::printDeck() 
{
    for (int i = 0; i < numCards_; i++) 
	{
        std::cout << deck_[i].print() << std::endl;
    }
}

bool NonStandardDeck::addCard(Card c) 
{
    if (numCards_ < capacity_) {
        deck_[numCards_] = c;
        numCards_++;
        return true;
    } else {
        std::cout << "Deck is full. Cannot add more cards." << std::endl;
        return false;
    }
}

void NonStandardDeck::shuffle() 
{
    int swapper = numCards_ * 3;
    for (int i = 0; i < swapper; i++) 
	{
        int val1 = rand() % numCards_;
        int val2 = rand() % numCards_;
        std::swap(deck_[val1], deck_[val2]);
    }
}

bool NonStandardDeck::mergeDecks(NonStandardDeck& otherDeck, bool shouldShuffle) 
{
    int totalCards = numCards_ + otherDeck.getNumCards();
    if (totalCards <= capacity_) 
	{
        for (int i = 0; i < otherDeck.getNumCards(); i++) 
		{
            if (numCards_ < capacity_) 
			{
                deck_[numCards_] = otherDeck.dealCard();
                numCards_++;
            } 
			else 
			{
                std::cout << "Deck is full. Ignoring additional cards." << std::endl;
                break;
            }
        }
        if (shouldShuffle) 
		{
            shuffle();
        }
        return true;
    } 
	else 
	{
        std::cout << "Merging would exceed deck capacity. Cannot merge." << std::endl;
        return false;
    }
}

Card NonStandardDeck::dealCard() 
{
	if (numCards_ > 0) {
        numCards_--;
        return deck_[numCards_];
    }
    return Card();
}

Card NonStandardDeck::getTop() 
{
    if (numCards_ > 0) {
        return deck_[numCards_ - 1];
    }
    return Card();
}

Card NonStandardDeck::getSecondFromTop() 
{
    if (numCards_ >= 2) {
        return deck_[numCards_ - 2];
    }
    return Card();
}

Card NonStandardDeck::getThirdFromTop() 
{
    if (numCards_ >= 3) {
        return deck_[numCards_ - 3];
    }
    return Card();
}