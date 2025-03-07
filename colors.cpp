#include <iostream>
#include <string>
#include <vector>

using namespace std;

void makeGreen(char c) {
    cout << "\033[0;102m" << c <<  "\033[0m";
}

void makeYellow(char c) {
    cout << "\033[0;103m" << c <<  "\033[0m";
}

void makeGrey(char c) {
    cout << "\033[47m" << c <<  "\033[0m";
}