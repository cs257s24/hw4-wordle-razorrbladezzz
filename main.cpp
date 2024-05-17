#include <iostream>
#include <string>
#include <vector>
#include <set>
#include "game.h"
using namespace std;


int main() {
    set<string> validResponses = {"Y", "y", "Yes", "yes"};
    string playAgain;

    cout << "Catdle" << endl;
    // insert cat-themed ASCII
    // i dont want to format this yet
    cout << "\nHow to play:\nThere is a hidden word, and you must guess it!\nThe colors will change, and they're all clues.\n"
    << "\033[0;102m" << "Green" << "\033[0m" << ": letter is in the right spot!\n" << "\033[0;103m" << "Yellow" <<
    "\033[0m" << ": letter is in the secret word, but wrong spot\n" << "\033[47m" << "Grey"
    << "\033[0m" << ": letter is not in the secret word :(" << endl;
    cout << "\nRules:" << endl;
    cout << "No numbers :3\nNo special characters :3\nFive-letter words only :3" << endl;

    cout << "\n[Press ENTER to continue]" << endl;
    cin.get();

    do {
        vector<string> words;
        string secret_word = readDictionary(words);
        string guess;

        cout << "A word has been chosen, submit your guesses below: \n12345" << endl;
        while (true) {
            // cin >> guess;
            string guess = readInputAndClear();
            wordColors(guess, secret_word, words);
            cout << endl;
            if (guessWord(guess, secret_word)) {
                cout << "congrats u won yippie" << endl;
                break;
            }
        }
        cout << "would you like to play again? (Y/N)" << endl;
        cin >> playAgain;
        cin.ignore(1000, '\n');
    } while (validResponses.count(playAgain));

    return 0;
}