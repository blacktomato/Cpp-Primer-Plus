#include <iostream>
#include <string>
#include <string.h>
#include "person.h"

using namespace std;

//static const int LIMIT = 25;
//string lname;
//char fname[LIMIT];

Person::Person(const string & ln, const char * fn){
    lname = ln;
    strcpy(fname, fn);
}

void Person::Show() const{
    cout << fname << " " << lname;
}

void Person::FormalShow() const{
    cout << lname << ", " << fname;
}