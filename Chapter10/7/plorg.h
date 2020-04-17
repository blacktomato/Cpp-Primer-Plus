#ifndef PLORG_H
#define PLORG_H

#include <iostream>
#include <string.h>

using namespace std;

class Plorg{
    public:
        Plorg(const char * n = "Plorga", int ci = 50){
            strcpy(_name, n);
            _CI = ci;
        }
        void set_CI(int new_ci){ _CI = new_ci; }
        void report(){
            cout << "name: " << _name << "\t CI: " << _CI << endl; 
        }
    private:
        static const int Len = 19; //p# 551
        char _name[Len]; 
        int _CI;
};

#endif