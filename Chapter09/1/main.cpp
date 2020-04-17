// Chapter -9- (p# 501)
#include <iostream>
#include "golf.h"

using namespace std;

int main(){
    golf g[5];
    while(setgolf(g[0]) == 0) cout << "Please enter valid name!\n";
    while(setgolf(g[1]) == 0) cout << "Please enter valid name!\n";
    setgolf(g[2], "Alice White", 2);
    setgolf(g[3], "Peter Trump", 1);
    setgolf(g[4], "Bojack Horseman", 1);
    
    handicap(g[4], 2);

    for (auto i:g)
        showgolf(i);

    return 0;
}