// Skynet.cpp : Aerial drone program

// visual studio file
#include "pch.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int main()
{
	// seed random number generator
	srand(static_cast<unsigned int>(time(0)));
	// keeps the main loop running until the player ends the game
	bool playing = true;
	// the random enemy location on an 8 x 8 grid (1-64)
	int enemyPos = rand() % 64 + 1;
	// lowest number that the enemy can be found
	int searchGridLowNumber = 1;
	// highest number that the enemy can be found
	int searchGridHighNumber = 64;
	// amount of predictions the software made
	int pings = 0;

	// intro text
	cout << "Generating random enemy location on 8 x 8 grid...\n";
	cout << "The enemy is located at location #" << enemyPos << " on 8 x 8 grid with 1-64 sectors.\n";
	cout << "Skynet HK-Aerial Initializing Search Software...\n";

	cout << "================================================================================\n";
	
	// Main play loop that continues until the player is finished
	while (playing)
	{
		string winner;
		int winnerPingAmount;

		/*
		Binary search program (drone program)
		Loops endlessly until the enemy is found
		*/
		while (true)
		{

			cout << "Skynet HK-Aerial Radar sending out ping #" << pings << endl;

			// guess grid number
			int searchedPos = ((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;

			// executes if the guess is equal to the enemy location
			if (searchedPos == enemyPos)
			{
				cout << "Enemy was hiding at location #" << enemyPos << endl;
				cout << "Target was found at location #" << enemyPos << endl;
				cout << "Skynet HK-Aerial Software took " << pings << " predictions to find the enemy location on a grid size of 8 x 8 (64)" << endl;

				winner = "Binary Search AI";
				winnerPingAmount = pings;
				pings = 0;

				// break out of the loop
				break;
			}
			// executes if the guess is too low
			else if (searchedPos < enemyPos)
			{
				// increases the prediction count by 1
				pings++;
				// increases the minimum grid number that the enemy can be found
				searchGridLowNumber = searchedPos + 1;

				cout << "The target location prediction of " << searchedPos << " was lower than the actual enemy location of " << enemyPos << endl;
				cout << "The new search grid low is " << searchGridLowNumber << endl;
			}
			else
			{
				// increases the prediction count by 1
				pings++;
				// decrease the highest grid number that the enemy can be found
				searchGridHighNumber = searchedPos - 1;

				cout << "The target location prediction of " << searchedPos << " was higher than the actual enemy location of " << enemyPos << endl;
				cout << "The new search grid high is " << searchGridHighNumber << endl;
			}
			cout << "================================================================================\n";
		}

		cout << "\n\n";

		/*
		Linear search AI
		Loops over the number of grid locations until the enemy is found
		*/
		for (int index = 1; index <= searchGridHighNumber; index++)
		{
			// current integer is too small
			if (index < enemyPos)
			{
				cout << "The target location prediction of " << index << " was less than the actual enemy location of " << enemyPos << endl;
			}
			// integer is the corrent one
			else if (index == enemyPos)
			{
				cout << "Enemy was hiding at location #" << enemyPos << endl;
				cout << "Target was found at location #" << enemyPos << endl;
				cout << "Linear search AI took " << index << " predictions to find the enemy location on a grid size of 8 x 8 (64)" << endl;

				// check if winning ping amount is higer than current pings
				if (winnerPingAmount > index) {
					winnerPingAmount = index;
					winner = "Linear Search AI";
				}

				// break out of the loop
				break;
			}
			// current integer is too big
			else
			{
				cout << "The target location prediction of " << index << " was higher than the actual enemy location of " << enemyPos << endl;
			}
		}

		cout << "\n\n";

		/*
		Random number guess AI
		Loops endlessly until the enemy location is randomly guessed
		*/
		while (true)
		{
			int guess = rand() % 64 + 1;

			if (guess < enemyPos)
			{
				pings++;

				cout << "The target location prediction of " << guess << " was less than the actual enemy location of " << enemyPos << endl;
			}
			else if (guess == enemyPos)
			{
				cout << "Enemy was hiding at location #" << enemyPos << endl;
				cout << "Target was found at location #" << enemyPos << endl;
				cout << "Random number guesser took " << pings << " predictions to find the enemy location on a grid size of 8 x 8 (64)" << endl;

				// check if winning ping amount is higer than current pings
				if (winnerPingAmount > pings) {
					winnerPingAmount = pings;
					winner = "Random Number AI";
				}

				// sets pings back to zero for the next algorithm/player
				pings = 0;

				// break out of the loop
				break;
			}
			else
			{
				pings++;

				cout << "The target location prediction of " << guess << " was higher than the actual enemy location of " << enemyPos << endl;
			}
		}

		cout << "\n\n";

		/*
		Player guess loop
		Loops endlessly until the player guesses the enemy location
		*/
		while (true)
		{
			int guess;

			cout << "Enter your guess: ";
			cin >> guess;

			if (guess < enemyPos) {
				pings++;

				cout << "The target location prediction of " << guess << " was less than the actual enemy location" << endl;
			}
			else if (guess == enemyPos)
			{
				cout << "Enemy was hiding at location #" << enemyPos << endl;
				cout << "Target was found at location #" << enemyPos << endl;
				cout << "Player took " << pings << " predictions to find the enemy location on a grid size of 8 x 8 (64)" << endl;

				// check if winning ping amount is higer than current pings
				if (winnerPingAmount > pings) {
					winnerPingAmount = pings;
					winner = "Player Search";
				}

				// break out of the loop
				break;
			}
			else
			{
				pings++;

				cout << "The target location prediction of " << guess << " was higher than the actual enemy location" << endl;
			}
		}

		cout << "\n\n";
		cout << winner << " won with " << winnerPingAmount << " pings!\n";
		cout << "Would you like to play again? ";

		// answer that the player gives
		string answer;
		// get player input
		cin >> answer;

		// if answer is "n" then stop the loop
		if (answer == "n")
		{
			playing = false;

			cout << "Thanks for playing!\n";
		}
	}

	// keeps the console from closing
	system("pause");

	return 0;
}
