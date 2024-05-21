#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <fstream>
#include <algorithm>
#include <map>
#include <termios.h>
#include <unistd.h>
#include "colors.h"

using namespace std;


int randomizer(int max) {
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(1, max);
    return dist(mt);
}

string readDictionary(vector<string> &words) {
    ifstream file("sgb-words.txt");
    string word;
    while (file >> word) {
        words.push_back(word);
    }
    
    int random_index = -1;

    if (!words.empty()) {
        random_index = randomizer(words.size()) - 1;
        // cout << "Random word: " << words[random_index] << endl;
    } else {
        cout << "Error, no words found in file." << endl;
    }

    return words[random_index];
}

bool errorOccurred = false;

bool wordColors(string &guess, string &secret_word, vector<string> &words, int &guessCount) {
    // if guess is NOT in words OR guess is NOT five letters long
    if (find(words.begin(), words.end(), guess) == words.end() || guess.size() != 5) {
        cout << "\n\033[A\33[2K\r";
        cout << "! Try again, must be a real word and 5 letters long.";

        if (!errorOccurred) {
            guessCount -= 1;
            errorOccurred = true;
        }
        
        return 1;
    } else {
        guessCount += 1;
        errorOccurred = false;
    }
    
    // for (char c : guess) {
    //     // if guess has number
    //     if (isdigit(c)) {
    //         cout << "\n\033[A\33[2K\r";
    //         cout << "! Try again, must be a real word and 5 letters long.";
    //         return 1;
    //     }
    //     // if guess has special character
    //     // if (isalnum(c)){
    //     //     cout << "\n\033[A\33[2K\r";
    //     //     cout << "! Try again";
    //     //     return 1;
    //     // }
    // }

    map<char, bool> duplicates;

    for (int i = 0; i < guess.size(); ++i) {
        if (i < secret_word.size() && guess[i] == secret_word[i]) {
            makeGreen(guess[i]);
            duplicates[guess[i]] = true;
        } else if (!duplicates[guess[i]] && secret_word.find(guess[i]) != string::npos) {
            makeYellow(guess[i]);
            duplicates[guess[i]] = true;
        } else {
            makeGrey(guess[i]);
        }
    }

    return 0;
}

bool guessWord(string &guess, string &secret_word) {
    if (guess == secret_word) {
        return true;
    } else {
        return false;
    }
}

string readInputAndClear() {
    string input;
    getline(cin, input);

    // Move up one line, clear the line, return to the beginning
    cout << "\033[A\33[2K\r";
    
    return input;
}