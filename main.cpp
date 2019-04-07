/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jorda
 *
 * Created on April 7, 2019, 5:18 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;

/*
 * 
 */
int main(int argc, char **argv)
{

    // Maximum number of incorrect guess until game over
    const int MAX_NUMBER_GUESSES = 8;

    // collection of possible words to guess
    vector<string> words;
    words.push_back("DOG");
    words.push_back("CAT");
    words.push_back("GAME");
    words.push_back("HANGMAN");
    words.push_back("ADVENTURE");

    srand(static_cast<unsigned int>(time(0)));

    // Shuffle the vector
    random_shuffle(words.begin(), words.end());

    // Word to guess
    const string WORD_TO_GUESS = words[0];

    // Number of wrong guesses
    int wrongGuesses = 0;

    // Word guessed so far, the current state of player guess
    string currentPlayerString(WORD_TO_GUESS.size(), '_');

    // Letters already guessed
    string lettersUsed = "";

    // Game Loop
    while ((wrongGuesses != MAX_NUMBER_GUESSES) && (currentPlayerString != WORD_TO_GUESS))
    {
        // Inform player of their current number of guesses remaining
        cout << "\n\nYou have " << (MAX_NUMBER_GUESSES - wrongGuesses) << " guess left! \n";

        // Inform player of their former guesses
        cout << "\nYou have used the following letters:\n"
             << lettersUsed << endl;

        // Inform player of their current string
        cout << "\nYou current guess is:\n"
             << currentPlayerString << endl;

        // Get a letter to guess
        char playerGuess;
        cout << "\n\nEnter your guess: ";
        cin >> playerGuess;
        playerGuess = toupper(playerGuess);

        // Don't let the player guess a previous guess
        while (lettersUsed.find(playerGuess) != string::npos)
        {
            cout << "\nYou've already guessed " << playerGuess << endl;
            cout << "\n\nEnter your guess: ";
            cin >> playerGuess;
            playerGuess = toupper(playerGuess);
        }

        // A the guess to the list of letters used
        lettersUsed += playerGuess;

        // If the guess is in the word to guess update the players string
        if (WORD_TO_GUESS.find(playerGuess) != string::npos)
        {
            cout << "That's right! " << playerGuess << " is in the word. \n";
            // Update currentPlayerString
            for (int i = 0; i < WORD_TO_GUESS.length(); i++)
            {
                if (WORD_TO_GUESS[i] == playerGuess)
                {
                    currentPlayerString[i] = playerGuess;
                }
            }
        }
        // If the guess isn't in the word increase the number of wrong guesses
        else
        {
            cout << "Sorry, " << playerGuess << " is not in the word.\n";
            wrongGuesses++;
        }
    }

    // If the player hits the number max number of wrong guesses end the game
    if (wrongGuesses == MAX_NUMBER_GUESSES)
    {
        cout << "\nYou've been hanged!";
    }

    // If the player has won the game, inform the player
    else
    {
        cout << "\nYou have won the game!";
    }

    // Confirm 
    cout << "\nThe word was" << currentPlayerString << endl;

    return 0;
}
