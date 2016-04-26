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
ftext GetValidGuess(); 
void PlayGame();
bool AskToPlayAgain();

fBullCowsgame BCGame; //instantiate a new game


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
		std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
		std::cout << " letter isogram I'm thinking of?\n";
		std::cout << std::endl;
		return;
	}

//play the game
	void PlayGame()
	{
		BCGame.Reset();
		int32 MaxTries = BCGame.GetMaxTries(); 

		//loop asking for guesses while the game 
		//is NOT won and there are still tries remaining
		while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)		
		{
			ftext Guess = GetValidGuess();

			//submit valid guess to the game and recieve counts
			FBullCowCount BullCowCount = BCGame.SubmittValidGuess(Guess);

			//print the results of the guess
			std::cout << "Bulls = " << BullCowCount.Bulls;
			std::cout << ". Cows = " << BullCowCount.Cows << "\n\n";
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

//loop continually untill the user gives a valid guess
	ftext GetValidGuess()
	{
		ftext Guess = "";
		EGuessStatus Status = EGuessStatus::Invalid_Status;
		do
		{
			//get a guess from the player 
			int32 CurrentTry = BCGame.GetCurrentTry();
			std::cout << "Try " << CurrentTry << ". Enter your guess: ";
			std::getline(std::cin, Guess);

			Status = BCGame.CheckGuessValidity(Guess);
			switch (Status)
			{
			case EGuessStatus::Not_Isogram:
				std::cout << "That is not an isogram. ";
				std::cout << "An isogram is a word that does not repeat any letters.\n";
				break;
			case EGuessStatus::Wrong_Lemgth:
				std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter guess.\n";
				break;
			case EGuessStatus::Not_Lowercase:
				std::cout << "Please enter your guess in all lower case.\n";
				break;
			default:
				//assume the guess is valid
				break;
			}
			std::cout << std::endl;
		} while (Status != EGuessStatus::Ok); //Keep looping until we get no errors
		return (Guess);
	}

