#ifndef PLAYER_2_H
#define PLAYER_2_H

#include "Player 1.h"
#include "Hand-and-Foot Cards.h"

// Create a class for player one that inherits data from the "Cards" class
class Player2: public Cards
{
private:
	vector<string> PlayedCardsForPlayer2; // Declares a vector that will represent the cards that player 2 puts down
	int Player2Books; // Declares a variable that will keep track of the number of books the player has
	int OverallPlayer2Score; // Decalres a variable that will keep track of the points that player 2 has

public:
	Player2(); // Default constructor for the class
	void DisplayPlayer2Hand(); // Displays the cards that is in the Hand of Player 2
	void OrganizePlayer2Hand(); // Organizes the cards in player 2's Hand
	void Player2DrawsFromTheDeckToHand(); // Takes cards from the deck and adds them to the Hand of Player 2
	void Player2DrawsFromDiscardPileToHand(string); // Takes cards from the discard pile and adds them to the Hand of Player 2
	string Player2DiscardsFromHand(); // Takes one card from the Hand of the Player and adds it to the discard pile
	
	int CheckPointsInPlayer2HandForDrawingFromDiscardPile(string); // Checks to see if the player has enough points to draw from the discard pile
	int CheckPointsInPlayer2HandForPuttingDownCards(); // Checks to see if the player has enogh points to put down cards from their Hand

	bool CheckPlayer2HandForTopDiscardCardTwinMatch(string); // Checks to see if the player has two of the same cards, in their Hand, as the card on the top of the discard pile
	bool CheckPlayer2FootForTopDiscardCardTwinMatch(string); // Checks to see if the player has two of the same cards, in their Foot, as the card on the top of the discard pile

	void Player2PuttingDownCardsFromHand(); // Puts cards down from the Hand of Player 2
	
	int Player2HandSize(); // Returns the number of cards in the Hand of Player 2
	
	void OrganizeAndDisplayPlayer2Cards(); // Organizes and displays the cards that the player has put down
	
	void DisplayPlayer2Foot(); // Displays the cards that is in the Foot of Player 2
	void OrganizePlayer2Foot(); // Organizes the cards in player 2's Foot
	void Player2DrawsFromTheDeckToFoot(); // Takes cards from the deck and adds them to the Foot of Player 2
	void Player2DrawsFromDiscardPileToFoot(string); // Takes cards from the discard pile and adds them to the Foot of Player 2
	void Player2PuttingDownCardsFromFoot(); // Checks to see if the player has enogh points to put down cards from their Foot
	string Player2DiscardsFromFoot(); // Takes one card from the Hand of the Player and adds it to the discard pile
	
	void CheckNumberOfBooksForPlayer2(); // This will check to see how many books the player has managed to make
	int AddUpPointsFromBooksForPlayer2(); // This will add up the value of the books that the player made and return that value

	int Player2FootSize(); // Returns the number of cards in the Hand of Player 2

};
#endif