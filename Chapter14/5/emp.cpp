#include <iostream>
#include <string>
#include "emp.h"

using namespace std;

//for abstr_emp class
abstr_emp::abstr_emp(){
    fname = "";
    lname = "";
    job = "";
}

abstr_emp::abstr_emp(const string &fn, const string &ln, const string &j){
    fname = fn;
    lname = ln;
    job = j;
}

abstr_emp::~abstr_emp(){} // virtual base class

void abstr_emp::ShowAll() const{
    cout << "First Name: " << fname 
        << "\nLast Name: " << lname
        << "\nJob: " << job << endl;
}

void abstr_emp::SetAll() {
    cout << "First Name: ";
    cin >> fname;
    cout << "Last Name: ";
    cin >> lname;
    cout << "Job: ";
    cin >> job;
}

ostream & operator<<(ostream &os, const abstr_emp &e){
    os << "Name:" << e.fname << " " << e.lname;
    return os;
}

//for employee class
employee::employee():abstr_emp() {}

employee::employee(const string &fn, const string &ln, const string &j)
    :abstr_emp(fn, ln, j) {}

void employee::ShowAll() const{
    abstr_emp::ShowAll();
}

void employee::SetAll() {
    abstr_emp::SetAll();
}

//for manager class
manager::manager(): abstr_emp(){
    inchargeof = 0;
}

manager::manager(const string &fn, const string &ln, const string &j, int ico)
    :abstr_emp(fn, ln, j), inchargeof(ico){}

manager::manager(const abstr_emp &e, int ico)
    :abstr_emp(e), inchargeof(ico){} //default copy construtor of abstr_emp

manager::manager(const manager &m)
    :abstr_emp(m), inchargeof(m.inchargeof){}

void manager::ShowAll() const{
    abstr_emp::ShowAll();
    cout << "In charge of: " << inchargeof << " employee(s)" << endl;
}

void manager::SetAll() {
    abstr_emp::SetAll();
    cout << "In charge of: ";
    cin >> inchargeof;
}

//for fink class
fink::fink(): abstr_emp(), reportsto(""){}

fink::fink(const string &fn, const string &ln, const string &j, const string & rpo)
    : abstr_emp(fn, ln, j), reportsto(rpo) {}

fink::fink(const abstr_emp &e, const string &rpo)
    : abstr_emp(e), reportsto(rpo){}

fink::fink(const fink &e) 
    : abstr_emp(e), reportsto(e.reportsto){}

void fink::ShowAll() const{
    abstr_emp::ShowAll();
    cout << "Report to: " << reportsto << endl;
}

void fink::SetAll(){
    abstr_emp::SetAll();
    cout << "Report to: ";
    cin >> reportsto;
}

//for highfink class
highfink::highfink()
    :abstr_emp(), manager(), fink(){}

highfink::highfink(const string &fn, const string &ln, const string &j, const string & rpo, int ico)
    :abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpo){}

highfink::highfink(const abstr_emp &e, const std::string &rpo, int ico)
    :abstr_emp(e), manager(e, ico), fink(e, rpo){}

highfink::highfink(const fink &f, int ico)
    :abstr_emp(f), manager(f, ico), fink(f){}

highfink::highfink(const manager &m, const std::string &rpo)
    :abstr_emp(m), manager(m), fink(m, rpo){}

highfink::highfink(const highfink &h)
    :abstr_emp(h), manager(h), fink(h){}

void highfink::ShowAll() const{
    abstr_emp::ShowAll();
    cout << "In charge of: " << InChargeOf();
    cout << "\nReport to: " << ReportsTo() << endl;
}

void highfink::SetAll() {
    abstr_emp::SetAll();
    cout << "In charge of: ";
    cin >> InChargeOf();
    cout << "Report to: ";
    cin >> ReportsTo(); 
}