#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;


// check if word is five letters long()
// - clears word, no response

// check if word is in dictionary()
// - clears word, no response

// check for numbers()
// - clears word, no response
bool numberCheck(string &guess) {
    for (char c : guess) {
        if (isdigit(c)) {
            // string readInputAndClear();
            cout << "\n\033[A\33[2K\r";
            return 1;
        }
    }
    return 0;
}

// check for special characters()
// - clears word, no response