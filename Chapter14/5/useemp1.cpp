// pe14-5.cpp
// useemp1.cpp -- using the abstr_emp classes
#include <iostream>
using namespace std;
#include "emp.h"
int main(void)
{
    employee em("Trip", "Harris", "Thumper");
    cout << em << endl;
    em.ShowAll();
    cout << endl;

    manager ma("Amorphia", "Spindragon", "Nuancer", 5);
    cout << ma << endl;
    ma.ShowAll();
    cout << endl;

    fink fi("Matt", "Oggs", "Oiler", "Juno Barr");
    cout << fi << endl;
    fi.ShowAll();
    cout << endl;

    highfink hf(ma, "Curly Kew"); // recruitment?
    hf.ShowAll();
    cout << endl;

    cout << "Press a key for next phase:\n";
    cin.get();
    highfink hf2;
    hf2.SetAll();
    cout << endl;
    cout << "Using an abstr_emp * pointer:\n";
    abstr_emp *tri[4] = {&em, &fi, &hf, &hf2};
    for (int i = 0; i < 4; i++){
        tri[i]->ShowAll();
        cout << endl;
    }
    return 0;
}