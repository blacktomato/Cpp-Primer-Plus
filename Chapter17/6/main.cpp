#include <iostream> // not required by most systems
#include <fstream>
#include <iomanip>
#include <cstdlib> // for exit()
#include "emp.h"

using namespace std;

const int MAX = 10; 
enum classkind{Employee, Manager, Fink, Highfink};
const char *file = "employee.dat"; 
inline void eatline() { while (std::cin.get() != '\n') continue; } 

int main() { 
    abstr_emp * e[MAX];
    cout << fixed; // show initial contents
    ifstream fin; // read and write streams
    fin.open(file);
    int n_employee = 0, i = 0;
    if (fin.is_open()) {
        cout << "Here are the current contents of the " << file << " file:\n";
        int classtype;
        char ch;
        while((fin >> classtype).get(ch)){
            switch(classtype){
                case Employee:
                    e[i] = new employee;
                    break;
                case Manager:
                    e[i] = new manager;
                    break;
                case Fink:
                    e[i] = new fink;
                    break;
                case Highfink:
                    e[i] = new highfink;
                    break;
            }
            n_employee++;
            e[i]->GetAll(fin);
            i++;
        }
    }
    fin.close();

    for (int i = 0;  i < n_employee; i++){
        e[i]->ShowAll();
        cout << endl;
    }


    i = n_employee;
    int classtype;
    cout << "Enter the kind of worker you want to add:\n"
            << "0. Employee\t1. Manager\n"
            << "2. Fink\t3.Highfink\n"
            << "-1. quit" << endl;
    while(cin >> classtype && classtype != -1){
        switch(classtype){
            case Employee:
                e[i] = new employee;
                break;
            case Manager:
                e[i] = new manager;
                break;
            case Fink:
                e[i] = new fink;
                break;
            case Highfink:
                e[i] = new highfink;
                break;
            default:
                break;
        }
        e[i]->SetAll();
        n_employee++;
        i++;

        cout << "Enter the kind of worker you want to add:\n"
            << "0. Employee\t1. Manager\n"
            << "2. Fink\t3.Highfink\n"
            << "-1. quit" << endl;
    }

    for (int i = 0;  i < n_employee; i++){
        e[i]->ShowAll();
        cout << endl;
    }

    ofstream fout; // write streams
    fout.open("result.dat");
    if (fout.is_open()) {
        for (i = 0; i < n_employee; i++)
            e[i]->WriteAll(fout);
    }
    fout.close();

    return 0;
}