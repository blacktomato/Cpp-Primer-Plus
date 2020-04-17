#ifndef COW_H
#define COW_H

class Cow{
    public:
        Cow();
        Cow(const char * nm, const char * ho, double wt);
        Cow(const Cow & c);
        ~Cow();
        Cow & operator=(const Cow & c);
        void ShowCow() const;
    private:
        char name[20];
        char *hobby;
        double weight;
};

#endif