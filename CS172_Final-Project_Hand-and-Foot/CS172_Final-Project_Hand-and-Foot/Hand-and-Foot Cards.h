#ifndef HAND_AND_FOOT_CARDS_H
#define HAND_AND_FOOT_CARDS_H

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <vector>
using namespace std;

// This class is responsible for making the individual cards and decks and will shuffle those decks
class Cards
{
protected:
	int Random; // Declares a avriable that will represent the number or times that the cards will be shuffled
	string King, Queen, Jack, Ten, Nine, Eight, Seven, Six, Five, Four, Three, Two, Ace; // Declares variables for each card
	vector<string> CardValues; // Declares a vector that will store the value of each cards 

	vector<string> DrawDeck; // Declares a vector that will represent the deck from which the players will draw from

	vector<string> Player1Hand; // Declares a vector that will store the cards in the Hand of player 1
	vector<string> Player1Foot; // Declares a vector that will store the cards in the Foot of player 1
	vector<string> Player2Hand; // Declares a vector that will store the cards in the Hand of player 2
	vector<string> Player2Foot; // Declares a vector that will store the cards in the Foot of player 2

public:
	Cards(); // Default constructor
	Cards(int); // The constructor that will be used in "main" for creatign the cards and decks and shuffling the decks together
	int GetCardValue(string, int); // This is for returning the point value of a specific card
};

#endif