// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rkapadia
#include "standardDeck.h"
//This the is the implementation of the standard deck class.
StandardDeck::StandardDeck() 
{
  deck_ = new Card[DECK_SIZE];
  numCards_=0;
}

StandardDeck::~StandardDeck() 
{
    delete[] deck_;
}

bool StandardDeck::isEmpty() 
{
    return (numCards_ == 0);
}

int StandardDeck::getNumCards() 
{
    return numCards_;
}

void StandardDeck::displayCard(int i) 
{
    if (i >= 0 && i < DECK_SIZE) 
    {
        std::cout<<deck_[i].print()<<std::endl;
    } 
    else 
    {
        std::cout << "Invalid card index." << std::endl;
    }
}

 void StandardDeck::initializeDeck()
{
    //deck_ = new Card[DECK_SIZE];
    int k=0;
    for(int s=1; s<=4; s++)
    {
      for(int f=1; f<=13; f++)
      {
          deck_[k].initialize(s, f);
          k++;
      }
    }
      numCards_ = DECK_SIZE;
}

void StandardDeck::printDeck() 
{
    for (int i = 0; i < numCards_; i++) 
    {
        std::cout<<deck_[i].print()<<std::endl; 
    }
}



void StandardDeck::shuffle() {
  //std::srand(static_cast<unsigned int>(std::time(nullptr)));
	int swapper = numCards_*3;
    for (int i = 0; i < swapper; i++) 
    {
        int val1 = rand() % numCards_;
        int val2 = rand() % numCards_;
        std::swap(deck_[val1], deck_[val2]);
    }
}

bool StandardDeck::addCard(Card c)
{
  
  if(numCards_ < DECK_SIZE)
  {
    deck_[numCards_]=c;
    numCards_++;
    return true;
  }
    
  else
  {
    return false;
  }
  
}

bool StandardDeck::mergeDecks(StandardDeck& otherDeck, bool shouldShuffle) 
{
  if(numCards_ + otherDeck.numCards_ <=DECK_SIZE)
  {
    for(int i=0; i<otherDeck.numCards_; i++)
    {
      deck_[numCards_]=otherDeck.deck_[i];
      numCards_++;
    }
    otherDeck.numCards_=0;
    if (shouldShuffle == true)
    {
      shuffle();
    }
  }
    return false;
}

Card StandardDeck::dealCard()
{    
	if(numCards_>0)
    {
      numCards_--;
      return deck_[numCards_];
    }
    return Card();
}
  
Card StandardDeck::getTop()
{
    return deck_[numCards_-1];
}

Card StandardDeck::getSecondFromTop()
{
    return deck_[numCards_-2];
}

Card StandardDeck::getThirdFromTop()
{
    return deck_[numCards_-3];
}