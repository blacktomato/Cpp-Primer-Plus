// Chapter -10- (p# 559)
#include <iostream>
#include "person.h"
#include <vector>

using namespace std;

int main(){
    Person one;
    Person two("Smythercraft");
    Person three("Dimwiddy", "Sam");

    cout << "First person: \n\t";
    one.Show();
    cout << "\n\tFormal: ";
    one.FormalShow();

    cout << "\n\nSecond person: \n\t";
    two.Show();
    cout << "\n\tFormal: ";
    two.FormalShow();

    cout << "\n\nSecond person: \n\t";
    three.Show();
    cout << "\n\tFormal: ";
    three.FormalShow();

    return 0;
}