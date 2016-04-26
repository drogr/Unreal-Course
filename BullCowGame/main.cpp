/*This is the console executable that makes use of the BullCow class
this acts as the view in a MCV pattern and is responsible for all
user interaction. For game logic see the FBullCowGame class.
*/


#include<iostream>
#include<string>
#include "fBullCowGame.h"

using ftext = std::string;
using int32 = int;

void PrintIntro();
ftext GetGuess(); 
void PlayGame();
bool AskToPlayAgain();

fBullCowsgame bcgame; //instantiate a new game


// The entry point for this application
int main() 
{
	bool bPlayAgain = false;
	do
	{
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);

	return 0; //exit the application
}






//introduce the game
	void PrintIntro()
	{

		std::cout << "Welcome to Bulls and Cows!\n";
		std::cout << "Can you guess the " << bcgame.GetHiddenWordLength();
		std::cout << " letter isogram I'm thinking of?\n";
		std::cout << std::endl;
		return;
	}

//play the game
	void PlayGame()
	{
		bcgame.Reset();
		int32 MaxTries = bcgame.GetMaxTries(); 
		std::cout << MaxTries << std::endl;
		for (int32 count = 1; count <= MaxTries; count++) 	// TODO change the FOR loop to WHILE loop once weare validating tries
		{
			ftext Guess = GetGuess();

			EGuessStatus Status = bcgame.CheckGuessValidity(Guess);

			//submit valid guess to the game and recieve counts
			FBullCowCount BullCowCount = bcgame.SubmittGuess(Guess);

			//print number of bulls and cows
			std::cout << "Bulls = " << BullCowCount.Bulls;
			std::cout << ". Cows = " << BullCowCount.Cows << std::endl;
			std::cout << std::endl;
		} 
		// TODO add a game summary
	}

	bool AskToPlayAgain()
	{
		std::cout << "Do you want to play again? (y/n)"; \
			ftext Response = "";
		std::getline(std::cin, Response);
		return  (Response[0] == 'Y') || (Response[0] == 'y');
	}

// g et a guess from the player1
	ftext GetGuess() // TODO change to GetValidGues
	{
		int32 CurrentTry = bcgame.GetCurrentTry();
		ftext Guess = "";
		std::cout << "Try "<< CurrentTry<<". Enter your guess: ";
		std::getline(std::cin, Guess);
		return Guess;
	}




