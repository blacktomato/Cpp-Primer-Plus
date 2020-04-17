#ifndef CLASSIC_H
#define CLASSIC_H

#include "cd.h"

class Classic : public Cd
{
public:
    Classic(const char *d1, const char *s1, const char *s2, int n, double x);
    Classic(const Classic &c);
    Classic();
    virtual ~Classic(){};
    virtual void Report() const; // reports all CD data
    Classic &operator=(const Classic &d);
private:
    char description[100];
};

#endif