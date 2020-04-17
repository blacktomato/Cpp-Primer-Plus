#include <iostream>
#include <string.h>
#include "port.h"

using namespace std;

Port::Port(const char *br = "none", const char *st = "none", int b = 0){
    brand = new char[strlen(br) + 1]; 
    strcpy(brand, br);
    strcpy(style, st);
    bottles = b;
}

Port::Port(const Port &p){
    brand = new char[strlen(p.brand) + 1]; 
    strcpy(brand, p.brand);
    strcpy(style, p.style);
    bottles = p.bottles;
}

Port & Port::operator=(const Port &p){
    if (this == &p)
        return *this;
    delete [] brand;
    brand = new char[strlen(p.brand) + 1]; 
    strcpy(brand, p.brand);
    strcpy(style, p.style);
    bottles = p.bottles;
    return *this;
}

Port & Port::operator+=(int b){
    bottles += b;
    return *this;
}

Port & Port::operator-=(int b){
    bottles -= b;
    return *this;
}

void Port::Show() const{
    cout << "Brand: " << brand << endl
         << "Kind: " << style << endl
         << "Bottles: " << bottles << endl;
}

ostream &operator<<(ostream &os, const Port &p){
    os << p.brand << ", " << p.style << ", " << p.bottles;
    return os;
}
