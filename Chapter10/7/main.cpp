// Chapter -10- (p# 561)
#include <iostream>
#include "plorg.h"

using namespace std;

int main(){
    Plorg p1;
    cout << "p1: ";
    p1.report();

    Plorg p2("Star", 24);
    cout << "p2: ";
    p2.report();

    p1.set_CI(20);
    cout << "\nSet the CI of p1 to 20\n" << "p1: ";
    p1.report();

    return 0;
}