#include <iostream>
#include <string.h>
#include "classic.h"

using namespace std;

//class Classic
Classic::Classic(const char *d1, const char *s1, const char *s2, int n, double x)
                :Cd(s1, s2, n, x){
    strcpy(description, d1);
}

Classic::Classic(const Classic &c)
                :Cd(c){
    strcpy(description, c.description);
}

Classic::Classic(): Cd(){
    description[0] = '\0';
}

void Classic::Report() const{
    Cd::Report();
    cout << "description: " << description << "\n";
}

Classic & Classic::operator=(const Classic &d){
    if (this == &d)
        return *this;
    Cd::operator=(d);
    strcpy(description, d.description);
    return *this;
}