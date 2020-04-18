#include <iostream>
#include <string>
#include <stdexcept>


class invalid_arg : public std::logic_error {
private:
    double v1;
    double v2;

public:
    invalid_arg(double a = 0, double b = 0, 
            const std::string &s = "Invalid arguments...") 
        : logic_error(s), v1(a), v2(b) {}
    virtual const char* what(){return logic_error::what();}
    virtual void report(){std::cout << "a = " << v1 << ", b = " << v2 << std::endl;}
};

class bad_hmean : public invalid_arg{
private:
    double v1;
    double v2;

public:
    bad_hmean(double a = 0, double b = 0, 
            const std::string &s = "Invalid arguments...")// = "hmean(a, b): a = -b") 
        : invalid_arg(a, b, s) {}
    const char* what(){return invalid_arg::what();}
    void report(){std::cout << "hmean(a, b): "; invalid_arg::report();};
};

class bad_gmean : public invalid_arg {
public:
    double v1;
    double v2;
    bad_gmean(double a = 0, double b = 0, 
            const std::string &s = "Invalid_argument...") 
        : invalid_arg(a, b, s) {}
    const char* what(){return invalid_arg::what();}
    void report(){std::cout << "gmean(a, b): "; invalid_arg::report();};
};