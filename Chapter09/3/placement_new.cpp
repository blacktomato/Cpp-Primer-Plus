// Chapter -9- (p# 502)
#include <iostream>
#include <string.h>
#include <string>
#include <new> //for placement new

using namespace std;

struct chaff
{
    char dross[20];
    int slag;
};

const int BUF = 32;
chaff buffer[BUF]; //chunk of memory


void show_chaff(chaff * c);
void set_chaff(chaff * c, string s, int i);


int main(){
    chaff *c1, *c2;
    c1 = new chaff;             //heap
    c2 = new (buffer) chaff;    //use buffer array
    set_chaff(c1, "aaaaaaaaaaaa", 1);
    set_chaff(c2, "bbbbbbbbbbbb", 2);

    cout << "Calling new and placement new:\n";
    cout << "Memory addresses:\n" << "  heap: " << c1 
                                  << "\tstatic: " << (void *)buffer << endl;
    cout << "Memory Contents:\n";
    cout << "heap__\t\t";
    show_chaff(c1);
    cout << "static__\t";
    show_chaff(c2);

    cout << "\nCalling new and placement new a second time:\n";
    chaff *c3, *c4;
    c3 = new chaff;             //find new address
    c4 = new (buffer) chaff;    //overwirte the old data;
    set_chaff(c3, "cccccccccccc", 3);
    set_chaff(c4, "dddddddddddd", 4);
    
    cout << "Memory Contents:\n";
    cout << "heap__\t\t";
    show_chaff(c3);
    cout << "static__\t";
    show_chaff(c4);

    cout << "\nCalling new and placement new a third time:\n";
    delete c1;
    c1 = new chaff;                           //find new address
    c2 = new (buffer+sizeof(chaff)) chaff;    //use the buffer
    set_chaff(c1, "eeeeeeeeeeee", 5);
    set_chaff(c2, "ffffffffffff", 6);
    
    cout << "Memory Contents:\n";
    cout << "heap__\t\t";
    show_chaff(c1);
    cout << "static__\t";
    show_chaff(c2);

    delete c1;
    delete c3;
    return 0;
}

void show_chaff(chaff * c){
    cout << "chaff: ";
    for (int i = 0; i < 20; i++)
        cout << c->dross[i];
    cout << "\tslag: " << c->slag;
    cout << "\tat " << c << endl;
}


void set_chaff(chaff * c, string s, int i){
    //empty original content
    for (int i = 0; i < 20; i++)
        c->dross[i] = ' ';
    strcpy(c->dross, s.c_str());
    c->slag = i;
}

