// Chapter -11- (p# 624)
#include <iostream>
#include "complex0.h"  // to avoid confusion with complex.h

using namespace std;

complex complex::operator+(complex & c) const{
    return complex(_real + c._real, _imaginary + c._imaginary);
}

complex complex::operator-(complex & c) const{
    return complex(_real - c._real, _imaginary - c._imaginary);
}

complex complex::operator*(complex & c) const{
    return complex( _real * c._real - _imaginary * c._imaginary, 
                    _real * c._imaginary + _imaginary * c._real );
}

complex complex::operator-() const{
    return complex(-_real, -_imaginary);
}

complex complex::operator~() const{
    return complex(_real, -_imaginary);
}

complex complex::operator*(double d) const{
    complex result(_real * d, _imaginary * d);
    return result;
}

ostream & operator<<( ostream & os, const complex & c){
    os << '(' << c._real<< ',' << c._imaginary << "i)"; 
    return os;
}

istream & operator>>( istream & is, complex & c){
    cout << "real: ";
    is >> c._real;
    cout << "imaginary:";
    is >> c._imaginary;
    return is;
}