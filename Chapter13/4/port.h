#ifndef PORT_H
#define PORT_H

#include <iostream>
using namespace std;

class Port
{
public:
    Port(const char *br, const char *st, int b);
    Port(const Port &p); // copy constructor
    virtual ~Port() { delete[] brand; }
    Port &operator=(const Port &p);
    Port &operator+=(int b); // adds b to bottles
    Port &operator-=(int b); // subtracts b from bottles, if available 
    int BottleCount() const { return bottles; }
    virtual void Show() const;
    friend ostream &operator<<(ostream &os, const Port &p);
    
private:
    char *brand;
    char style[20]; // i.e., tawny, ruby, vintage
    int bottles;
};

#endif