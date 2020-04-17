// Chapter -12- (p# 702)
#include <iostream>
#include "cow.h"

using namespace std;

int main(){
          //name    hobby       weight
    Cow c1("Jack", "Eat grass", 210.3 );  //custom constructor
    Cow c2("Jill", "Drink water", 189.8 );

    Cow c3;     // default constructor
    c3 = c1;    // assign operator

    Cow c4(c2); // copy constructor 

    cout << "c1 __ "; c1.ShowCow();
    cout << "c2 __ "; c2.ShowCow();
    cout << "c3 __ "; c3.ShowCow();
    cout << "c4 __ "; c4.ShowCow();

    return 0;
}