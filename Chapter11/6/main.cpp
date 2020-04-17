#include <iostream>
#include "stonewt.h"

using namespace std;

int main(){
    Stonewt s[6];
    s[0] = Stonewt(34.0);
    s[1] = Stonewt(11, 2.1);
    s[2] = Stonewt(12, 5.1);
    
    for (int i = 3;  i < 6; i++){
        double temp;
        cout << "Enter the weight of the object_" << i << "_: (lbs)\n";
        cin >> temp;
        s[i] = Stonewt(temp);
    }

    cout << endl;
    for (int i = 0;  i < 6; i++){
        cout << "Object_" << i << "_: ";
        s[i].show_stn();
    }
    
    Stonewt max = s[0];
    int max_i = 0;
    for (int i = 1;  i < 6; i++){
        if( max < s[i]) {
            max = s[i]; 
            max_i = i;
        }
    }

    Stonewt min = s[0];
    int min_i = 0;
    for (int i = 1;  i < 6; i++){
        if( min > s[i]) {
            min = s[i]; 
            min_i = i;
        }
    }

    cout << "\nThe Heavist one is object_" << max_i << "_" << endl;
    cout << "The Lightest one is object_" << min_i << "_" << endl;

    cout << endl;

    Stonewt c(11, 0);
    for (int i = 0;  i < 6; i++){
        if (s[i] >= c) 
            cout << "The object_" << i << " is heavier than 11 stones." << endl;
    }
    return 0;

}