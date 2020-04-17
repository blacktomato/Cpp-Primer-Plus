#include <iostream>
#include "stack.h"

using namespace std;

void POP(Stack &, Item &);

int main(){
    Stack s1(7);
    Stack s2(5);

    Item dummy = 0;
    POP(s1, dummy);
    s1.push(3);
    s1.push(423);
    s1.push(89);
    s1.push(743);
    s1.push(121);
    POP(s1, dummy);
    s1.push(89);
    s1.push(124);
    s1.push(34419);
    POP(s1, dummy);

    s2.push(1892);
    s2.push(827);
    s2.push(28214);
    s2.push(3659);

    cout << "s1:\n";
    s1.show();
    cout << "s2:\n";
    s2.show();

    cout << endl;
    cout << "Use copy construstor to generate s3:\n";
    Stack s3(s1);
    s3.show();

    cout << "Use assign operator to generate s4:\n";
    Stack s4 = s2;
    s4.show();

    return 0;
}

void POP(Stack &s, Item &i){
    if(s.pop(i)) cout << "Pop out Item: " << i << endl;
    else cout << "Fail to pop from the stack!" << endl;
}