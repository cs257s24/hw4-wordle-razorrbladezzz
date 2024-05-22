#include <iostream>
#include <string>
#include <vector>
#include <set>
#include "game.h"

using namespace std;


int main() {
    set<string> validResponses = {"Y", "y", "Yes", "yes"};
    string playAgain;

    cout << R"(
        
   █████████             █████        █████ ████        
  ███░░░░░███           ░░███        ░░███ ░░███          
 ███     ░░░   ██████   ███████    ███████  ░███   ██████ 
░███          ░░░░░███ ░░░███░    ███░░███  ░███  ███░░███
░███           ███████   ░███    ░███ ░███  ░███ ░███████ 
░░███     ███ ███░░███   ░███ ███░███ ░███  ░███ ░███░░░  
 ░░█████████ ░░████████  ░░█████ ░░████████ █████░░██████ 
  ░░░░░░░░░   ░░░░░░░░    ░░░░░   ░░░░░░░░ ░░░░░  ░░░░░░  
  )" << endl;

    cout << "\n[Press ENTER to continue]\n";
    cin.get();

    cout << R"(
   /\_/\
   >^.^<.---.
  _'-`-'     )\
 ( --\ |--\ (`.`-.
     --'  --'  ``-' )" << endl;

    cout << "\033[4m" << "How to play:" << "\033[0m" << "\nThere is a hidden word, and you must guess it!\nThe colors will change, and they're all clues.\n- "
    << "\033[0;102m" << "Green" << "\033[0m" << ": letter is in the right spot!\n- " << "\033[0;103m" << "Yellow" <<
    "\033[0m" << ": letter is in the secret word, but wrong spot\n- " << "\033[47m" << "Grey"
    << "\033[0m" << ": letter is not in the secret word :(" << endl;

    cout << "\n[Press ENTER to continue]" << endl;
    cin.get();

    cout << "\033[4m" << "Rules:" << "\033[0m" << endl;
    cout << "- Six guesses total :3\n- No numbers :3\n- No special characters :3\n- Five-letter words only :3\n- Invalid words will be cleared :3" << endl;

    cout << "\n[Press ENTER to continue]\n";
    cin.get();

    do {
        vector<string> words;
        string secret_word = readDictionary(words);
        string guess;
        int guessCount = 0;

        cout << R"(
    _._     _,-'""`-._
   (,-.`._,'(       |\`-/|
       `-.-' \ )-`( , o o)
             `-    \`_`"'- )" << endl;

        cout << "\nA word has been chosen, submit your guesses below: \n12345" << endl;

        while (true) {
            // cin >> guess;
            string guess = readInputAndClear();
            wordColors(guess, secret_word, words, guessCount);
            cout << endl;

            if (guessWord(guess, secret_word)) {
                cout << "Congrats, you guessed the word " << "\033[0;102m" << secret_word <<  "\033[0m" << "!" << endl;
                break;
            } else if (guessCount >= 6) {
                cout << "Too many guesses! The word was: " << secret_word << endl;
                break;
            }
        }
        cout << "Would you like to play again? (Y/N)" << endl;
        cin >> playAgain;
        cin.ignore(1000, '\n');
    } while (validResponses.count(playAgain));

    cout << "\nBye bye" << endl;
    cout << R"(
  ,-.       _,---._ __  / \
 /  )    .-'       `./ /   \
(  (   ,'            `/    /|
 \  `-"             \'\   / |
  `.              ,  \ \ /  |
   /`.          ,'-`----Y   |
  (            ;        |   '
  |  ,-.    ,-'         |  /
  |  | (   |            | /
  )  |  \  `.___________|/
  `--'   `--'
    )" << endl;

    return 0;
}