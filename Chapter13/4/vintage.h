#ifndef VINTAGE_H
#define VINTAGE_H

#include <iostream>
#include "port.h"

using namespace std;

class VintagePort : public Port // style necessarily = "vintage"
{
public:
    VintagePort();
    VintagePort(const char * br, int b, const char * nn, int y);
    VintagePort(const VintagePort & vp);
    ~VintagePort() { delete [] nickname; }
    VintagePort & operator=(const VintagePort & vp);
    virtual void Show() const;
    friend ostream & operator<<(ostream & os, const VintagePort & vp);
private:
    char * nickname; // i.e., "The Noble" or "Old Velvet", etc.
    int year; // vintage year
};

#endif