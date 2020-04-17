// Chapter -10- (p# 560)
#include <iostream>
#include "stack.h"

using namespace std;

int main(){
    Item i[5] = {
        {"John Wick", 100.23},
        {"Harry Potter", 91.24},
        {"Bruno Mars", 124.17},
        {"Edward Alex", 121.40},
        {"SL Chung", 20.74}
    };

    Stack shop(i[0]);
    shop.pop();

    shop.push(i[1]);
    shop.push(i[2]);
    shop.pop();
    
    shop.push(i[3]);
    shop.pop();

    shop.push(i[4]);
    shop.pop();
    shop.pop();
    
    shop.pop();
    return 0;
}