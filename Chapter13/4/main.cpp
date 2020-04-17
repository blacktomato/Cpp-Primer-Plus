#include <iostream>
#include "port.h"
#include "vintage.h"

using namespace std;

int main(){
    const int PORT = 4;
    Port * p[PORT];
    Port p1("A", "tawny", 30);
    Port p2("B", "ruby", 47);
    VintagePort p3("C", 17, "The Noble", 1992);
    VintagePort p4("D", 13, "Old Velvet", 2000);

    p[0] = &p1;
    p[1] = &p2;
    p[2] = &p3;
    p[3] = &p4;

    *p[2] -= 4;
    *p[3] += 4;

    for (int i = 0; i < PORT; i++){
        cout << "Port_" << i+1 << endl;
        p[i]->Show();
        cout << endl;
    }

    for (int i = 0; i < PORT; i++)
        cout << "Port_" << i+1 << ": " << *p[i] << endl;

    cout << "\nUse default constructer and assign operator:\n";
    VintagePort p5;
    p5 = p4;
    cout << "Port_5" << endl;
    p5.Show();
    cout << "\nPort_5: " << p5 << endl;

    return 0;
}