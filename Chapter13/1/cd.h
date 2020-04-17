#ifndef CD_H
#define CD_H

// base class
class Cd
{ // represents a CD disk
public:
    Cd(const char *s1, const char *s2, int n, double x);
    Cd(const Cd &d);
    Cd();
    virtual ~Cd(){};
    virtual void Report() const; // reports all CD data
    Cd &operator=(const Cd &d);
private:
    char performers[50];
    char label[20];
    int selections;  // number of selections
    double playtime; // playing time in minutes
};


#endif