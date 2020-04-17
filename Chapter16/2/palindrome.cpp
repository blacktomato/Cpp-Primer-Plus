#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isPalindrome(string s);
void toLower(char &c);
void remove_nonalpha(string &s);


int main(){
    string test;
    cout << "Please enter a string to check if it is a palindrome: (q for quit)"<< endl;
    while(getline(cin, test) && test != "q"){
        if (test == "") {
            cout << "Please do not enter a empty string..."<< endl;
            continue;
        } 
        if(isPalindrome(test)) cout << "The string is a palindrome!" << endl;
        else cout << "The string is not a palindrome...." << endl;
        cout << "Please enter a string to check if it is a palindrome: (q for quit)"<< endl;
    }
    cout << "Bye!" << endl;
}

bool isPalindrome(string s){
    remove_nonalpha(s);
    for_each(s.begin(), s.end(), toLower);// to lower case
    string::iterator i = s.begin();
    string::iterator j = s.end() - 1;
    while(i != j){
        if (*i != *j) return false;
        else if (j == ++i) return true;
        else j--;
    }
    return true;
}

void toLower(char &c){
    c = tolower(c);
}

void remove_nonalpha(string &s){
    for(int i = 0; i < s.size(); i++){
        if (!isalpha(s[i])) 
        {
            s.erase(s.begin()+i);
            i--;
        }
    }
}