#include "fBullCowGame.h"



fBullCowsgame::fBullCowsgame()
{
	Reset();
}

//getters
int32 fBullCowsgame::GetMaxTries() const { return MyMaxTries; }
int32 fBullCowsgame::GetCurrentTry() const { return MyCurrentTries; }
int32 fBullCowsgame::GetHiddenWordLength() const {	return MyHiddenWord.length();}
bool fBullCowsgame::IsGameWon() const { return bGameIsWon;}


void fBullCowsgame::Reset()
{
	constexpr int32 Max_Tries = 8;
	const FString Hidden_Word = "planet";
	
	MyMaxTries = Max_Tries;
	MyHiddenWord = Hidden_Word;
	MyCurrentTries = 1;
	bGameIsWon = false;
	return;
}







EGuessStatus fBullCowsgame::CheckGuessValidity(FString Guess) const
{
	if (false)//if the guess is not an isogram
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (Guess.length() != GetHiddenWordLength()) //if the guess is not the correct length
	{
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
FBullCowCount fBullCowsgame::SubmittValidGuess(FString Guess)
{
	MyCurrentTries++;
		// setup a return value
	FBullCowCount BullCowCount;
	int32 WordLength = MyHiddenWord.length();//assuming same length as guess

	//loop through all letters in the hidden word
	for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++) 
	{
		//compare letters against the guess
		for (int32 GChar = 0; GChar < WordLength; GChar++) {
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
	if (BullCowCount.Bulls == WordLength)
	{
		bGameIsWon = true;

	}
	else
	{
		bGameIsWon = false;
	}
	return BullCowCount;
}
