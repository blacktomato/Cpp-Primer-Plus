#ifndef WINEC_H_
#define WINEC_H_

#include <iostream>
#include <string>
#include <utility>
#include <valarray>

using namespace std;

typedef valarray<int> ArrayInt;
typedef pair<ArrayInt, ArrayInt> PairArray;

class Wine{
public:
    Wine(const char *l, int y, const int yr[], const int bot[])
        : _name(l),
          _num_year(y),
          _year_bottle(PairArray(ArrayInt(yr, y), ArrayInt(bot, y))){}
    Wine(const char *l = "", int y = 0)
        : _name(l),
          _num_year(y), 
          _year_bottle(PairArray(ArrayInt(y),ArrayInt(y))){}
    void GetBottles(){
        cout << "Enter " << _name << " data for " << _num_year << " year(s):\n";
        for(int i = 0; i < _num_year; i++){
            cout << "Enter year: ";
            cin >> _year_bottle.first[i];
            cout << "Enter bottles for that year: ";
            cin >> _year_bottle.second[i];
        }
    }
    void Show(){
        cout << "Wine: " << _name << endl;
        cout << "\tYear\tBottles" << endl;
        for(int i = 0; i < _num_year; i++){
            cout << "\t" << _year_bottle.first[i]; 
            cout << "\t" << _year_bottle.second[i] << endl; 
        }
    }
    const string & Label(){return _name;}
    const int sum(){return _year_bottle.second.sum();}
private:
    string _name;
    int _num_year;
    PairArray _year_bottle; 
};


#endif //WINEC_H_
