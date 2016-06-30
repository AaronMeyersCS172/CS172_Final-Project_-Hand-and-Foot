///////////////////////////////////////////////
// Aaron Meyers
// 6/22/16
// CS172: Final Project: Hand-and-Foot
//////////////////////////////////////////////

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <fstream>
#include "Hand-and-Foot Cards.h"
#include "Player 1.h"
#include "Player 2.h"
using namespace std;

vector<string> DiscardPile; // Declares a vector for storing cards that the players discard from their Hands and Feet
void ShowDiscardPile(); // Prototype for he function that displays the cards that are in the DiscardPile vector

int main()
{
	srand(time(NULL)); // Sets up the puesdo random number generator
	int X = rand() % 200; // Stes up a variable that will be responisble for the number of times that the cards are shuffled together

	int Threshold = 60; // Declares a variable that will establish a point limit that the player swill have to match/exceed in order to put down cards for the first time

	int Player1Score = 0; // Declares a variable that will keep track of the score of a player for the entire game
	int Player2Score = 0; // Declares a variable that will keep track of the score of a player for the entire game

	cout << "WELCOME TO HAND-AND-FOOT\n\n" << endl;

	// Creates a stream that will take the info in the txt file and display it for the user
	// The txt file in question contains the rules for the game
	ifstream Rules("C:\\Users\\Aaron C Meyers\\Desktop\\CS172_Final-Project_Hand-and-Foot\\Hand-and-Foot Rules.txt");

	string Word; // Declares a variable for inputting word from the txt file

	if (Rules.fail()) // Executes if the file does not exist or is not found
	{
		cout << "File does not exist" << endl;
		return 0; // Ends the program
	}

	// This loop will output all of the words that are contained in the txt file
	// This loop will run until the end of the txt file is reached
	while (Rules >> Word)
	{
		getline(Rules, Word, '#'); // Creates a line whenever it encounters a '#'
		cout << Word << " "; // Outputs a word
	}

	Rules.close(); // Closes the input stream
	
	cout << endl;

	// This loop will execute four times to represent a round in the game
	// When the loop ends, the game is ends as well
	for (int i = 0; i < 1; i++)
	{
		Cards C4(X); // Creates a class object and inputs the randomized variable "X" into the object to shuffle the cards "X" number of times
		Player1 P1; // Creates a class object for Player 1
		Player2 P2; // Creates a class object for Player 1

		int CHOICE = 0; // Declares a variable for user input
		int COUNT = 0;

		// This loop will run until one of the players have discarded all of the cards in their Foots, which they can only do if they have the books required to go out
		// When the loop ends, it represents the end of a round
		while (P1.Player1FootSize() > 0 || P2.Player2FootSize() > 0)
		{
			int Player1PutDown = 0; // Declares a variable to track whether or player 1 has put down cards (0 = no, 1 = yes)
			int Player2PutDown = 0; // Declares a variable to track whether or player 2 has put down cards (0 = no, 1 = yes)
			string Discard = ""; // Declares a variable to act as the card that each player discards from their Hand or Foot at the end of their turn
			bool DiscardQualification; // Declares a variable for determining whether or not a player has the cards required to draw from the discard pile

			cout << "PLAYER ONE: Has " << Player1Score << " points total" << endl; // Shows the score of Player 1
			cout << "PLAYER TWO: Has " << Player2Score << " points total" << endl; // Shows the score of Player 2
			cout << "\nThe point threshold is " << Threshold << "\n" << endl; // Shows the minimum number of points that each player will have to have in order to put down cards or draw from the discard pile

			if (P1.Player1HandSize() != 0) // Executes if the Hand of Player 1 is not empty
			{
				P1.DisplayPlayer1Hand(); // Calls the function that will display the Hand of player 1
				cout << "\n" << endl;
				ShowDiscardPile(); // Calls the function that will display the cards in the disard pile
				cout << endl;


				cout << "Player One: Do you want to (1) draw from the deck or (2) take the top five card on the discard pile? " << endl;
				cin >> CHOICE; // Get data from the user

				if (CHOICE == 1)
				{
					P1.Player1DrawsFromTheDeckToHand(); // Calls the function for adding cards from the darw deck to the Hand of player 1
					P1.DisplayPlayer1Hand(); // Calls the function that will display the Hand of player 1
					cout << "PLAYER ONE: DO you want to put down cards? (1) Yes and (2) No" << endl;
					cin >> CHOICE; // Get data from the user

					if (CHOICE == 1) // Exeutes if the player inputs a 1 for putting down cards
					{
						if (Player1PutDown == 0) // This executes if the player has not put down any cards
						{
							int PointTotal = P1.CheckPointsInPlayer1HandForPuttingDownCards(); // Calls the function that will determine if the player has the points, in thier Hand, required to put down cards

							if (PointTotal < Threshold) // This executes if the value of PoitTotal does not meet or exceed the value 
							{
								cout << endl;
								cout << "Player One: You do not have the points required to play down cards." << endl;
								cout << "You have " << PointTotal << " while you need " << Threshold << " to put down cards" << endl;// Shows the results to the player 

								cout << endl;

								P1.Player1DrawsFromTheDeckToHand(); // Calls the function for adding cards from the darw deck to the Hand of player 1
								P1.DisplayPlayer1Hand(); // Calls the function that will display the Hand of player 1

								cout << endl;

								Discard = P1.Player1DiscardsFromHand(); // This will get the card, of the player's choice, that they will discard from their Hand or their Foot
								DiscardPile.push_back(Discard); // Saves the value of Discard to the Discard Pile
								
								if (P1.Player1HandSize() == 0) // Executes if the Hand of player 1 is now empty of all cards
								{
									cout << "PLAYER ONE: You no have no more cards left in hand. "
										<< "You can now pick up your foot." << endl;
								}
								cout << "\n\n\n" << endl;
							}
							else if (PointTotal > Threshold) // This executes if the value of PointTotal is equal to or greater than the value of Threshold
							{
								cout << "Player One: You are able to put down cards." << endl;
								P1.Player1PuttingDownCardsFromHand(); // Calls the function that simulates the player putting down cards from their Hand
								Player1PutDown++; // Increases the value of Player1PutDown to mark that task as complete

								if (P1.Player1HandSize() == 0) // Executes if the Hand of player 1 is now empty of all cards
								{
									cout << "PLAYER ONE: You no have no more cards left in hand. "
										<< "You can now pick up your foot." << endl;
								}

								cout << endl;
								P1.OrganizeAndDisplayPlayer1Cards(); // This will display the cards that the player has put down 
								P1.DisplayPlayer1Hand(); // Calls the function that will display the Hand of player 1

								Discard = P1.Player1DiscardsFromHand(); // This will get the card, of the player's choice, that they will discard from their Hand or their Foot
								DiscardPile.push_back(Discard); // Saves the value of Discard to the Discard Pile

								if (P1.Player1HandSize() == 0) // Executes if the Hand of player 1 is now empty of all cards
								{
									cout << "PLAYER ONE: You no have no more cards left in hand. "
										<< "You can now pick up your foot." << endl;
								}
								cout << "\n\n\n" << endl;
							}
						}
						else if (Player1PutDown > 0) // This will execute if player 1 has already put down cards
						{
							P1.Player1PuttingDownCardsFromHand(); // Calls the function that simulates the player putting down cards from their Hand
							Player1PutDown++; // Increases the value of Player1PutDown to mark that task as complete

							if (P1.Player1HandSize() == 0) // Executes if the Hand of player 1 is now empty of all cards
							{
								cout << "PLAYER ONE: You no have no more cards left in hand. "
									<< "You can now pick up your foot." << endl;
							}

							cout << endl;
							P1.OrganizeAndDisplayPlayer1Cards(); // This will display the cards that the player has put down 
							P1.DisplayPlayer1Hand(); // Calls the function that will display the Hand of player 1

							Discard = P1.Player1DiscardsFromHand(); // This will get the card, of the player's choice, that they will discard from their Hand or their Foot
							DiscardPile.push_back(Discard); // Saves the value of Discard to the Discard Pile

							if (P1.Player1HandSize() == 0) // Executes if the Hand of player 1 is now empty of all cards
							{
								cout << "PLAYER ONE: You no have no more cards left in hand. "
									<< "You can now pick up your foot." << endl;
							}
							cout << "\n\n\n" << endl;
						}
					}
					else // This executes if the player chooses to not put down cards
					{
						Discard = P1.Player1DiscardsFromHand(); // This will get the card, of the player's choice, that they will discard from their Hand or their Foot
						DiscardPile.push_back(Discard); // Saves the value of Discard to the Discard Pile

						if (P1.Player1HandSize() == 0) // Executes if the Hand of player 1 is now empty of all cards
						{
							cout << "PLAYER ONE: You no have no more cards left in hand. "
								<< "You can now pick up your foot." << endl;
						}
						cout << "\n\n\n" << endl;
					}
				}
				else if (CHOICE == 2) // This will execute if the player chooses to draw from the discard pile
				{
					if (DiscardPile.size() < 5) // This will execute of the size of the discard pile is less than 5
					{
						cout << "PLAYER ONE: There are not enough cards in the discrad pile for you to draw from." << endl;
						cout << endl;
						P1.Player1DrawsFromTheDeckToHand(); // This will get the card, of the player's choice, that they will discard from their Hand or their Foot
						P1.DisplayPlayer1Hand(); // Calls the function that will display the Hand of player 1

						cout << "PLAYER ONE: DO you want to put down cards? (1) Yes and (2) No" << endl;
						cin >> CHOICE; // Get data from the user 

						if (CHOICE == 1) // Executes if the player chooses to put down cards
						{
							int PointTotal = P1.CheckPointsInPlayer1HandForPuttingDownCards(); // Calls teh function that will determine if the player has the points, in thier Hand, required to put down cards

							if (PointTotal < Threshold) // This executes if the value of PoitTotal does not meet or exceed the value 
							{
								cout << "Player One: You do not have the points required to play down cards." << endl;
								cout << "You have " << PointTotal << " while you need " << Threshold << " to put down cards" << endl; // Outputs the results 

								P1.Player1DrawsFromTheDeckToHand(); // This will get the card, of the player's choice, that they will discard from their Hand or their Foot
								P1.DisplayPlayer1Hand();  // Calls the function that will display the Hand of player 1

								Discard = P1.Player1DiscardsFromHand(); // This will get the card, of the player's choice, that they will discard from their Hand or their Foot
								DiscardPile.push_back(Discard); // Saves the value of Discard to the Discard Pile

								if (P1.Player1HandSize() == 0) // Executes if the Hand of player 1 is now empty of all cards
								{
									cout << "PLAYER ONE: You no have no more cards left in hand. "
										<< "You can now pick up your foot." << endl;
								}
								cout << "\n\n\n" << endl;
							}
							else if (PointTotal > Threshold) // This executes if the value of PointTotal is equal to or greater than the value of Threshold
							{
								cout << "Player One: You are able to put down cards." << endl;

								P1.Player1PuttingDownCardsFromHand(); // Calls the function that simulates the player putting down cards from their Hand
								Player1PutDown++; // Increases the value of Player1PutDown to mark that task as complete

								if (P1.Player1HandSize() == 0) // Executes if the Hand of player 1 is now empty of all cards
								{
									cout << "PLAYER ONE: You no have no more cards left in hand. "
										<< "You can now pick up your foot." << endl;
								}

								cout << endl;
								P1.OrganizeAndDisplayPlayer1Cards(); // This will get the card, of the player's choice, that they will discard from their Hand or their Foot
								P1.DisplayPlayer1Hand(); // Calls the function that will display the Hand of player 1

								Discard = P1.Player1DiscardsFromHand(); // This will get the card, of the player's choice, that they will discard from their Hand or their Foot
								DiscardPile.push_back(Discard); // Saves the value of Discard to the Discard Pile

								if (P1.Player1HandSize() == 0) // Executes if the Hand of player 1 is now empty of all cards
								{
									cout << "PLAYER ONE: You no have no more cards left in hand. "
										<< "You can now pick up your foot." << endl;
								}
								cout << "\n\n\n" << endl;
							}
						}
						else // This execute if the player chooses to not put down cards
						{
							Discard = P1.Player1DiscardsFromHand(); // This will get the card, of the player's choice, that they will discard from their Hand or their Foot
							DiscardPile.push_back(Discard); // Saves the value of Discard to the Discard Pile

							if (P1.Player1HandSize() == 0) // Executes if the Hand of player 1 is now empty of all cards
							{
								cout << "PLAYER ONE: You no have no more cards left in hand. "
									<< "You can now pick up your foot." << endl;
							}
							cout << "\n\n\n" << endl;
						}
					}
					else if (DiscardPile.size() >= 5) // This executes if the number of card in the discard pile is equal to or greater than 5
					{
						if (Player1PutDown == 0) // This executes if the player has not put down any cards 
						{
							DiscardQualification = P1.CheckPlayer1HandForTopDiscardCardTwinMatch(DiscardPile.back()); // this will check to see if the player has two copies of the same card as the card on the top of the discard pile

							if (DiscardQualification == 1) // This executes if the player DOES have the two cards needed
							{
								int PointTotal = P1.CheckPointsInPlayer1HandForDrawingFromDiscardPile(DiscardPile.back()); // Calls the function that will determine if the player has the points, in thier Hand, required to draw cards from the discard pile

								if (PointTotal < Threshold) // This executes if the player does not have the points required to draw from the discard pile
								{
									cout << "Player One: You do not currently have the points required to play down cards and thus, cannot draw from the discard pile." << endl;
									cout << "You have " << PointTotal << " while you need " << Threshold << " to put down cards\n" << endl; // Outputs results
									
									cout << endl;
									P1.Player1DrawsFromTheDeckToHand(); // Calls the function for adding cards from the darw deck to the Hand of player 1
									P1.DisplayPlayer1Hand(); // Calls the function that will display the Hand of player 1

									cout << "PLAYER ONE: DO you want to put down cards? (1) Yes and (2) No" << endl;
									cin >> CHOICE; // Get data from the player

									if (CHOICE == 1) // Executes if the player chooses to put down cards
									{
										int PointTotal = P1.CheckPointsInPlayer1HandForPuttingDownCards(); // Calls the function that will determine if the player has the points, in thier Hand, required to put down cards

										if (PointTotal < Threshold) // Executes if the player does not have the points required to put down cards
										{
											cout << "Player One: You do not have the points required to play down cards." << endl;
											cout << "You have " << PointTotal << " while you need " << Threshold << " to put down cards" << endl; // Outputs result

											P1.Player1DrawsFromTheDeckToHand(); // Calls the function for adding cards from the darw deck to the Hand of player 1
											P1.DisplayPlayer1Hand(); // Calls the function that will display the Hand of player 1

											Discard = P1.Player1DiscardsFromHand(); // This will get the card, of the player's choice, that they will discard from their Hand or their Foot
											DiscardPile.push_back(Discard); // Saves the value of Discard to the Discard Pile

											if (P1.Player1HandSize() == 0) // Executes if the Hand of player 1 is now empty of all cards
											{
												cout << "PLAYER ONE: You no have no more cards left in hand. "
													<< "You can now pick up your foot." << endl;
											}
											cout << "\n\n\n" << endl;
										}
										else if (PointTotal > Threshold) // Executes if the player has the points required to put down cards
										{
											cout << "Player One: You are able to put down cards." << endl;
											P1.Player1PuttingDownCardsFromHand();  // Calls the function that simulates the player putting down cards from their Hand
											Player1PutDown++; // Increases the value of Player1PutDown to mark that task as complete

											if (P1.Player1HandSize() == 0) // Executes if the Hand of player 1 is now empty of all cards
											{
												cout << "PLAYER ONE: You no have no more cards left in hand. "
													<< "You can now pick up your foot." << endl;
											}

											cout << endl;
											P1.OrganizeAndDisplayPlayer1Cards(); // This will get the card, of the player's choice, that they will discard from their Hand or their Foot
											P1.DisplayPlayer1Hand(); // Calls the function that will display the Hand of player 1

											Discard = P1.Player1DiscardsFromHand(); // This will get the card, of the player's choice, that they will discard from their Hand or their Foot
											DiscardPile.push_back(Discard); // Saves the value of Discard to the Discard Pile

											if (P1.Player1HandSize() == 0) // Executes if the Hand of player 1 is now empty of all cards
											{
												cout << "PLAYER ONE: You no have no more cards left in hand. "
													<< "You can now pick up your foot." << endl;
											}
											cout << "\n\n\n" << endl;
										}
									}
									else // Executes if the player chooses to not put down cards
									{
										Discard = P1.Player1DiscardsFromHand(); // This will get the card, of the player's choice, that they will discard from their Hand or their Foot
										DiscardPile.push_back(Discard); // Saves the value of Discard to the Discard Pile

										if (P1.Player1HandSize() == 0) // Executes if the Hand of player 1 is now empty of all cards
										{
											cout << "PLAYER ONE: You no have no more cards left in hand. "
												<< "You can now pick up your foot." << endl;
										}
										cout << "\n\n\n" << endl;
									}
								}
								else // Executesif the player has the points required to draw from the discard pile
								{
									cout << "Player One: You are able to draw from the discard pile." << endl;

									// This loop will run 5 times to take 5 cards from the discard pile and transfer them to the Hand of the player
									for (int i = 0; i < 5; i++)
									{
										P1.Player1DrawsFromDiscardPileToHand(DiscardPile.back()); // Sends the card that is at the top of the discard pile to the function that will add it to the Hand of the player
										DiscardPile.pop_back(); // Deletes the top card in the DiscardPile vector
									}

									cout << endl;
									P1.DisplayPlayer1Hand(); // Calls the function that will display the Hand of player 1

									cout << "PLAYER ONE: DO you want to put down cards? (1) Yes and (2) No" << endl;
									cin >> CHOICE; // Get data from the user

									if (CHOICE == 1) // Executes if the player chooses to put down cards
									{
										int PointTotal = P1.CheckPointsInPlayer1HandForPuttingDownCards(); // Calls the function that will determine if the player has the points, in thier Hand, required to put down cards 

										if (PointTotal < Threshold) // Executes if the player does not have the points required to put down cards
										{
											cout << "Player One: You do not have the points required to play down cards." << endl;
											cout << "You have " << PointTotal << " while you need " << Threshold << " to put down cards" << endl; // Outpouts results

											P1.Player1DrawsFromTheDeckToHand(); // Calls the function for adding cards from the darw deck to the Hand of player 1
											P1.DisplayPlayer1Hand(); // Calls the function that will display the Hand of player 1

											Discard = P1.Player1DiscardsFromHand(); // This will get the card, of the player's choice, that they will discard from their Hand or their Foot
											DiscardPile.push_back(Discard); // Saves the value of Discard to the Discard Pile

											if (P1.Player1HandSize() == 0) // Executes if the Hand of player 1 is now empty of all cards
											{
												cout << "PLAYER ONE: You no have no more cards left in hand. "
													<< "You can now pick up your foot." << endl;
											}
											cout << "\n\n\n" << endl;
										}
										else if (PointTotal > Threshold) // Executes if the player has the points required to put down cards
										{
											cout << "Player One: You are able to put down cards." << endl;
											P1.Player1PuttingDownCardsFromHand(); // Calls the function that simulates the player putting down cards from their Hand
											Player1PutDown++; // Increases the value of Player1PutDown to mark that task as complete

											if (P1.Player1HandSize() == 0) // Executes if the Hand of player 1 is now empty of all cards
											{
												cout << "PLAYER ONE: You no have no more cards left in hand. "
													<< "You can now pick up your foot." << endl;
											}

											cout << endl;
											P1.OrganizeAndDisplayPlayer1Cards(); // This will get the card, of the player's choice, that they will discard from their Hand or their Foot
											P1.DisplayPlayer1Hand(); // Calls the function that will display the Hand of player 1

											Discard = P1.Player1DiscardsFromHand(); // This will get the card, of the player's choice, that they will discard from their Hand or their Foot
											DiscardPile.push_back(Discard); // Saves the value of Discard to the Discard Pile

											if (P1.Player1HandSize() == 0) // Executes if the Hand of player 1 is now empty of all cards
											{
												cout << "PLAYER ONE: You no have no more cards left in hand. "
													<< "You can now pick up your foot." << endl;
											}
											cout << "\n\n\n" << endl;
										}
									}
									else
									{
										Discard = P1.Player1DiscardsFromHand(); // This will get the card, of the player's choice, that they will discard from their Hand or their Foot
										DiscardPile.push_back(Discard); // Saves the value of Discard to the Discard Pile

										if (P1.Player1HandSize() == 0) // Executes if the Hand of player 1 is now empty of all cards
										{
											cout << "PLAYER ONE: You no have no more cards left in hand. "
												<< "You can now pick up your foot." << endl;
										}
										cout << "\n\n\n" << endl;
									}
								}
							}
							else // Executes if the player DOES NOT have the cards need to draw from the discard pile
							{
								P1.Player1DrawsFromTheDeckToHand(); // Calls the function for adding cards from the darw deck to the Hand of player 1
								P1.DisplayPlayer1Hand(); // Calls the function that will display the Hand of player 1

								Discard = P1.Player1DiscardsFromHand(); // This will get the card, of the player's choice, that they will discard from their Hand or their Foot
								DiscardPile.push_back(Discard); // Saves the value of Discard to the Discard Pile

								if (P1.Player1HandSize() == 0) // Executes if the Hand of player 1 is now empty of all cards
								{
									cout << "PLAYER ONE: You no have no more cards left in hand. "
										<< "You can now pick up your foot." << endl;
								}
								cout << "\n\n\n" << endl;
							}
						}
						else if (Player1PutDown > 0) // Executes if the player has not put down cards
						{
							// This loop will run 5 times to take 5 cards from the discard pile and transfer them to the Hand of the player
							for (int i = 0; i < 5; i++)
							{
								P1.Player1DrawsFromDiscardPileToHand(DiscardPile.back()); // Sends the card that is at the top of the discard pile to the function that will add it to the Hand of the player
								DiscardPile.pop_back(); // Deletes the top card in the DiscardPile vector
							}

							P1.DisplayPlayer1Hand(); // Calls the function that will display the Hand of player 1

							cout << "PLAYER ONE: DO you want to put down cards? (1) Yes and (2) No" << endl;
							cin >> CHOICE; // Get data from the user

							if (CHOICE == 1) // Executes if the player chooses to put down cards 
							{
								int PointTotal = P1.CheckPointsInPlayer1HandForPuttingDownCards(); // Calls the function that will determine if the player has the points, in thier Hand, required to put down cards 

								if (PointTotal < Threshold) // Executes if the player does not have the points required to put down cards
								{
									cout << "Player One: You do not have the points required to play down cards." << endl;
									cout << "You have " << PointTotal << " while you need " << Threshold << " to put down cards" << endl; // Outputs results

									P1.Player1DrawsFromTheDeckToHand(); // Calls the function for adding cards from the darw deck to the Hand of player 1
									cout << endl;
									P1.DisplayPlayer1Hand(); // Calls the function that will display the Hand of player 1

									Discard = P1.Player1DiscardsFromHand(); // This will get the card, of the player's choice, that they will discard from their Hand or their Foot
									DiscardPile.push_back(Discard); // Saves the value of Discard to the Discard Pile

									if (P1.Player1HandSize() == 0) // Executes if the Hand of player 1 is now empty of all cards
									{
										cout << "PLAYER ONE: You no have no more cards left in hand. "
											<< "You can now pick up your foot." << endl;
									}
									cout << "\n\n\n" << endl;
								}
								else if (PointTotal > Threshold)
								{
									cout << "Player One: You are able to put down cards." << endl;
									P1.Player1PuttingDownCardsFromHand(); // Calls the function that simulates the player putting down cards from their Hand
									Player1PutDown++; // Increases the value of Player1PutDown to mark that task as complete

									if (P1.Player1HandSize() == 0) // Executes if the Hand of player 1 is now empty of all cards
									{
										cout << "PLAYER ONE: You no have no more cards left in hand. "
											<< "You can now pick up your foot." << endl;
									}
									cout << endl;
									P1.OrganizeAndDisplayPlayer1Cards();
									P1.DisplayPlayer1Hand(); // Calls the function that will display the Hand of player 1

									Discard = P1.Player1DiscardsFromHand(); // This will get the card, of the player's choice, that they will discard from their Hand or their Foot
									DiscardPile.push_back(Discard); // Saves the value of Discard to the Discard Pile

									if (P1.Player1HandSize() == 0) // Executes if the Hand of player 1 is now empty of all cards
									{
										cout << "PLAYER ONE: You no have no more cards left in hand. "
											<< "You can now pick up your foot." << endl;
									}
									cout << "\n\n\n" << endl;
								}
							}
							else // Executes if the player chooses to not put down cards
							{
								Discard = P1.Player1DiscardsFromHand(); // This will get the card, of the player's choice, that they will discard from their Hand or their Foot
								DiscardPile.push_back(Discard); // Saves the value of Discard to the Discard Pile

								if (P1.Player1HandSize() == 0) // Executes if the Hand of player 1 is now empty of all cards
								{
									cout << "PLAYER ONE: You no have no more cards left in hand. "
										<< "You can now pick up your foot." << endl;
								}
								cout << "\n\n\n" << endl;
							}
						}
					}
				}
			}

/*********************************************************************************************************************************/

			else if (P1.Player1HandSize() == 0) // Executes if the Hand of the player is empty of all cards
			{
				P1.DisplayPlayer1Foot(); // Calls the function that will display the Foot of player 1
				cout << "\n" << endl;
				ShowDiscardPile(); // Shows the cards that are in the discard pile
				cout << endl;

				cout << "Player One: Do you want to (1) draw from the deck or (2) take the top five card on the discard pile? " << endl;
				cin >> CHOICE; // Get data from the player

				if (CHOICE == 1) // Executes if the player chooses to draw from the deck
				{
					P1.Player1DrawsFromTheDeckToFoot(); // Calls the function for adding cards from the darw deck to the Foot of player 1
					cout << endl;
					P1.DisplayPlayer1Foot(); // Calls the function that will display the Foot of player 1

					cout << "PLAYER ONE: DO you want to put down cards? (1) Yes and (2) No" << endl;
					cin >> CHOICE; // Get data from the player

					if (CHOICE == 1) // Executes if the player chooses to put down cards
					{
						P1.Player1PuttingDownCardsFromFoot(); // Calls the function that simulates the player putting down cards from their Foot

						cout << endl;
						P1.OrganizeAndDisplayPlayer1Cards(); // Calls the function that will display the cards the player has put down
						P1.DisplayPlayer1Foot(); // Calls the function that will display the Foot of player 1

						Discard = P1.Player1DiscardsFromFoot(); // This will get the card, of the player's choice, that they will discard from their Hand or their Foot
						DiscardPile.push_back(Discard); // Saves the value of Discard to the Discard Pile

						cout << "\n\n\n" << endl;
					}
					else
					{
						Discard = P1.Player1DiscardsFromFoot(); // This will get the card, of the player's choice, that they will discard from their Hand or their Foot
						DiscardPile.push_back(Discard); // Saves the value of Discard to the Discard Pile

						cout << "\n\n\n" << endl;
					}
				}
				else if (CHOICE == 2) // Executesif the player chooses to draw from the discard pile
				{
					DiscardQualification = P1.CheckPlayer1FootForTopDiscardCardTwinMatch(DiscardPile.back()); // Calls the function that will determine if the player has the points, in thier Hand, required to draw cards from the discard pile

					if (DiscardQualification == 1) // Executes if the player does not have the cards required to draw from the discard pile
					{
						// This loop will run 5 times to take 5 cards from the discard pile and transfer them to the Hand of the player
						for (int i = 0; i < 5; i++)
						{
							P1.Player1DrawsFromDiscardPileToFoot(DiscardPile.back()); // Sends the card that is at the top of the discard pile to the function that will add it to the Hand of the player
							DiscardPile.pop_back(); // Deletes the top card in the DiscardPile vector
						}

						P1.DisplayPlayer1Foot(); // Calls the function that will display the Foot of player 1

						cout << "PLAYER ONE: DO you want to put down cards? (1) Yes and (2) No" << endl;
						cin >> CHOICE; // Get data from the player

						if (CHOICE == 1) // Executes if the player chooses to put down cards
						{
							cout << "Player One: You are able to put down cards." << endl;
							P1.Player1PuttingDownCardsFromFoot(); // Calls the function that simulates the player putting down cards from their Foot

							cout << endl;
							P1.OrganizeAndDisplayPlayer1Cards(); // Calls the function that will display the cards the player has put down
							P1.DisplayPlayer1Foot(); // Calls the function that will display the Foot of player 1

							Discard = P1.Player1DiscardsFromFoot(); // This will get the card, of the player's choice, that they will discard from their Hand or their Foot
							DiscardPile.push_back(Discard); // Saves the value of Discard to the Discard Pile
							cout << "\n\n\n" << endl;
						}
						else // Executes if the player chooses to not put down cards
						{
							Discard = P1.Player1DiscardsFromFoot(); // This will get the card, of the player's choice, that they will discard from their Hand or their Foot
							DiscardPile.push_back(Discard); // Saves the value of Discard to the Discard Pile

							cout << "\n\n\n" << endl;
						}
					}
					else // Executes if the player does not have the cards required to draw from the discard pile
					{
						P1.DisplayPlayer1Foot(); // Calls the function that will display the Foot of player 1

						cout << "PLAYER ONE: DO you want to put down cards? (1) Yes and (2) No" << endl;
						cin >> CHOICE; // Get data from the player

						if (CHOICE == 1) // Executes if the player chooses to put down cards
						{
							cout << "Player One: You are able to put down cards." << endl;
							P1.Player1PuttingDownCardsFromFoot(); // Calls the function that simulates the player putting down cards from their Foot

							cout << endl;
							P1.OrganizeAndDisplayPlayer1Cards(); // Calls the function that will display the cards the player has put down
							P1.DisplayPlayer1Foot(); // Calls the function that will display the Foot of player 1

							Discard = P1.Player1DiscardsFromFoot(); // This will get the card, of the player's choice, that they will discard from their Hand or their Foot
							DiscardPile.push_back(Discard); // Saves the value of Discard to the Discard Pile

							cout << "\n\n\n" << endl;
						}
						else // Executes if the player chooses to not put down cards
						{
							Discard = P1.Player1DiscardsFromFoot(); // This will get the card, of the player's choice, that they will discard from their Hand or their Foot
							DiscardPile.push_back(Discard); // Saves the value of Discard to the Discard Pile

							cout << "\n\n\n" << endl;
						}
					}
				}
			}


/********************************************************************************************************************************/
/********************************************************************************************************************************/
/********************************************************************************************************************************/
			
			if (P2.Player2HandSize() != 0)
			{
				P2.DisplayPlayer2Hand(); // Calls the function that will display the Hand of player 2
				cout << "\n" << endl;
				ShowDiscardPile(); // Calls the function that will display the cards in the disard pile
				cout << endl;


				cout << "Player Two: Do you want to (1) draw from the deck or (2) take the top five card on the discard pile? " << endl;
				cin >> CHOICE; // Get data from the user

				if (CHOICE == 1)
				{
					P2.Player2DrawsFromTheDeckToHand(); // Calls the function for adding cards from the darw deck to the Hand of player 1
					P2.DisplayPlayer2Hand(); // Calls the function that will display the Hand of player 2
					cout << "PLAYER TWO: DO you want to put down cards? (1) Yes and (2) No" << endl;
					cin >> CHOICE; // Get data from the user

					if (CHOICE == 1) // Exeutes if the player inputs a 1 for putting down cards
					{
						if (Player2PutDown == 0) // This executes if the player has not put down any cards
						{
							int PointTotal = P2.CheckPointsInPlayer2HandForPuttingDownCards(); // Calls the function that will determine if the player has the points, in thier Hand, required to put down cards

							if (PointTotal < Threshold) // This executes if the value of PoitTotal does not meet or exceed the value 
							{
								cout << endl;
								cout << "Player Two: You do not have the points required to play down cards." << endl;
								cout << "You have " << PointTotal << " while you need " << Threshold << " to put down cards" << endl;// Shows the results to the player 

								cout << endl;

								P2.Player2DrawsFromTheDeckToHand(); // Calls the function for adding cards from the darw deck to the Hand of player 1
								P2.DisplayPlayer2Hand(); // Calls the function that will display the Hand of player 1

								cout << endl;

								Discard = P2.Player2DiscardsFromHand(); // This will get the card, of the player's choice, that they will discard from their Hand or their Foot
								DiscardPile.push_back(Discard); // Saves the value of Discard to the Discard Pile

								if (P2.Player2HandSize() == 0) // Executes if the Hand of player 2 is now empty of all cards
								{
									cout << "PLAYER TWO: You no have no more cards left in hand. "
										<< "You can now pick up your foot." << endl;
								}
								cout << "\n\n\n" << endl;
							}
							else if (PointTotal > Threshold) // This executes if the value of PointTotal is equal to or greater than the value of Threshold
							{
								cout << "Player Two: You are able to put down cards." << endl;
								P2.Player2PuttingDownCardsFromHand(); // Calls the function that simulates the player putting down cards from their Hand
								Player2PutDown++; // Increases the value of Player1PutDown to mark that task as complete

								if (P2.Player2HandSize() == 0) // Executes if the Hand of player 2 is now empty of all cards
								{
									cout << "PLAYER TWO: You no have no more cards left in hand. "
										<< "You can now pick up your foot." << endl;
								}

								cout << endl;
								P2.OrganizeAndDisplayPlayer2Cards(); // This will display the cards that the player has put down 
								P2.DisplayPlayer2Hand(); // Calls the function that will display the Hand of player 2

								Discard = P2.Player2DiscardsFromHand(); // This will get the card, of the player's choice, that they will discard from their Hand or their Foot
								DiscardPile.push_back(Discard); // Saves the value of Discard to the Discard Pile

								if (P2.Player2HandSize() == 0) // Executes if the Hand of player 2 is now empty of all cards
								{
									cout << "PLAYER TWO: You no have no more cards left in hand. "
										<< "You can now pick up your foot." << endl;
								}
								cout << "\n\n\n" << endl;
							}
						}
						else if (Player2PutDown > 0) // This will execute if player 2 has already put down cards
						{
							P2.Player2PuttingDownCardsFromHand(); // Calls the function that simulates the player putting down cards from their Hand
							Player2PutDown++; // Increases the value of Player1PutDown to mark that task as complete

							if (P2.Player2HandSize() == 0) // Executes if the Hand of player 2 is now empty of all cards
							{
								cout << "PLAYER TWO: You no have no more cards left in hand. "
									<< "You can now pick up your foot." << endl;
							}

							cout << endl;
							P2.OrganizeAndDisplayPlayer2Cards(); // This will display the cards that the player has put down 
							P2.DisplayPlayer2Hand(); // Calls the function that will display the Hand of player 2

							Discard = P2.Player2DiscardsFromHand(); // This will get the card, of the player's choice, that they will discard from their Hand or their Foot
							DiscardPile.push_back(Discard); // Saves the value of Discard to the Discard Pile

							if (P2.Player2HandSize() == 0) // Executes if the Hand of player 2 is now empty of all cards
							{
								cout << "PLAYER TWO: You no have no more cards left in hand. "
									<< "You can now pick up your foot." << endl;
							}
							cout << "\n\n\n" << endl;
						}
					}
					else // This executes if the player chooses to not put down cards
					{
						Discard = P2.Player2DiscardsFromHand(); // This will get the card, of the player's choice, that they will discard from their Hand or their Foot
						DiscardPile.push_back(Discard); // Saves the value of Discard to the Discard Pile

						if (P2.Player2HandSize() == 0) // Executes if the Hand of player 2 is now empty of all cards
						{
							cout << "PLAYER TWO: You no have no more cards left in hand. "
								<< "You can now pick up your foot." << endl;
						}
						cout << "\n\n\n" << endl;
					}
				}
				else if (CHOICE == 2) // This will execute if the player chooses to draw from the discard pile
				{
					if (DiscardPile.size() < 5) // This will execute of the size of the discard pile is less than 5
					{
						cout << "PLAYER ONE: There are not enough cards in the discrad pile for you to draw from." << endl;
						cout << endl;
						P2.Player2DrawsFromTheDeckToHand(); // This will get the card, of the player's choice, that they will discard from their Hand or their Foot
						P2.DisplayPlayer2Hand(); // Calls the function that will display the Hand of player 2

						cout << "PLAYER TWO: DO you want to put down cards? (1) Yes and (2) No" << endl;
						cin >> CHOICE; // Get data from the user 

						if (CHOICE == 1) // Executes if the player chooses to put down cards
						{
							int PointTotal = P2.CheckPointsInPlayer2HandForPuttingDownCards(); // Calls the function that will determine if the player has the points, in thier Hand, required to put down cards

							if (PointTotal < Threshold) // This executes if the value of PoitTotal does not meet or exceed the value 
							{
								cout << "Player Two: You do not have the points required to play down cards." << endl;
								cout << "You have " << PointTotal << " while you need " << Threshold << " to put down cards" << endl; // Outputs the results 

								P2.Player2DrawsFromTheDeckToHand(); // This will get the card, of the player's choice, that they will discard from their Hand or their Foot
								P2.DisplayPlayer2Hand();  // Calls the function that will display the Hand of player 2

								Discard = P2.Player2DiscardsFromHand(); // This will get the card, of the player's choice, that they will discard from their Hand or their Foot
								DiscardPile.push_back(Discard); // Saves the value of Discard to the Discard Pile

								if (P2.Player2HandSize() == 0) // Executes if the Hand of player 2 is now empty of all cards
								{
									cout << "PLAYER TWO: You no have no more cards left in hand. "
										<< "You can now pick up your foot." << endl;
								}
								cout << "\n\n\n" << endl;
							}
							else if (PointTotal > Threshold) // This executes if the value of PointTotal is equal to or greater than the value of Threshold
							{
								cout << "Player Two: You are able to put down cards." << endl;

								P2.Player2PuttingDownCardsFromHand(); // Calls the function that simulates the player putting down cards from their Hand
								Player2PutDown++; // Increases the value of Player1PutDown to mark that task as complete

								if (P2.Player2HandSize() == 0) // Executes if the Hand of player 2 is now empty of all cards
								{
									cout << "PLAYER TWO: You no have no more cards left in hand. "
										<< "You can now pick up your foot." << endl;
								}

								cout << endl;
								P2.OrganizeAndDisplayPlayer2Cards(); // This will get the card, of the player's choice, that they will discard from their Hand or their Foot
								P2.DisplayPlayer2Hand(); // Calls the function that will display the Hand of player 2

								Discard = P2.Player2DiscardsFromHand(); // This will get the card, of the player's choice, that they will discard from their Hand or their Foot
								DiscardPile.push_back(Discard); // Saves the value of Discard to the Discard Pile

								if (P2.Player2HandSize() == 0) // Executes if the Hand of player 2 is now empty of all cards
								{
									cout << "PLAYER TWO: You no have no more cards left in hand. "
										<< "You can now pick up your foot." << endl;
								}
								cout << "\n\n\n" << endl;
							}
						}
						else // This execute if the player chooses to not put down cards
						{
							Discard = P2.Player2DiscardsFromHand(); // This will get the card, of the player's choice, that they will discard from their Hand or their Foot
							DiscardPile.push_back(Discard); // Saves the value of Discard to the Discard Pile

							if (P2.Player2HandSize() == 0) // Executes if the Hand of player 2 is now empty of all cards
							{
								cout << "PLAYER TWO: You no have no more cards left in hand. "
									<< "You can now pick up your foot." << endl;
							}
							cout << "\n\n\n" << endl;
						}
					}
					else if (DiscardPile.size() >= 5) // This executes if the number of card in the discard pile is equal to or greater than 5
					{
						if (Player2PutDown == 0) // This executes if the player has not put down any cards 
						{
							DiscardQualification = P2.CheckPlayer2HandForTopDiscardCardTwinMatch(DiscardPile.back()); // this will check to see if the player has two copies of the same card as the card on the top of the discard pile

							if (DiscardQualification == 1) // This executes if the player DOES have the two cards needed
							{
								int PointTotal = P2.CheckPointsInPlayer2HandForDrawingFromDiscardPile(DiscardPile.back()); // Calls the function that will determine if the player has the points, in thier Hand, required to draw cards from the discard pile

								if (PointTotal < Threshold) // This executes if the player does not have the points required to draw from the discard pile
								{
									cout << "Player Two: You do not currently have the points required to play down cards and thus, cannot draw from the discard pile." << endl;
									cout << "You have " << PointTotal << " while you need " << Threshold << " to put down cards\n" << endl; // Outputs results

									cout << endl;
									P2.Player2DrawsFromTheDeckToHand(); // Calls the function for adding cards from the darw deck to the Hand of player 1
									P2.DisplayPlayer2Hand(); // Calls the function that will display the Hand of player 2

									cout << "PLAYER TWO: DO you want to put down cards? (1) Yes and (2) No" << endl;
									cin >> CHOICE; // Get data from the player

									if (CHOICE == 1) // Executes if the player chooses to put down cards
									{
										int PointTotal = P2.CheckPointsInPlayer2HandForPuttingDownCards(); // Calls the function that will determine if the player has the points, in thier Hand, required to put down cards

										if (PointTotal < Threshold) // Executes if the player does not have the points required to put down cards
										{
											cout << "Player Two: You do not have the points required to play down cards." << endl;
											cout << "You have " << PointTotal << " while you need " << Threshold << " to put down cards" << endl; // Outputs result

											P2.Player2DrawsFromTheDeckToHand(); // Calls the function for adding cards from the darw deck to the Hand of player 1
											P2.DisplayPlayer2Hand(); // Calls the function that will display the Hand of player 2

											Discard = P2.Player2DiscardsFromHand(); // This will get the card, of the player's choice, that they will discard from their Hand or their Foot
											DiscardPile.push_back(Discard); // Saves the value of Discard to the Discard Pile

											if (P2.Player2HandSize() == 0) // Executes if the Hand of player 2 is now empty of all cards
											{
												cout << "PLAYER TWO: You no have no more cards left in hand. "
													<< "You can now pick up your foot." << endl;
											}
											cout << "\n\n\n" << endl;
										}
										else if (PointTotal > Threshold) // Executes if the player has the points required to put down cards
										{
											cout << "Player Two: You are able to put down cards." << endl;
											P2.Player2PuttingDownCardsFromHand();  // Calls the function that simulates the player putting down cards from their Hand
											Player2PutDown++; // Increases the value of Player2PutDown to mark that task as complete

											if (P2.Player2HandSize() == 0) // Executes if the Hand of player 2 is now empty of all cards
											{
												cout << "PLAYER TWO: You no have no more cards left in hand. "
													<< "You can now pick up your foot." << endl;
											}

											cout << endl;
											P2.OrganizeAndDisplayPlayer2Cards(); // This will get the card, of the player's choice, that they will discard from their Hand or their Foot
											P2.DisplayPlayer2Hand(); // Calls the function that will display the Hand of player 2

											Discard = P2.Player2DiscardsFromHand(); // This will get the card, of the player's choice, that they will discard from their Hand or their Foot
											DiscardPile.push_back(Discard); // Saves the value of Discard to the Discard Pile

											if (P2.Player2HandSize() == 0) // Executes if the Hand of player 2 is now empty of all cards
											{
												cout << "PLAYER TWO: You no have no more cards left in hand. "
													<< "You can now pick up your foot." << endl;
											}
											cout << "\n\n\n" << endl;
										}
									}
									else // Executes if the player chooses to not put down cards
									{
										Discard = P2.Player2DiscardsFromHand(); // This will get the card, of the player's choice, that they will discard from their Hand or their Foot
										DiscardPile.push_back(Discard); // Saves the value of Discard to the Discard Pile

										if (P2.Player2HandSize() == 0) // Executes if the Hand of player 2 is now empty of all cards
										{
											cout << "PLAYER TWO: You no have no more cards left in hand. "
												<< "You can now pick up your foot." << endl;
										}
										cout << "\n\n\n" << endl;
									}
								}
								else // Executes if the player has the points required to draw from the discard pile
								{
									cout << "Player Two: You are able to draw from the discard pile." << endl;

									// This loop will run 5 times to take 5 cards from the discard pile and transfer them to the Hand of the player
									for (int i = 0; i < 5; i++)
									{
										P2.Player2DrawsFromDiscardPileToHand(DiscardPile.back()); // Sends the card that is at the top of the discard pile to the function that will add it to the Hand of the player
										DiscardPile.pop_back(); // Deletes the top card in the DiscardPile vector
									}

									cout << endl;
									P2.DisplayPlayer2Hand(); // Calls the function that will display the Hand of player 2

									cout << "PLAYER ONE: DO you want to put down cards? (1) Yes and (2) No" << endl;
									cin >> CHOICE; // Get data from the user

									if (CHOICE == 1) // Executes if the player chooses to put down cards
									{
										int PointTotal = P2.CheckPointsInPlayer2HandForPuttingDownCards(); // Calls the function that will determine if the player has the points, in thier Hand, required to put down cards 

										if (PointTotal < Threshold) // Executes if the player does not have the points required to put down cards
										{
											cout << "Player Two: You do not have the points required to play down cards." << endl;
											cout << "You have " << PointTotal << " while you need " << Threshold << " to put down cards" << endl; // Outpouts results

											P2.Player2DrawsFromTheDeckToHand(); // Calls the function for adding cards from the darw deck to the Hand of player 1
											P2.DisplayPlayer2Hand(); // Calls the function that will display the Hand of player 2

											Discard = P2.Player2DiscardsFromHand(); // This will get the card, of the player's choice, that they will discard from their Hand or their Foot
											DiscardPile.push_back(Discard); // Saves the value of Discard to the Discard Pile

											if (P2.Player2HandSize() == 0) // Executes if the Hand of player 2 is now empty of all cards
											{
												cout << "PLAYER TWO: You no have no more cards left in hand. "
													<< "You can now pick up your foot." << endl;
											}
											cout << "\n\n\n" << endl;
										}
										else if (PointTotal > Threshold) // Executes if the player has the points required to put down cards
										{
											cout << "Player Two: You are able to put down cards." << endl;
											P2.Player2PuttingDownCardsFromHand(); // Calls the function that simulates the player putting down cards from their Hand
											Player2PutDown++; // Increases the value of Player2PutDown to mark that task as complete

											if (P2.Player2HandSize() == 0) // Executes if the Hand of player 2 is now empty of all cards
											{
												cout << "PLAYER TWO: You no have no more cards left in hand. "
													<< "You can now pick up your foot." << endl;
											}

											cout << endl;
											P2.OrganizeAndDisplayPlayer2Cards(); // This will get the card, of the player's choice, that they will discard from their Hand or their Foot
											P2.DisplayPlayer2Hand(); // Calls the function that will display the Hand of player 2

											Discard = P2.Player2DiscardsFromHand(); // This will get the card, of the player's choice, that they will discard from their Hand or their Foot
											DiscardPile.push_back(Discard); // Saves the value of Discard to the Discard Pile

											if (P2.Player2HandSize() == 0) // Executes if the Hand of player 2 is now empty of all cards
											{
												cout << "PLAYER TWO: You no have no more cards left in hand. "
													<< "You can now pick up your foot." << endl;
											}
											cout << "\n\n\n" << endl;
										}
									}
									else // Executes if the player chooses to not put down cards
									{
										Discard = P2.Player2DiscardsFromHand(); // This will get the card, of the player's choice, that they will discard from their Hand or their Foot
										DiscardPile.push_back(Discard); // Saves the value of Discard to the Discard Pile

										if (P2.Player2HandSize() == 0) // Executes if the Hand of player 2 is now empty of all cards
										{
											cout << "PLAYER TWO: You no have no more cards left in hand. "
												<< "You can now pick up your foot." << endl;
										}
										cout << "\n\n\n" << endl;
									}
								}
							}
							else // Executes if the player DOES NOT have the cards need to draw from the discard pile
							{
								P2.Player2DrawsFromTheDeckToHand(); // Calls the function for adding cards from the darw deck to the Hand of player 1
								P2.DisplayPlayer2Hand(); // Calls the function that will display the Hand of player 2

								Discard = P2.Player2DiscardsFromHand(); // This will get the card, of the player's choice, that they will discard from their Hand or their Foot
								DiscardPile.push_back(Discard); // Saves the value of Discard to the Discard Pile

								if (P2.Player2HandSize() == 0) // Executes if the Hand of player 2 is now empty of all cards
								{
									cout << "PLAYER TWO: You no have no more cards left in hand. "
										<< "You can now pick up your foot." << endl;
								}
								cout << "\n\n\n" << endl;
							}
						}
						else if (Player2PutDown > 0) // Executes if the player has not put down cards
						{
							// This loop will run 5 times to take 5 cards from the discard pile and transfer them to the Hand of the player
							for (int i = 0; i < 5; i++)
							{
								P2.Player2DrawsFromDiscardPileToHand(DiscardPile.back()); // Sends the card that is at the top of the discard pile to the function that will add it to the Hand of the player
								DiscardPile.pop_back(); // Deletes the top card in the DiscardPile vector
							}

							P2.DisplayPlayer2Hand(); // Calls the function that will display the Hand of player 2

							cout << "PLAYER TWO: DO you want to put down cards? (1) Yes and (2) No" << endl;
							cin >> CHOICE; // Get data from the user

							if (CHOICE == 1) // Executes if the player chooses to put down cards 
							{
								int PointTotal = P2.CheckPointsInPlayer2HandForPuttingDownCards(); // Calls the function that will determine if the player has the points, in thier Hand, required to put down cards 

								if (PointTotal < Threshold) // Executes if the player does not have the points required to put down cards
								{
									cout << "Player Two: You do not have the points required to play down cards." << endl;
									cout << "You have " << PointTotal << " while you need " << Threshold << " to put down cards" << endl; // Outputs results

									P2.Player2DrawsFromTheDeckToHand(); // Calls the function for adding cards from the darw deck to the Hand of player 1
									cout << endl;
									P2.DisplayPlayer2Hand(); // Calls the function that will display the Hand of player 2

									Discard = P2.Player2DiscardsFromHand(); // This will get the card, of the player's choice, that they will discard from their Hand or their Foot
									DiscardPile.push_back(Discard); // Saves the value of Discard to the Discard Pile

									if (P2.Player2HandSize() == 0) // Executes if the Hand of player 2 is now empty of all cards
									{
										cout << "PLAYER TWO: You no have no more cards left in hand. "
											<< "You can now pick up your foot." << endl;
									}
									cout << "\n\n\n" << endl;
								}
								else if (PointTotal > Threshold)
								{
									cout << "Player Two: You are able to put down cards." << endl;
									P2.Player2PuttingDownCardsFromHand(); // Calls the function that simulates the player putting down cards from their Hand
									Player1PutDown++; // Increases the value of Player1PutDown to mark that task as complete

									if (P2.Player2HandSize() == 0) // Executes if the Hand of player 2 is now empty of all cards
									{
										cout << "PLAYER TWO: You no have no more cards left in hand. "
											<< "You can now pick up your foot." << endl;
									}
									cout << endl;
									P2.OrganizeAndDisplayPlayer2Cards();
									P2.DisplayPlayer2Hand(); // Calls the function that will display the Hand of player 2

									Discard = P2.Player2DiscardsFromHand(); // This will get the card, of the player's choice, that they will discard from their Hand or their Foot
									DiscardPile.push_back(Discard); // Saves the value of Discard to the Discard Pile

									if (P2.Player2HandSize() == 0) // Executes if the Hand of player 2 is now empty of all cards
									{
										cout << "PLAYER TWO: You no have no more cards left in hand. "
											<< "You can now pick up your foot." << endl;
									}
									cout << "\n\n\n" << endl;
								}
							}
							else
							{
								Discard = P2.Player2DiscardsFromHand(); // This will get the card, of the player's choice, that they will discard from their Hand or their Foot
								DiscardPile.push_back(Discard); // Saves the value of Discard to the Discard Pile

								if (P2.Player2HandSize() == 0) // Executes if the Hand of player 2 is now empty of all cards
								{
									cout << "PLAYER TWO: You no have no more cards left in hand. "
										<< "You can now pick up your foot." << endl;
								}
								cout << "\n\n\n" << endl;
							}
						}
					}
				}
			}

/*******************************************************************************************************************************/

			else if (P2.Player2HandSize() == 0)
			{
				P2.DisplayPlayer2Foot(); // Calls the function that will display the Foot of player 2
				cout << "\n" << endl;
				ShowDiscardPile(); // Shows the cards that are in the discard pile
				cout << endl;

				cout << "PLAYER TWO: Do you want to (1) draw from the deck or (2) take the top five card on the discard pile? " << endl;
				cin >> CHOICE; // Get data from the player

				if (CHOICE == 1) // Executes if the player chooses to draw from the deck
				{
					P2.Player2DrawsFromTheDeckToFoot(); // Calls the function for adding cards from the darw deck to the Foot of player 1
					cout << endl;
					P2.DisplayPlayer2Foot(); // Calls the function that will display the Foot of player 2

					cout << "PLAYER TWO: DO you want to put down cards? (1) Yes and (2) No" << endl;
					cin >> CHOICE; // Get data from the player

					if (CHOICE == 1) // Executes if the player chooses to put down cards
					{
						P2.Player2PuttingDownCardsFromFoot(); // Calls the function that simulates the player putting down cards from their Foot

						cout << endl;
						P2.OrganizeAndDisplayPlayer2Cards(); // Calls the function that will display the cards the player has put down
						P2.DisplayPlayer2Foot(); // Calls the function that will display the Foot of player 2

						Discard = P2.Player2DiscardsFromFoot(); // This will get the card, of the player's choice, that they will discard from their Hand or their Foot
						DiscardPile.push_back(Discard); // Saves the value of Discard to the Discard Pile

						cout << "\n\n\n" << endl;
					}
					else
					{
						Discard = P2.Player2DiscardsFromFoot(); // This will get the card, of the player's choice, that they will discard from their Hand or their Foot
						DiscardPile.push_back(Discard); // Saves the value of Discard to the Discard Pile

						cout << "\n\n\n" << endl;
					}
				}
				else if (CHOICE == 2) // Executesif the player chooses to draw from the discard pile
				{
					DiscardQualification = P2.CheckPlayer2FootForTopDiscardCardTwinMatch(DiscardPile.back()); // Calls the function that will determine if the player has the points, in thier Hand, required to draw cards from the discard pile

					if (DiscardQualification == 1) // Executes if the player does not have the cards required to draw from the discard pile
					{
						// This loop will run 5 times to take 5 cards from the discard pile and transfer them to the Hand of the player
						for (int i = 0; i < 5; i++)
						{
							P2.Player2DrawsFromDiscardPileToFoot(DiscardPile.back()); // Sends the card that is at the top of the discard pile to the function that will add it to the Hand of the player
							DiscardPile.pop_back(); // Deletes the top card in the DiscardPile vector
						}

						P2.DisplayPlayer2Foot(); // Calls the function that will display the Foot of player 2

						cout << "PLAYER TWO: DO you want to put down cards? (1) Yes and (2) No" << endl;
						cin >> CHOICE; // Get data from the player

						if (CHOICE == 1) // Executes if the player chooses to put down cards
						{
							cout << "Player Two: You are able to put down cards." << endl;
							P2.Player2PuttingDownCardsFromFoot(); // Calls the function that simulates the player putting down cards from their Foot

							cout << endl;
							P2.OrganizeAndDisplayPlayer2Cards(); // Calls the function that will display the cards the player has put down
							P2.DisplayPlayer2Foot(); // Calls the function that will display the Foot of player 2

							Discard = P2.Player2DiscardsFromFoot(); // This will get the card, of the player's choice, that they will discard from their Hand or their Foot
							DiscardPile.push_back(Discard); // Saves the value of Discard to the Discard Pile
							cout << "\n\n\n" << endl;
						}
						else // Executes if the player chooses to not put down cards
						{
							Discard = P2.Player2DiscardsFromFoot(); // This will get the card, of the player's choice, that they will discard from their Hand or their Foot
							DiscardPile.push_back(Discard); // Saves the value of Discard to the Discard Pile

							cout << "\n\n\n" << endl;
						}
					}
					else // Executes if the player does not have the cards required to draw from the discard pile
					{
						P2.DisplayPlayer2Foot(); // Calls the function that will display the Foot of player 2

						cout << "PLAYER TWO: DO you want to put down cards? (1) Yes and (2) No" << endl;
						cin >> CHOICE; // Get data from the player

						if (CHOICE == 1) // Executes if the player chooses to put down cards
						{
							cout << "Player Two: You are able to put down cards." << endl;
							P2.Player2PuttingDownCardsFromFoot(); // Calls the function that simulates the player putting down cards from their Foot

							cout << endl;
							P2.OrganizeAndDisplayPlayer2Cards(); // Calls the function that will display the cards the player has put down
							P2.DisplayPlayer2Foot(); // Calls the function that will display the Foot of player 2

							Discard = P2.Player2DiscardsFromFoot(); // This will get the card, of the player's choice, that they will discard from their Hand or their Foot
							DiscardPile.push_back(Discard); // Saves the value of Discard to the Discard Pile

							cout << "\n\n\n" << endl;
						}
						else // Executes if the player chooses to not put down cards
						{
							Discard = P2.Player2DiscardsFromFoot(); // This will get the card, of the player's choice, that they will discard from their Hand or their Foot
							DiscardPile.push_back(Discard); // Saves the value of Discard to the Discard Pile

							cout << "\n\n\n" << endl;
						}
					}
				}
			}
			(system("cls")); // Clears the sceen of all previous text
		}
	

		cout << "End of Round " << i << endl; // Shows to the players that the end of the round has been reached
		cout << "\n\n\n\n" << endl;
		X = rand() % 200; // Re-randomizes the variable X for the next round

		Player1Score += P1.AddUpPointsFromBooksForPlayer1(); // Totals up the points that the player has accumenlated for the round and adds it to the overall score for that player
		cout << "PLAYER ONE: Has " << Player1Score << " points total" << endl; // Displays score for player 1 
		
		Player2Score += P2.AddUpPointsFromBooksForPlayer2(); // Totals up the points that the player has accumenlated for the round and adds it to the overall score for that player
		cout << "PLAYER ONE: Has " << Player2Score << " points total" << endl; // Displays score for player 12


		(system("cls")); // Clears the sceen of preivous txt
	}
	cout << "PLAYERS: You have reached the end of the game. " << endl; // Announces the end of the game to the players

	if (Player1Score > Player2Score) // This executes if the score of player 1 is greater than the score of player 2
	{
		cout << "PLAYER ONE: You won the game with " << Player1Score << " points" << endl; // Displays the score of player 1
		cout << "PLAYER TWO: You lost with " << Player2Score << " points" << endl; // Displays the score of player 2
	}
	else if (Player1Score < Player2Score) // This executes if the score of player 2 is greater than the score of player 1
	{
		cout << "PLAYER TWO: You won the game with " << Player2Score << " points" << endl; // Displays the score of player 2
		cout << "PLAYER ONE: You lost with " << Player1Score << " points" << endl; // Displays the score of player 1
	}

	return 0;
}


// This function is for displaying the cards that are in the DiscardPile vector
void ShowDiscardPile()
{
	if (DiscardPile.size() == 0) // Executes if there are no cards in the discard pile
	{
		cout << "DISCARD PILE: There are no cards in the discard pile." << endl;
	}
	else if (DiscardPile.size() > 0 && DiscardPile.size() < 5) // This executes if there are more than 1 and less than 5 card in the discard pile
	{
		cout << "DISCARD PILE: ";

		// This loop will run through the DiscardPile vector and display the card(s) that are stored in it
		// The loop will end when it goes through the entire vector
		for (int i = 0; i < DiscardPile.size(); i++)
		{
			if (DiscardPile.size() == 1) // Executes if there is only one card in the discard pile
			{
				cout << DiscardPile.at(i) << endl; // Outputs the current value of the DiscardPile vector
			}
			else if (DiscardPile.size() > 1 && DiscardPile.size() < 5) // Executes if there are more than 1 and less than 5 cards in the discard pile
			{
				cout << DiscardPile.at(i) << " "; // Outputs the current value of the DiscardPile vector
			}
		}
	}
	else if (DiscardPile.size() >= 5) // Executes if there are 5 or more card in the discard pile
	{
		cout << "DISCARD PILE (Top 5 cards): ";

		// This loop will run through the DiscardPile vector and display the cards that are stored in it
		// The loop will end when it goes through the last 5 values (which is the top of the discard pile) that are stored in the vector
		for (int i = (DiscardPile.size() - 5); i < DiscardPile.size(); i++)
		{
			cout << DiscardPile.at(i) << " "; // Outputs the current value of the DiscardPile vector
		}
	}
	cout << endl;
}