#include "Hand-and-Foot Cards.h"
using namespace std;

// This is the default constructor
Cards::Cards()
{
	King = "King"; // Creates a string of the name of the card to represent the card itself  
	Queen = "Queen"; // Creates a string of the name of the card to represent the card itself  
	Jack = "Jack"; // Creates a string of the name of the card to represent the card itself  
	Ten = "Ten"; // Creates a string of the name of the card to represent the card itself  
	Nine = "Nine"; // Creates a string of the name of the card to represent the card itself  
	Eight = "Eight"; // Creates a string of the name of the card to represent the card itself  
	Seven = "Seven"; // Creates a string of the name of the card to represent the card itself  
	Six = "Six"; // Creates a string of the name of the card to represent the card itself  
	Five = "Five"; // Creates a string of the name of the card to represent the card itself  
	Four = "Four"; // Creates a string of the name of the card to represent the card itself 
	Three = "Three"; // Creates a string of the name of the card to represent the card itself 
	Two = "Two"; // Creates a string of the name of the card to represent the card itself
	Ace = "Ace"; // Creates a string of the name of the card to represent the card itself  
}


Cards::Cards(int X)
{
	King = "King"; // Creates a string of the name of the card to represent the card itself 
	Queen = "Queen"; // Creates a string of the name of the card to represent the card itself 
	Jack = "Jack"; // Creates a string of the name of the card to represent the card itself 
	Ten = "Ten"; // Creates a string of the name of the card to represent the card itself 
	Nine = "Nine"; // Creates a string of the name of the card to represent the card itself 
	Eight = "Eight"; // Creates a string of the name of the card to represent the card itself 
	Seven = "Seven"; // Creates a string of the name of the card to represent the card itself 
	Six = "Six"; // Creates a string of the name of the card to represent the card itself 
	Five = "Five"; // Creates a string of the name of the card to represent the card itself 
	Four = "Four"; // Creates a string of the name of the card to represent the card itself 
	Three = "Three"; // Creates a string of the name of the card to represent the card itself 
	Two = "Two"; // Creates a string of the name of the card to represent the card itself 
	Ace = "Ace"; // Creates a string of the name of the card to represent the card itself 

	CardValues.push_back(King); // Stores the name of the card into the "CardValue" vector
	CardValues.push_back(Queen); // Stores the name of the card into the "CardValue" vector
	CardValues.push_back(Jack); // Stores the name of the card into the "CardValue" vector
	CardValues.push_back(Ten); // Stores the name of the card into the "CardValue" vector
	CardValues.push_back(Nine); // Stores the name of the card into the "CardValue" vector
	CardValues.push_back(Eight); // Stores the name of the card into the "CardValue" vector
	CardValues.push_back(Seven); // Stores the name of the card into the "CardValue" vector
	CardValues.push_back(Six); // Stores the name of the card into the "CardValue" vector
	CardValues.push_back(Five); // Stores the name of the card into the "CardValue" vector
	CardValues.push_back(Four); // Stores the name of the card into the "CardValue" vector
	CardValues.push_back(Three); // Stores the name of the card into the "CardValue" vector
	CardValues.push_back(Two); // Stores the name of the card into the "CardValue" vector
	CardValues.push_back(Ace); // Stores the name of the card into the "CardValue" vector
	

	/*********************************************************************************************************/
	int Random = X; // This variable will determine how many times the decks will be shuffled

	// This loop is for making decks of cards
	// The loop will end once 7 decks have been created
	for (int q = 0; q < 7; q++)
	{
		// This loop will run through all of the card values that are stored in the "CardValues" vector
		for (int i = 0; i < CardValues.size(); i++)
		{
			// This loop will ensure that for every value that is stored in "CardValues", there will be 4 copies of it per deck
			for (int j = 0; j < 4; j++)
			{
				// This will store the current card value into the "DrawDeck" every time the current loop executes
				DrawDeck.push_back(CardValues.at(i));
			}
		}
	}
	/************************************************************************************************************/
	
	// This will execute if the number that determines how many times the decks will be shuffled is under 50 
	while (Random < 50)
	{
		Random = rand() % 200; // Rerandomizes the "Random" variable
	}

	// This loop is for shufflign teh cards that are stored in "DrawDeck"
	// This loop will run until the value of "i" reaches the value of "Random"
	for (int j = 0; j < Random; j++)
	{
		vector<string> ShufflePile1; // Creates a vector that will hold half of the values in the vector "v"
		vector<string> ShufflePile2; // Creates a vector that will hold half of the values in the vector "v"
		int mid = ((DrawDeck.size() / 2)); // Declares a avrible that is half the size of "DrawDeck"

		// This loop will saves the values that are in the first half of the "v" vector into the "PILE1" vector
		// The loop will end once "i" is equal to the value of "mid"
		for (int i = 0; i < mid; i++)
		{
			ShufflePile1.push_back(DrawDeck.at(i)); // Saves the value of the "v" vector into the "PILE1" vector
		}

		// This loop will saves the values that are in the second half of the "v" vector into the "PILE2" vector
		// The loop will end once "i" is equal to the size of "v"
		for (int i = mid; i < DrawDeck.size(); i++)
		{
			ShufflePile2.push_back(DrawDeck.at(i)); // Saves the value of the "v" vector into the "PILE2" vector
		}

		DrawDeck.clear(); // Empties the "DrawDeck" vector 

		int Pile = rand() % 2; // Randomizes a value that will choose which "PILE" vector to take a value from

		// This loop will take that values that are stored in the two pile and reenter those values back into the "DrawDeck" vector
		while (ShufflePile1.size() > 0 || ShufflePile2.size() > 0)
		{
			if (Pile == 0 && ShufflePile1.size() > 0) // Executes if "PileChoose" is 0 and if the "PILE1" vector is not empty
			{
				DrawDeck.push_back(ShufflePile1.back()); // Saves the value from the "PILE1" vector into the the "NewOrder" vector
				ShufflePile1.pop_back(); // Removes an element from the "PILE1" vector
				Pile = rand() % 2; // Rerandomizes a value that will choose which "PILE" vector to take a value from
			}

			else if (Pile = 1 && ShufflePile2.size() > 0) // Executes if "PileChoose" is 1 and if the "PILE2" vector is not empty
			{
				DrawDeck.push_back(ShufflePile2.back()); // Saves the value from the "PILE2" vector into the the "NewOrder" vector
				ShufflePile2.pop_back(); // Removes an element from the "PILE2" vector
				Pile = rand() % 2; // Rerandomizes a value that will choose which "PILE" vector to take a value from
			}
		}
	}
	/**********************************************************************************************************************/
	vector<string> Player1FirstDraw; // Declares a vector that will represent the total number of cards that the player will take from the top of "DrawDeck"
	vector<string> Player2FirstDraw; // Declares a vector that will represent the total number of cards that the player will take from the top of "DrawDeck"

	// This loop will take the top 44 cards from the "DrawDeck" vector
	// These cards will make up the hands and feet of both the players
	for (int i = 0; i < 44; i++)
	{
		if (i < 22) // This executes so that the first half is transfered to a pile for Player 1
		{
			Player1FirstDraw.push_back(DrawDeck.back()); // Transfers the last value in the vector to a pile for Player 1
			DrawDeck.pop_back(); // Deletes the last value in the vector
		}

		else if (i >= 22) // This executes so that the second half is transfered to a pile for Player 2
		{
			Player2FirstDraw.push_back(DrawDeck.back()); // Transfers the last value in the vector to a pile for Player 2
			DrawDeck.pop_back(); // Deletes the last value in the vector
		}
	}

	int ISIZE = Player1FirstDraw.size();
	// This loop will run through the vector that holds the 22 card for player 1 and put half of the vector into the hand and the other half into the foot 
	// This loop will end once it has gone through the whole vector
	for (int i = 0; i < ISIZE; i++)
	{
		if (Player1FirstDraw.size() < 11) // Executes while the size of "Player1FirstDraw" is less than 11
		{
			Player1Hand.push_back(Player1FirstDraw.back()); // Saves the value at the end of the vector to the vector for the Hand of player 1
			Player1FirstDraw.pop_back(); // Deletes the last value in the vector
		}

		else if (Player1FirstDraw.size() >= 11) // Executes if the size of "Player1FirstDarw" is greater than or equal to 11
		{
			Player1Foot.push_back(Player1FirstDraw.back()); // Saves the value at the end of the vector to the vector for the Foot of player 1
			Player1FirstDraw.pop_back(); // Deletes the last value in the vector
		}
	}

	// This loop will run through the vector that holds the 22 card for player 2 and put half of the vector into the hand and the other half into the foot 
	// This loop will end once it has gone through the whole vector
	for (int i = 0; i < ISIZE; i++)
	{
		if (Player2FirstDraw.size() < 11) // Executes while the size of "Player2FirstDraw" is less than 11
		{
			Player2Hand.push_back(Player2FirstDraw.back()); // Saves the value at the end of the vector to the vector for the Hand of player 2
			Player2FirstDraw.pop_back(); // Deletes the last value in the vector
		}

		else if (Player2FirstDraw.size() >= 11) // Executes if the size of "Player2FirstDarw" is greater than or equal to 11
		{
			Player2Foot.push_back(Player2FirstDraw.back()); // Saves the value at the end of the vector to the vector for the Foot of player 2
			Player2FirstDraw.pop_back(); // Deletes the last value in the vector
		}
	}
}

// This function will compare the inputs that the function takes in to the names of the cards 
int Cards::GetCardValue(string Card, int TIMES)
{
	int Value = 0; // Declares a variable that will represent the value of the card that is inpuuted into the function

	// This loop will run through the "CardValues" vector to search for a match to the "Card" input
	// The loop will end once it finds a match
	for (int i = 0; i < CardValues.size(); i++)
	{
		if (Card == CardValues.at(i)) // Executes if the input "Card" match a value in the vector (Which it should no matter what)
		{
			if (i >= 0 && i <= 5) // Executes if the value of "i" is between 0 and 5
			{
				Value = 10 * TIMES; // Calculates the value of the card
				break; // Ends the loop
			}
			else if (i >= 6 && i <= 11) // Executes if the value of "i" is between 6 and 11
			{
				Value = 5 * TIMES; // Calculates the value of the card
				break; // Ends the loop
			}
			else if (i == 12) // Executes if the value of "i" is equal to 12
			{
				Value = 20 * TIMES; // Calculates the value of the card
				break; // Ends the loop
			}
		}
	}

	return Value; // Returns the value of the card
}