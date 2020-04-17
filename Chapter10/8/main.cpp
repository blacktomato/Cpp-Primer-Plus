// Chapter -10- (p# 561)
#include <iostream>
#include "list.h"

using namespace std;

void showItem (Item *);

int main(){
    cout << "Creating a list with capacity == 0...\n";
    DList list1(0);  // a list with capacity == 0
    list1.addnode(4);

    cout << "Creating a list with capacity == 6...\n";
    DList list2(6);  // a list with capacity == 6

    if (list2.isempty()) cout << "The list is empty now...\n";
    list2.addnode(5);

    cout << "List: ";
    list2.visit(showItem);
    cout << endl << endl;

    list2.addnode(4);
    cout << "List: ";
    list2.visit(showItem);
    cout << endl << endl;

    list2.addnode(1);
    list2.addnode(9);
    list2.addnode(20);
    list2.addnode(3);
    
    cout << "List: ";
    list2.visit(showItem);
    cout << endl << endl;

    list2.addnode(3);

    return 0;
}

void showItem (Item * i){
    cout << i->_value << ' ';
}