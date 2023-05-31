#include "Game.h"
#include <iostream>
#include <fstream>
#include <time.h>
void Game::setup() {
    std::string word = "";
	std::ifstream input("words.txt");
	if (input.is_open() == true) {
        while (!input.eof()) {
            input >> word;
            if (input.fail()) break;
            words.push_back(word);
        } //End While
    } //End if
}

void Game::run(std::ostream& ostr) {
    srand(time(NULL));
    word = words[(rand() % 10)];
    //std::cout << word << std::endl; //uncomment for debug :)
    for (int i = 0; i < word.size(); i++) {
        wordl.push_back(word[i]);
    }
    displayLetters(ostr);
    while ((guesses > 0)&&!won) {
        char guess = getGuess();
        bool found = checkLetter(guess);
        if (!found) {
            guesses--;
            if (guesses>0) std::cout << "That letter is not in the word. Try again" << std::endl;
        }
        displayLetters(ostr);
        won = allGuessed();
    }
    if (won) {
        std::cout << "Congratulations! You won!" << std::endl;
    }
    else {
        std::cout << "You ran out of guesses! The word was " << word << std::endl;
    }
}

void Game::displayLetters(std::ostream& ostr) {
    for (Game::letter l : wordl) {
        bool guessed = l.guessed;
        ostr << (guessed ? l.c : '_') << " ";
    }
    ostr << std::endl;
    if (guessedLetters.size() > 0) {
        ostr << "The letters you've guessed are: ";
        for (char c : guessedLetters) {
            ostr << c << (c == guessedLetters.back() ? "" : ", ");
        }
        ostr << std::endl;
    }
}

char Game::getGuess() {
    char character = '0';
    while (true) {
        std::cout << "Enter a guess - you have " << guesses << " guesses remaining" << std::endl;
        std::cin >> character;
        
        if (!validLetter(character)) {
            std::cout << "Invalid letter" << std::endl;
        }
        else {
            if (std::count(guessedLetters.begin(), guessedLetters.end(), character)) {
                std::cout << "Letter has already been guessed. Guess again" << std::endl;
            }
            else {
                break;
            }
        }
    }
    return character;
}

bool Game::validLetter(char c) {
    return (c >= 65 && c <= 90) || (c >= 97 && c <= 122);
}

char Game::toLowercase(char c) {
    if (c >= 97 && c <= 122) return c;
    if (c >= 65 && c <= 90) return c + 32;
    return -1;
}

bool Game::checkLetter(char c) {
    bool found = false;
    for (letter& l : wordl) {
        if (tolower(l.c) == tolower(c)) {
            found = true;
            l.guessed = true;
        }
    }
    guessedLetters.push_back(c);
    return found;
}

bool Game::allGuessed() {
    for (letter l : wordl) {
        if (!(l.guessed)) return false;
    }
    return true;
}