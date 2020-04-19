#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include "store.h"

using namespace std;

void ShowStr(string &s);
void GetStrs(ifstream &fin, vector<string> &vistr);

int main() {
    vector<string> vostr;
    string temp;
    // acquire strings
    cout << "Enter strings (empty line to quit):\n";
    while (getline(cin, temp) && temp[0] != '\0')
        vostr.push_back(temp);
    cout << "Here is your input.\n";
    for_each(vostr.begin(), vostr.end(), ShowStr);
    // store in a file
    ofstream fout("strings.dat", ios_base::out | ios_base::binary);
    for_each(vostr.begin(), vostr.end(), Store(fout));
    fout.close();
    // recover file contents
    vector<string> vistr;
    ifstream fin("strings.dat", ios_base::in | ios_base::binary);
    if (!fin.is_open())
    {
        cerr << "Could not open file for input.\n";
        exit(EXIT_FAILURE);
    }
    GetStrs(fin, vistr);
    cout << "\nHere are the strings read from the file:\n";
    for_each(vistr.begin(), vistr.end(), ShowStr);
    return 0;
}

void ShowStr(string &s){
    cout << s << endl;
}

void GetStrs(ifstream &fin, vector<string> &vistr){
    size_t len;
    while ( fin.read( (char*)&len, sizeof(size_t) ) ){
        char ch;
        string str;
        for(int i = 0; i < len; i++){
            fin.read(&ch, sizeof(char));
            str.push_back(ch);
        }
        vistr.push_back(str);
    }
}