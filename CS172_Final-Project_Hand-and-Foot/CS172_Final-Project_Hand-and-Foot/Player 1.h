#ifndef PLAYERS_H
#define PLAYERS_H

#include "Hand-and-Foot Cards.h"
using namespace std;

// Create a class for player one that inherits data from the "Cards" class
class Player1: public Cards
{
private:
	vector<string> PlayedCardsForPlayer1;  // Declares a vector that will represent the cards that player 1 puts down
	int Player1Books; // Declares a variable that will keep track of the number of books the player has
	int OverallPlayer1Score; // Decalres a variable that will keep track of the points that player 1 has

public:
	Player1(); // Default constructor for the class
	void DisplayPlayer1Hand(); // Displays the cards that is in the Hand of Player 1
	void OrganizePlayer1Hand(); // Organizes the cards in player 1's Hand
	void Player1DrawsFromTheDeckToHand(); // Takes cards from the deck and adds them to the Hand of Player 1
	void Player1DrawsFromDiscardPileToHand(string); // Takes cards from the discard pile and adds them to the Hand of Player 1
	string Player1DiscardsFromHand(); // Takes one card from the Hand of the Player and adds it to the discard pile

	int CheckPointsInPlayer1HandForDrawingFromDiscardPile(string); // Checks to see if the player has enough points to draw from the discard pile
	int CheckPointsInPlayer1HandForPuttingDownCards(); // Checks to see if the player has enogh points to put down cards from their Hand

	bool CheckPlayer1HandForTopDiscardCardTwinMatch(string); // Checks to see if the player has two of the same cards, in their Hand, as the card on the top of the discard pile
	bool CheckPlayer1FootForTopDiscardCardTwinMatch(string); // Checks to see if the player has two of the same cards, in their Foot, as the card on the top of the discard pile

	void Player1PuttingDownCardsFromHand(); // Puts cards down from the Hand of Player 1

	int Player1HandSize(); // Returns the number of cards in the Hand of Player 1

	void OrganizeAndDisplayPlayer1Cards(); // Organizes and displays the cards that the player has put down

	void DisplayPlayer1Foot(); // Displays the cards that is in the Foot of Player 1
	void OrganizePlayer1Foot(); // Organizes the cards in player 1's Foot
	void Player1DrawsFromTheDeckToFoot(); // Takes cards from the deck and adds them to the Foot of Player 1
	void Player1DrawsFromDiscardPileToFoot(string); // Takes cards from the discard pile and adds them to the Foot of Player 1
	void Player1PuttingDownCardsFromFoot(); // Checks to see if the player has enogh points to put down cards from their Foot
	string Player1DiscardsFromFoot(); // Takes one card from the Hand of the Player and adds it to the discard pile

	void CheckNumberOfBooksForPlayer1(); // This will check to see how many books the player has managed to make
	int AddUpPointsFromBooksForPlayer1(); // This will add up the value of the books that the player made and return that value

	int Player1FootSize(); // Returns the number of cards in the Hand of Player 1
};

#endif