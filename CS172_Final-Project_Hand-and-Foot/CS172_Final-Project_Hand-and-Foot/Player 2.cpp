#include "Player 1.h"
#include "Player 2.h"

// Default constructor for the class
Player2::Player2() : Cards(Random)
{
	Player2Books = 0;
	OverallPlayer2Score = 0;
}

// This function will show how many cards, of each kind, are in the Hand of the player
void Player2::OrganizePlayer2Hand()
{
	cout << "PLAYER TWO has ";

	// This loop will go through the cards in the Hand and find a match
	// This loop will reorganize the vector for the Hand of the player so that like cards are right next to each other
	// The loop will end once it goes through the whole vector
	for (int i = 0; i < CardValues.size(); i++)
	{
		string CurrentCard = CardValues.at(i); // Sets the value of "CurrentCard" equal to the current value of "CardValues"
		int COUNT = 0; // Decalres a variable that will keep track of the occurance of a kind of card in the Hand of the player

					   // This loop will run through the Hand of the player to search for any matches to "CurrentCard"
					   // The loop will end once it goes through the entire vector
		for (int j = 0; j < Player2Hand.size(); j++)
		{
			if (CurrentCard == Player2Hand.at(j)) // Executes if a match has been found
			{
				COUNT++; // Increaxses the value of "COUNT"
			}
		}
		if (COUNT == 1) // Executes if only one match was found
		{
			cout << COUNT << " " << CardValues.at(i) << ", "; // Outputs results
		}
		else if (COUNT > 1) // Executes if more than one match was found
		{
			cout << COUNT << " " << CardValues.at(i) << "s, "; // Outputs results
		}
		else if (i == (CardValues.size() - 1) && COUNT >= 1) // Executes if the loop for the CardValues vector has reached the last value
		{
			cout << COUNT << " " << CardValues.at(i) << "."; // Outputs results
		}
	}
	cout << endl;
}

// This function will display the cards that is in the Hand of the player
void Player2::DisplayPlayer2Hand()
{
	OrganizePlayer2Hand(); // Calls the function to organize the Hand of the player

	cout << endl;

	// This loop will go through the Hand of the player and check for like cards
	// This loop will reorganize the vector for the Hand of the player so that like cards are right next to each other
	// The loop will end once it goes throguh the vector
	for (int i = 0; i < Player2Hand.size(); i++)
	{
		string CurrentCard = Player2Hand.at(i); // Makes the value of CurrentCard equal to the current value of the Hand
		int INDEX = i; // Declares a avriable that is eqaul to the value of i
		string SaveCard = ""; // Declares a variable that will svae the value of the Hand if a match has been found

							  // This loop will run through the Hand vector and check for any matches between CurrentCard and the Hand
							  // The loop will end once it goes through the entire Hand
		for (int j = i + 1; j < Player2Hand.size(); j++)
		{
			if (CurrentCard == Player2Hand.at(j)) // Executes if a match has been found
			{
				SaveCard = Player2Hand.at(i + 1); // Saves the value of the next value in the vector (i)
				Player2Hand.at(i + 1) = Player2Hand.at(j); // Makes the value that is in (i + 1) equal to the value at (j)
				Player2Hand.at(j) = SaveCard; // Makes the value at j equal to SaveCard
			}
		}
	}

	cout << "\nThe cards that PLAYER TWO has are in this order: " << endl;

	// This loop will go through the vector for the Hand and display the cards in their new order
	for (int i = 0; i < Player2Hand.size(); i++)
	{
		cout << Player2Hand.at(i) << setw(7); // Outputs the current card
	}
	cout << endl;
}

// This function will check to see if there are two cards that are the smae as the card at the top of the discard pile
bool Player2::CheckPlayer2HandForTopDiscardCardTwinMatch(string TopDiscardCard)
{
	bool Match = false; // Sets a boolian expression that is false by default
	int COUNT = 0; // Declares a variable that will keep track of the occurance of cards that match that of the top discard card

	cout << endl;

	// This loop will go through the Hand vector to search for any matches between the cards in the Hand and the top discard card
	// The loop will end once it has gone through the whole vector
	for (int i = 0; i < Player1Hand.size(); i++)
	{
		if (TopDiscardCard == Player1Hand.at(i)) // Executes if a match has been found
		{
			COUNT++; // Increases the value of COUNT
		}
	}

	if (COUNT >= 2) // Executes if there are two or more matches found in the Hand of the player
	{
		Match = true; // Sets the boolian value to true
		cout << "You have two copies of the card at the top of the discard pile." << endl;
	}
	else // Executes if there are less than two matches found in the Hand of the player
	{
		cout << "You do not have the two copies of the card at the top of the discard pile to qualify "
			<< "for drawing from the discard pile." << endl;
	}

	cout << endl;

	return Match; // Returns the value of Match
}

// This function will check to see if the player has enough points in their hand to pick up from the discard pile
int Player2::CheckPointsInPlayer2HandForDrawingFromDiscardPile(string DiscardCard)
{
	int OverallPoints = 0; // Declares a variable for the overall points that is in the Hand of the player
	int Value = 0; // Declares a variable for the value of a single group of similar card

				   // This loop will run through the vector for the Hand to search for multipe cards of the same kind
				   // The loop will end once it has reached the end of the vector
	for (int i = 0; i < Player1Hand.size(); i++)
	{
		string CurrentCard = Player1Hand.at(i); // Makes the value of CurrentCard equal to that of the current value of the Hand
		int count = 0; // Sets count to 0

					   // This loop will run through the Hand to search for matches
		for (int j = 0; j < Player1Hand.size(); j++)
		{
			if (CurrentCard == Player1Hand.at(j)) // Executes if a match has been found
			{
				count++; // Increases the value of count
			}
		}

		if (count >= 3) // Executes if the value of count is eqaul to or greater than 3
		{
			Value = GetCardValue(Player1Hand.at(i), count); // Gets the value of the current card which will be multipled by the number of ties it occurs in the Hand of the player
			OverallPoints += Value; // takes of value of Value and adds it to the value of OverallPoints
		}
	}
	Value = GetCardValue(DiscardCard, 1); // Gets the value of the card at the top of the discard pile
	OverallPoints += Value; // Adds the value of the discard card to the overallpoint value

	return OverallPoints; // Returns the value of OverallPoints
}


int Player2::CheckPointsInPlayer2HandForPuttingDownCards()
{
	int OverallPoints = 0; // Declares a variable for the overall points that is in the Hand of the player
	int Value = 0; // Declares a variable for the value of a single group of similar card

				   // This loop will run through the vector for the Hand to search for multipe cards of the same kind
				   // The loop will end once it has reached the end of the vector
	for (int i = 0; i < Player1Hand.size(); i++)
	{
		string CurrentCard = Player1Hand.at(i); // Makes the value of CurrentCard equal to that of the current value of the Hand
		int count = 0; // Sets count to 0

					   // This loop will run through the Hand to search for matches
		for (int j = 0; j < Player1Hand.size(); j++)
		{
			if (CurrentCard == Player1Hand.at(j)) // Executes if a match has been found
			{
				count++; // Increases the value of count
			}
		}

		if (count >= 3) // Executes if the value of count is eqaul to or greater than 3
		{
			Value = GetCardValue(Player1Hand.at(i), count); // Gets the value of the current card which will be multipled by the number of ties it occurs in the Hand of the player
			OverallPoints += Value; // takes of value of Value and adds it to the value of OverallPoints
		}
	}

	return OverallPoints; // Returns the value of OverallPoints
}


// This function is for when the player draws cards from the top of the draw deck
void Player2::Player2DrawsFromTheDeckToHand()
{
	cout << endl;

	cout << "PLAYER TWO: You drew ";

	// This loop will run only twice so that the player will only get 2 cards from the draw deck
	for (int i = 0; i < 2; i++)
	{
		cout << "a " << DrawDeck.back(); // outputs the card from teh darw deck
		Player1Hand.push_back(DrawDeck.back()); // Saves the card into the vector for the Hand
		DrawDeck.pop_back(); // Deletes the value that was saved in the Hand vector

		if (i == 0) // Executes if this is the first time the loop ran
		{
			cout << " and a ";
		}
	}
	cout << endl;
}

// This function will simulate the player drawing from the discard pile
void Player2::Player2DrawsFromDiscardPileToHand(string DiscardCard)
{
	Player2Hand.push_back(DiscardCard); // Saves the value of the discard pile into the Hand of the player
}

// This function is for discarding 1 card from the Hand of the player
string Player2::Player2DiscardsFromHand()
{
	int EX = rand() % Player2Hand.size(); // Declares a varaible for showing an example (which is generated at random)

	int INDEX = 0; // Declares a variable for user input
	string SaveCard = ""; // Declares a varaiable for saving the card taht is at the end of the Hand vector

	cout << endl;

	cout << "Which card are you going to discard? (0 - " << (Player2Hand.size() - 1) << ")" << endl; // Shows the user the range
	cout << "EXAMPLE: Input a " << EX << " to discard " << Player2Hand.at(EX) << endl; // Shows the user an example
	cin >> INDEX; // get input from the user

	cout << "PLAYER ONE discarded a " << Player2Hand.at(INDEX) << endl; // Shows the player what they discarded

	SaveCard = Player2Hand.at(INDEX); // Saves the value of the card that they chose
	Player2Hand.at(INDEX) = Player2Hand.back(); // makes the card at the spot the player chose equal to that of the value in the back of the vector
	Player2Hand.pop_back(); // deletes the last element in the vector

	return SaveCard; //Returns the value of SaveCard
}

// This function will simulate the player putting down cards 
void Player2::Player2PuttingDownCardsFromHand()
{
	int NumberOfCards = 0; // Declares a variable for user input

	cout << "How many cards do you want to put down? You can only put down " << (Player2Hand.size() / 2) << " cards at one time" << endl;
	cin >> NumberOfCards; // Get input from the user

	if (NumberOfCards == 0) // Executes if the player inputs a 0
	{
		cout << "PLAYER ONE: You didn't put down any cards" << endl;
	}
	else if (NumberOfCards > 0) // Executes if the player input a number greater than one
	{
		// This loop will allow the user in play the number of cards that he indicated eariler
		for (int i = 0; i < NumberOfCards; i++)
		{
			int SPOT = Player2Hand.size(); // Declares a variable that is equal to the size of the Hand vector, minus one so that that value will get deleted
			int CHOICE = 0; // Declares a variable for user input

			cout << "Which card do you want to put down?" << endl;
			cin >> CHOICE; // Get input from the user

			string BACK = Player2Hand.back();// makes the variable BACK eqaul to the value that is at the back of the Hand vector
			PlayedCardsForPlayer2.push_back(Player2Hand.at(CHOICE)); // Saves the card that the layer choose to the PlayedCards vector
			Player2Hand.back() = Player2Hand.at(CHOICE); // Sends the crad of the players choice to the back of the vector
			Player2Hand.at(CHOICE) = BACK; // Saves the value that was preivously at the back to the spot that was the spot of the card that the player choose
			Player2Hand.pop_back(); // Deleets the last element in the vector
		}

		cout << endl;
	}
}

// This function will organize and display the cards that have been put down by the player
void Player2::OrganizeAndDisplayPlayer2Cards()
{
	if (PlayedCardsForPlayer2.size() > 0) // Executes if there are values stored in the Playedcards vector
	{
		cout << "PLAYED CARDS FOR PLAYER TWO: ";

		// This loop will go through the values that are stored in CardValues to search for matches between CardValues and PlayedCards
		// The loop will end when goes to the end of the CardValues vector
		for (int i = 0; i < CardValues.size(); i++)
		{
			string CurrentCard = CardValues.at(i); // Sets the value of CurrentCard to teh current value of the CardValue vector
			int COUNT = 0; // Sets the variable that keeps track of the occurances of matches to 0

						   // Thsi loop will go through the PlayedCards vector to search for matches between the value stored in there to CurrentCard
			for (int j = 0; j < PlayedCardsForPlayer2.size(); j++)
			{
				if (CurrentCard == PlayedCardsForPlayer2.at(j)) // Executes if a match has been found
				{
					COUNT++; // Increases the value of COUNT
				}
			}
			if (COUNT == 1) // Executes if the value of COUNT is equal to 1
			{
				cout << COUNT << " " << CardValues.at(i) << ", "; // Displays results
			}
			else if (COUNT > 1) // Exexutes if the value of COUNT is greater than 1
			{
				cout << COUNT << " " << CardValues.at(i) << "s, "; // Displays results
			}
			else if (i == (CardValues.size() - 1) && COUNT > 1) // Executes if the loop is on the last run and the value of COUNT is eqaul to or greater than 1
			{
				cout << COUNT << " " << CardValues.at(i) << "."; // Displays results
			}
		}
	}
}

// This function will return the size of the Hand vector
int Player2::Player2HandSize()
{
	return Player2Hand.size();
}



/************************************************************************************************************/
/************************************************************************************************************/
/************************************************************************************************************/
/************************************************************************************************************/
/************************************************************************************************************/

// This function is for display in the cards that the player has in the Foot
void Player2::DisplayPlayer2Foot()
{
	OrganizePlayer2Foot();

	cout << endl;

	// This loop will go through the Hand of the player and check for like cards
	// This loop will reorganize the vector for the Hand of the player so that like cards are right next to each other
	// The loop will end once it goes throguh the vector
	for (int i = 0; i < Player2Hand.size(); i++)
	{
		string CurrentCard = Player2Hand.at(i); // Makes the value of CurrentCard equal to the current value of the Hand
		int INDEX = i; // Declares a avriable that is eqaul to the value of i
		string SaveCard = ""; // Declares a variable that will svae the value of the Hand if a match has been found

							  // This loop will run through the Hand vector and check for any matches between CurrentCard and the Hand
							  // The loop will end once it goes through the entire Hand
		for (int j = i + 1; j < Player2Hand.size(); j++)
		{
			if (CurrentCard == Player2Hand.at(j)) // Executes if a match has been found
			{
				SaveCard = Player2Hand.at(i + 1); // Saves the value of the next value in the vector (i)
				Player2Hand.at(i + 1) = Player2Hand.at(j); // Makes the value that is in (i + 1) equal to the value at (j)
				Player2Hand.at(j) = SaveCard; // Makes the value at j equal to SaveCard
			}
		}
	}

	cout << "\nThe cards that PLAYER TWO has are in this order: " << endl;

	// This loop will go through the vector for the Hand and display the cards in their new order
	for (int i = 0; i < Player2Hand.size(); i++)
	{
		cout << Player2Hand.at(i) << setw(7); // Outputs the current card
	}
	cout << endl;
}

// This function will organize the cards that are in the player's Foot so that the player will know exactly how many of which card they have in their Foot
void Player2::OrganizePlayer2Foot()
{
	cout << "PLAYER TWO has ";

	// This loop will go through the cards in the Hand and find a match
	// This loop will reorganize the vector for the Hand of the player so that like cards are right next to each other
	// The loop will end once it goes through the whole vector
	for (int i = 0; i < CardValues.size(); i++)
	{
		string CurrentCard = CardValues.at(i); // Sets the value of "CurrentCard" equal to the current value of "CardValues"
		int COUNT = 0; // Decalres a variable that will keep track of the occurance of a kind of card in the Hand of the player

		// This loop will run through the Hand of the player to search for any matches to "CurrentCard"
		// The loop will end once it goes through the entire vector
		for (int j = 0; j < Player2Hand.size(); j++)
		{
			if (CurrentCard == Player2Hand.at(j)) // Executes if a match has been found
			{
				COUNT++; // Increaxses the value of "COUNT"
			}
		}
		if (COUNT == 1) // Executes if only one match was found
		{
			cout << COUNT << " " << CardValues.at(i) << ", "; // Outputs results
		}
		else if (COUNT > 1) // Executes if more than one match was found
		{
			cout << COUNT << " " << CardValues.at(i) << "s, "; // Outputs results
		}
		else if (i == (CardValues.size() - 1) && COUNT >= 1) // Executes if the loop for the CardValues vector has reached the last value
		{
			cout << COUNT << " " << CardValues.at(i) << "."; // Outputs results
		}
	}
	cout << endl;
}

// This function will simulate the player drawing 2 cards from the deck and putting them into their Foots
void Player2::Player2DrawsFromTheDeckToFoot()
{
	cout << endl;

	cout << "PLAYER TWO: You drew ";

	// This loop will run only twice so that the player will only get 2 cards from the draw deck
	for (int i = 0; i < 2; i++)
	{
		cout << "a " << DrawDeck.back(); // outputs the card from teh darw deck
		Player1Hand.push_back(DrawDeck.back()); // Saves the card into the vector for the Hand
		DrawDeck.pop_back(); // Deletes the value that was saved in the Hand vector

		if (i == 0) // Executes if this is the first time the loop ran
		{
			cout << " and a ";
		}
	}
	cout << endl;
}

// This function will check to see if the player has two of the same kind, in their Foot, of card as the one that is on the topof the discard pile
bool Player2::CheckPlayer2FootForTopDiscardCardTwinMatch(string TopDiscardCard)
{
	bool Match = false; // Sets a boolian expression that is false by default
	int COUNT = 0; // Declares a variable that will keep track of the occurance of cards that match that of the top discard card

	cout << endl;

	// This loop will go through the Hand vector to search for any matches between the cards in the Hand and the top discard card
	// The loop will end once it has gone through the whole vector
	for (int i = 0; i < Player1Hand.size(); i++)
	{
		if (TopDiscardCard == Player1Hand.at(i)) // Executes if a match has been found
		{
			COUNT++; // Increases the value of COUNT
		}
	}

	if (COUNT >= 2) // Executes if there are two or more matches found in the Hand of the player
	{
		Match = true; // Sets the boolian value to true
		cout << "You have two copies of the card at the top of the discard pile." << endl;
	}
	else // Executes if there are less than two matches found in the Hand of the player
	{
		cout << "You do not have the two copies of the card at the top of the discard pile to qualify "
			<< "for drawing from the discard pile." << endl;
	}

	cout << endl;

	return Match; // Returns the value of Match
}

// This function will save the card from the discard pile
void Player2::Player2DrawsFromDiscardPileToFoot(string DiscardCard)
{
	Player2Foot.push_back(DiscardCard); // Saves the card from the discard pile into the players Foot
}

// This function will simulate the player discarding cards from their Foot
string Player2::Player2DiscardsFromFoot()
{
	int EX = rand() % Player1Hand.size(); // Declares a varaible for showing an example (which is generated at random)

	int INDEX = 0; // Declares a variable for user input
	string SaveCard = ""; // Declares a varaiable for saving the card taht is at the end of the Hand vector

	cout << endl;

	cout << "Player TWO: Which card will you discard? " << endl;

	if (Player2Foot.size() == 1) // This will execute if the size of the vector is equal to one
	{
		CheckNumberOfBooksForPlayer2(); // Calls the function that will check the number of books that the player currently has

		if (Player2Books >= 3) // Executes if the player has 3 or more books
		{
			cout << "You have enough books to go out.\n" << endl;

			cout << "Which card are you going to discard? (0 - " << (Player2Foot.size() - 1) << ")" << endl; // Shows the user the range
			cout << "EXAMPLE: Input a " << EX << " to discard " << Player2Foot.at(EX) << endl; // Shows the user an example
			cin >> INDEX; // Gets input from the user

			cout << "PLAYER TWO discarded a " << Player2Foot.at(INDEX) << endl; // Shows the player what they discarded

			SaveCard = Player2Foot.at(INDEX); // Saves the value of the card that they chose
			Player2Foot.at(INDEX) = Player2Foot.back(); // makes the card at the spot the player chose equal to that of the value in the back of the vector
			Player2Foot.pop_back(); // deletes the last element in the vector
		}
		else if (Player2Books < 3) // Executes if the player has less than 3 books
		{
			Player2Books = 0; // Resets the number of books to zero to avoid checking problems in the future
			cout << "You do not have the number of books required to go out. Therefore you cannot go out. "
				<< "You will be given 3 cards from the ones that you have played." << endl;

			// This loop will give the player 3 cards from their played cards so that they can discard cards
			for (int i = 0; i < 3; i++)
			{
				Player2Foot.push_back(PlayedCardsForPlayer2.back()); // Saves value of played card to the Foot
				PlayedCardsForPlayer2.pop_back(); // Delest that card from the vector
			}

			cout << "Which card are you going to discard? (0 - " << (Player2Foot.size() - 1) << ")" << endl; // Shows the user the range
			cout << "EXAMPLE: Input a " << EX << " to discard " << Player2Foot.at(EX) << endl; // Shows the user an example
			cin >> INDEX; // Gets input from the user

			cout << "PLAYER TWO discarded a " << Player2Foot.at(INDEX) << endl; // Shows the player what they discarded

			SaveCard = Player2Foot.at(INDEX); // Saves the value of the card that they chose
			Player2Foot.at(INDEX) = Player2Foot.back(); // makes the card at the spot the player chose equal to that of the value in the back of the vector
			Player2Foot.pop_back(); // deletes the last element in the vector
		}
	}
	else
	{
		cout << "Which card are you going to discard? (0 - " << (Player2Foot.size() - 1) << ")" << endl; // Shows the user the range
		cout << "EXAMPLE: Input a " << EX << " to discard " << Player2Foot.at(EX) << endl; // Shows the user an example
		cin >> INDEX; // get input from the user

		cout << "PLAYER TWO discarded a " << Player2Foot.at(INDEX) << endl; // Shows the player what they discarded

		SaveCard = Player2Foot.at(INDEX); // Saves the value of the card that they chose
		Player2Foot.at(INDEX) = Player2Foot.back(); // makes the card at the spot the player chose equal to that of the value in the back of the vector
		Player2Foot.pop_back(); // deletes the last element in the vector
	}

	return SaveCard; // Returns the value of SaveCard
}

// This function will simulate the player putting down cards from their Foot
void Player2::Player2PuttingDownCardsFromFoot()
{
	int NumberOfCards = 0; // Declares a variable for user input

	cout << "How many cards do you want to put down? You can only put down " << (Player2Foot.size() / 2) << " cards at one time" << endl;
	cin >> NumberOfCards; // Get input from the user

	if (NumberOfCards == 0) // Executes if the player inputs a 0
	{
		cout << "PLAYER ONE: You didn't put down any cards" << endl;
	}
	else if (NumberOfCards > 0) // Executes if the player input a number greater than one
	{
		// This loop will allow the user in play the number of cards that he indicated eariler
		for (int i = 0; i < NumberOfCards; i++)
		{
			int SPOT = Player2Foot.size(); // Declares a variable that is equal to the size of the Hand vector, minus one so that that value will get deleted
			int CHOICE = 0; // Declares a variable for user input

			cout << "Which card do you want to put down?" << endl;
			cin >> CHOICE; // Get input from the user

			string BACK = Player2Foot.back();// makes the variable BACK eqaul to the value that is at the back of the Hand vector
			PlayedCardsForPlayer2.push_back(Player2Foot.at(CHOICE)); // Saves the card that the layer choose to the PlayedCards vector
			Player2Foot.back() = Player2Foot.at(CHOICE); // Sends the crad of the players choice to the back of the vector
			Player2Foot.at(CHOICE) = BACK; // Saves the value that was preivously at the back to the spot that was the spot of the card that the player choose
			Player2Foot.pop_back(); // Deleets the last element in the vector
		}

		cout << endl;
	}
}

// This function will check the cards that the player has put down and check to see if there are any books among the Played Cards 
void Player2::CheckNumberOfBooksForPlayer2()
{
	cout << "PLAYED CARDS FOR PLAYER TWO: ";

	// This loop will run through the CardValues vector to check for similar cards that have been played and count those occurences 
	// The loop will end when it reaches teh end of the CardVales vector
	for (int i = 0; i < CardValues.size(); i++)
	{
		string CurrentCard = CardValues.at(i); // sets the value of CurrentCard to the current value of the CardValue vector
		int COUNT = 0; // Sets the value of COUNT to 0

					   // This loop will run through the PlayedCards vector to check for cards that match CurrentCard
					   // The loop will end when it reaches the end of the PlayedCards vector
		for (int j = 0; j < PlayedCardsForPlayer2.size(); j++)
		{
			if (CurrentCard == PlayedCardsForPlayer2.at(j)) // Executes if a match has been found
			{
				COUNT++; // Increases the value of COUNT
			}
		}

		if (COUNT >= 7) // Executes if the value of COUNT is equal to or greater than 7
		{
			Player2Books++; // Increases the value of Player1Books
			cout << "You have a book of " << CardValues.at(i) << endl; // Outputs results
		}
	}
	cout << "PLAYER ONE: You have " << Player2Books << "s." << endl; // Output results
	cout << "You need 3 books to go out." << endl;
}

// This function will calculate and return the score the player got for that round
int Player2::AddUpPointsFromBooksForPlayer2()
{
	return OverallPlayer2Score = Player2Books * 500; //Each book is worth 500 points
}

// This function will return the size of the Foot vector
int Player2::Player2FootSize()
{
	return Player1Foot.size();
}