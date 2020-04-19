#ifndef STORE_H_
#define STORE_H_

#include <fstream>
#include <string>

using namespace std;

class Store{
public:
    Store(ofstream &f): fout(f){}
    void operator()(const string &s){
        size_t len = s.size();
        fout.write((char*)&len, sizeof(size_t) );
        fout.write(s.data(), len );
    };
private:
    ofstream &fout;
};

#endif