#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <vector>
#include <random>
using namespace std;

// Randomizer
// - Generates a random number using Mesenne Twister PRNG
// Parameters:
// - int max: the max range of random numbers
// Returns:
// - int: the resulting randomized integar
int randomizer(int max);

// Read Dictionary
// - Reads a file of words and finds a random one based on its index
// Dependancies: 
// - randomizer(): used to generate a random index for selecting a word
// Parameters: 
// - vector<string> &words: referenced vector where the words from the file will be stored
// Returns:
// - string: the resulting random word
string readDictionary(vector<string> &words);

// Word Colors
// - Colors the letters in the guess based on their relation to the secret word
// Parameters:
// - string &guess: the guessed word where the letters will change colors
// - string &secret_word: the secret word of which the guess is compared to
// - vector<string> &words: the list of possible words
// Returns: void, but it changes the guess string by coloring its letters
void wordColors(string &guess, string &secret_word, vector<string> &words, int &guessCount);

// Guess Word
// - Checks if any input of guess matches the secret word
// Parameters:
// - string &guess: the guessed word
// - string &secret_word: the secret word to be guessed
// Returns: bool
// true if guess == secret_word, false otherwise
bool guessWord(string &guess, string &secret_word);

// Read Input and Clear
// - Reads input, stores it, and stops the echo that would occur
// Parameters: none
// Returns: string
// - Returns the inputted string to be used as the guess variable
string readInputAndClear();

#endif