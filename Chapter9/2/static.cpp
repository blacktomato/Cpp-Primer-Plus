// Chapter -9- (p# 502)
// static.cpp -- using a static local variable
#include <iostream>
#include <string>
// function prototype

using namespace std;

void strcount(const string str);

int main()
{
    string input = "";
    while(true){
        cout << "Enter a line:\n";
        getline(cin, input);
        if(input == "") break;
        strcount(input);
    }
    cout << "Bye!" << endl;
    return 0;
}

void strcount(const string str)
{
    static int total = 0; // static local variable
    int count = str.size(); // automatic local variable
    cout << "\"" << str <<"\" contains ";
    total += count;
    cout << count << " characters\n";
    cout << total << " characters total\n";
}