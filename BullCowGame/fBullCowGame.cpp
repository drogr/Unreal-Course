#include "fBullCowGame.h"



fBullCowsgame::fBullCowsgame()
{
	Reset();
}

int32 fBullCowsgame::GetMaxTries() const { return MyMaxTries; }
int32 fBullCowsgame::GetCurrentTry() const { return MyCurrentTries; }
int32 fBullCowsgame::GetHiddenWordLength() const {	return MyHiddenWord.length();}



void fBullCowsgame::Reset()
{
	constexpr int32 Max_Tries = 8;
	MyMaxTries = Max_Tries;
	const FString Hidden_Word = "planet";
	MyHiddenWord = Hidden_Word;
	MyCurrentTries = 1;
	
	return;
}



bool fBullCowsgame::IsGameWon() const
{
	return false;
}

EGuessStatus fBullCowsgame::CheckGuessValidity(FString) const
{
	if (false)//if the guess is not an isogram
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (true) //if the guess is not the correct length
	{
		Guess.length() != GetHiddenWordLength;
		return EGuessStatus::Wrong_Lemgth;
	}
	else if (false) //if the guess is not lower case
	{
		return EGuessStatus::Not_Lowercase;
	}
	else
	{
		return EGuessStatus::Ok;
	}
	

	
		//return an error
	//otherwise
		//return OK
}

// recieves a VALID guess, incraments turn, and returns count
FBullCowCount fBullCowsgame::SubmittGuess(FString Guess)
{
	//incriment the turn number
	MyCurrentTries++;
		// setup a return value
	FBullCowCount BullCowCount;
	//loop through all letters in the guess
	int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++) 
	{
		//compare letters against the hidden word
		for (int32 GChar = 0; GChar < HiddenWordLength; GChar++) {
			//if they match then
			if (Guess[GChar] == MyHiddenWord[MHWChar]) //checking to see if chars in position [X	] match
			{
				if (MHWChar == GChar)				//if in the same place
				{
					BullCowCount.Bulls++; //incriment Bulls
				}
				else
				{
					BullCowCount.Cows++;	//must be a cow. increment cows
				}
			}
		}
	}
	return BullCowCount;
}
