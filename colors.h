#ifndef COLORS_H
#define COLORS_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Make Green
// - Changes target character to green
// - Green means the letter is in the right spot
// Parameters:
// - char c: selected letter, chosen from index of guess
// Returns: void
void makeGreen(char c);

// Make Yellow
// - Changes target character to yellow
// - Yellow means the letter is in the word, but wrong spot
// Parameters:
// - char c: selected letter, chosen from index of guess
// Returns: void
void makeYellow(char c);

// Make Grey
// - Changes target character to grey
// - Grey means the letter is not in the word
// Parameters:
// - char c: selected letter, chosen from index of guess
// Returns: void
void makeGrey(char c);

#endif