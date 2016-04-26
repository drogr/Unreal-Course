#include<iostream>
#include<string>

using namespace std;	

void PrintIntro();
string GetGuess();
}

// The entry point for this application
int main()
{
	PrintIntro();

	GetGuess();

	cout << endl;
	return 0;
}

//Introduce the gamne
void PrintIntro() {
	constexpr int WORD_LENGTH = 5;
	cout << "Welcome to Jeff's Bulls and Cows Game! It's a fun word game.\n";
	cout << "Can you guess the " << WORD_LENGTH;
	cout << " letter isogram I'm think of?\n";
	cout << endl;
	return;
}

// Get a guess from the player1
string GetGuess() {
	string Guess = "";
	cout << "Enter your guess: ";
	getline(cin, Guess);
	       
	// Prints the guess back to them
	cout << "Your guess was: " << Guess << endl;
	return Guess;
}



