// Chapter -10- (p# 560)
#include <iostream>
#include "move.h"

using namespace std;

int main(){
    Move m1(3.75, 6.38);
    Move m2(29.23, 8.98);
    cout << "m1: "; 
    m1.showmove();
    cout << "m2: "; 
    m2.showmove();

    Move m3 = m1.add(m2);
    cout << "m3(m1+m2): "; 
    m3.showmove();
    
    m2.reset();
    cout << "m2(reset): "; 
    m2.showmove();

    return 0;
}