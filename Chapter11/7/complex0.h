#ifndef COMPLEX0_H_H
#define COMPLEX0_H_H

#include <iostream>

using std::cout;
using std::ostream;
using std::istream;

class complex{
    public:
        complex(double r = 0.0, double i = 0.0){ _real = r; _imaginary = i;}
        complex operator+(complex &) const;
        complex operator-(complex &) const;
        complex operator*(complex &) const;
        complex operator*(double) const;
        //unary operator
        complex operator-() const;
        complex operator~() const; //conjugation

        friend complex operator*(double d, complex &c){ return (c * d); }
        friend ostream & operator<<( ostream &, const complex &); // only the member function can denote const
        friend istream & operator>>( istream &, complex &);
    private:
        double _real;
        double _imaginary;
};


#endif