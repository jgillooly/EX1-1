#pragma once
#include <vector>
#include <string>
class Game
{
	struct letter {
		letter(char value) { c = value; }
		char c;
		bool guessed = false;
	};
public:
	void setup();
	void run(std::ostream& ostr);
private:
	std::vector<std::string> words;
	std::string word;
	std::vector<letter> wordl;
	std::vector<char> guessedLetters;
	int guesses = 7;
	bool won = false;
	void displayLetters(std::ostream& ostr);
	char getGuess();
	bool validLetter(char c);
	bool checkLetter(char c);
	char toLowercase(char c);
	bool allGuessed();
};

