// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rkapadia
#include <iostream>
#include "standardDeck.h"
#include "nonStandardDeck.h"
//valgrind --log-file=valgrind.txt War.exe
//cat valgrind.txt

//This is the simulate standard deck function. It will simulate war with a normal deck.
void simulateStandard(){
  int wins1 = 0;
  int wins2 = 0;
  int tie=0;
  int score1=0;
  int score2=0;
  for (int j = 0; j < 50; j++) 
  {
    //std::cout<<"______________ROUND_________________"<<std::endl;
    StandardDeck* dealingDeck = new StandardDeck();
    dealingDeck->initializeDeck();
    dealingDeck->shuffle();
    //dealingDeck->printDeck();
    StandardDeck* player1 = new StandardDeck();
    StandardDeck* player2 = new StandardDeck();
    StandardDeck* battleground = new StandardDeck();
    for (int i = 0; i < 26; i++) 
	{
      player1->addCard(dealingDeck->dealCard());
      player2->addCard(dealingDeck->dealCard());
    }
    //std::cout<<"Player1: "<<std::endl;
    //std::cout<<"Player1: "<<std::endl;
	 //player1->printDeck();
    //std::cout<<"Player2: "<<std::endl;
    //std::cout<<"Player2: "<<std::endl;
    //player2->printDeck();
    //break;
    Card holder;
    Card place;
    while (!player1->isEmpty() && !player2->isEmpty())
	{
      Card card1 = player1->dealCard();
      //std::cout<<"Card1: "<<card1.print()<<std::endl;
      battleground->addCard(card1);
      if (card1.getFace() == holder.getFace()) 
      {
        player1->mergeDecks(*battleground, true);
        card1 = player1->dealCard();
        //std::cout<<"Player 1 wins war and places this: Card1: "<<card1.print()<<std::endl;
        battleground->addCard(card1);
      }
      Card card2 = player2->dealCard();
      //std::cout<<"Card2: "<<card2.print()<<std::endl;
      battleground->addCard(card2);
      holder=card2;
      if (card2.getFace() == battleground->getSecondFromTop().getFace())
      {
        player2->mergeDecks(*battleground, true);
        card2 = player2->dealCard();
        //std::cout<<"Player 2 wins war and places this: Card2: "<<card2.print()<<std::endl;
        battleground->addCard(card2);
        holder=place;
      }
      /*if (card1.getFace() == holder.getFace()) 
      {
        player1->mergeDecks(*battleground, true);
        std::cout<<"Player 1 wins war and places on the next line"<<std::endl;
      }*/
    }
    //std::cout<<player1->getNumCards()<<std::endl;
    //std::cout<<player2->getNumCards()<<std::endl;
     if (player1->isEmpty()) 
	 {
       wins2++;
	   score2+=player2->getNumCards();
     }
     else if (player2->isEmpty()) 
	 {
       wins1++;
	   score1+=player1->getNumCards();
     }
   	 delete dealingDeck;
     delete player1;
     delete player2;
     delete battleground;
	 }
     if(wins1>wins2)
     {
 	   std::cout<<"Player 1 was the champion with "<< wins1 << " victories versus Player 2"<<std::endl;
     }
     else if(wins2>wins1)
     {
 	   std::cout<<"Player 2 was the champion with "<< wins2 << " victories versus Player 1"<<std::endl;
     }
	 if(wins2==wins1)
	 {
		 std::cout<<"It's a tie!"<<std::endl;
	 }
     std::cout << "Player 1 wins: " << wins1 << " Average score: "<< score1/wins1<< std::endl;
     std::cout << "Player 2 wins: " << wins2 << " Average score: "<< score2/wins2<< std::endl;
}
//This is the opposite of the function above. It will read in a text file and run the game.
void simulateNonStandard()
{
    int wins1 = 0;
    int wins2 = 0;
    int tie=0;
    int score1=0;
    int score2=0;
	/*NonStandardDeck * dealingDeck= new NonStandardDeck();
	NonStandardDeck* player1 = new NonStandardDeck();
    NonStandardDeck* player2 = new NonStandardDeck();
	dealingDeck->initializeDeck();
	std::cout<<"Dealing Deck"<<std::endl;
	dealingDeck->printDeck();
	int numCardsToDistribute = dealingDeck->getNumCards() / 2;
	bool distributeExtraCard = (dealingDeck->getNumCards() % 2) == 1;
    for (int i = 0; i < numCardsToDistribute; i++)
	{
      player1->addCard(dealingDeck->dealCard());
      player2->addCard(dealingDeck->dealCard());
    }
	
	if (distributeExtraCard) {
        player1->addCard(dealingDeck->dealCard());
		
	    // Distribute the extra card to either player1 or player2
	    /*if (rand() % 2 == 0) {
	        player1->addCard(dealingDeck->dealCard());
	    } else {
	        player2->addCard(dealingDeck->dealCard());
	    }
	}
	std::cout<<"Player 1"<<std::endl;
	//player1->displayCard(0);
	player1->printDeck();
	std::cout<<"Player 2"<<std::endl;
	player2->printDeck();*/
	
	for (int j = 0; j < 50; j++) {
		NonStandardDeck * dealingDeck= new NonStandardDeck();
		dealingDeck->initializeDeck();
		dealingDeck->shuffle();
		//std::cout<<"___________________________________________________"<<std::endl;
		//dealingDeck->printDeck();
		//std::cout<<"___________________________________________________"<<std::endl;
		NonStandardDeck* player1 = new NonStandardDeck();
		NonStandardDeck* player2 = new NonStandardDeck();
		NonStandardDeck* battleground = new NonStandardDeck();
		int numCardsToDistribute = dealingDeck->getNumCards() / 2;
		bool distributeExtraCard = (dealingDeck->getNumCards() % 2) == 1;
		if (numCardsToDistribute > 0) 
		{
	    	for (int i = 0; i < numCardsToDistribute; i++)
			{
			  player1->addCard(dealingDeck->dealCard());
	      	  player2->addCard(dealingDeck->dealCard());
	    	}
		}
		if (distributeExtraCard) 
		{
		    if (rand() % 2 == 0) 
			{
		      player1->addCard(dealingDeck->dealCard());
		    } 
			else 
			{
		      player2->addCard(dealingDeck->dealCard());
			}
		 }
      Card holder;
      Card place;
      while (!player1->isEmpty() && !player2->isEmpty())
	  {
        Card card1 = player1->dealCard();
      	//std::cout<<"Card1: "<<card1.print()<<std::endl;
        battleground->addCard(card1);
        if (card1.getFace() == holder.getFace()) 
        {
          player1->mergeDecks(*battleground, true);
          card1 = player1->dealCard();
          //std::cout<<"Player 1 wins war and places this: Card1: "<<card1.print()<<std::endl;
          battleground->addCard(card1);
        }
        Card card2 = player2->dealCard();
      	//std::cout<<"Card2: "<<card2.print()<<std::endl;
        battleground->addCard(card2);
        holder=card2;
        if (card2.getFace() == battleground->getSecondFromTop().getFace())
        {
        
          player2->mergeDecks(*battleground, true);
          card2 = player2->dealCard();
          //std::cout<<"Player 2 wins war and places this: Card2: "<<card2.print()<<std::endl;
          battleground->addCard(card2);
          holder=place;
        }
      }
       if (player1->isEmpty()) 
	   {
         wins2++;
  	   	 score2+=player2->getNumCards();
       }
       else if (player2->isEmpty()) 
	   {
         wins1++;
  	     score1+=player1->getNumCards();
       }

       delete dealingDeck;
       delete player1;
       delete player2;
       delete battleground;
  	 }
     if(wins1>wins2)
     {
 	   std::cout<<"Player 1 was the champion with "<< wins1 << " victories versus Player 2"<<std::endl;
     }
     else if(wins2>wins1)
     {
 	   std::cout<<"Player 2 was the champion with "<< wins2 << " victories versus Player 1"<<std::endl;
     }
	 if(wins2==wins1)
	 {
		 std::cout<<"It's a tie!"<<std::endl;
	 }
  
    std::cout << "Player 1 wins: " << wins1 << " Average score: "<< score1/wins1<< std::endl;
    std::cout << "Player 2 wins: " << wins2 << " Average score: "<< score2/wins2<< std::endl;
}


int main() {
	srand(time(NULL));
	simulateStandard();
	simulateNonStandard();
    
	return 0;
}