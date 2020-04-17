#include <iostream>
#include <string.h>
#include "golf.h"

using namespace std;

void setgolf(golf & g, const char * name, int hc){
    strcpy(g.fullname, name);
    g.handicap = hc;
}

int setgolf(golf & g){
    char input[Len];
    char next;

    cout << "Enter the player's name: \n"; 
    cin.ignore(); // flush the \n left by the last cin.get()
    cin.get(input, Len);
    if (input[0] == '\0') return 0;
    strcpy(g.fullname, input);
    cout << "Enter the player's handicap: \n"; 
    cin >> g.handicap;
    return 1;
}

void handicap(golf & g, int hc){
    g.handicap = hc;
}

void showgolf(const golf & g){
    cout << "Player: " << g.fullname << "\tHandicap: " << g.handicap << endl;
}