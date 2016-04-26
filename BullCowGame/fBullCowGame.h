#pragma once
#include <string>

using FString = std::string;
using int32 = int;

//all values initailized to zero
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus
{
	Invalid_Status,
	Ok,
	Not_Isogram,
	Wrong_Lemgth,
	Not_Lowercase
};



class fBullCowsgame
{
public:
	fBullCowsgame(); //Constructor
	int32 GetMaxTries() const;
	int32 GetCurrentTry()const;
	int32 GetHiddenWordLength() const; 
	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(FString) const; //TODO Make a more rich return value

	void Reset(); 
	FBullCowCount SubmittValidGuess(FString);

	//string GetRules();
	//int32 GetBulls();
	//int32 GetCows();


//Ignore this and focus on the interface above 
private:
	//see constructor for initialization
	int32 MyCurrentTries;
	int32 MyMaxTries;
	FString MyHiddenWord;
	bool bGameIsWon;
};