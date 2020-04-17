#include "stack.h"
#include <iostream>

using std::cout;
using std::endl;

Stack::Stack(){
    pitems = new Item[MAX];
    size = MAX;
    top = 0;
}

Stack::Stack(int n){
    if (n <= 0 || n > MAX) n = MAX;
    pitems = new Item[n];
    size = n;
    top = 0;
}

Stack::Stack(const Stack &st){
    pitems = new Item[st.size];
    size = st.size;
    top = st.top;
    for (int i = 0; i < top; i++){
        pitems[i] = st.pitems[i];
    }
}

Stack::~Stack(){
    delete [] pitems;
}

bool Stack::isempty() const{
    return (top == 0);
}

bool Stack::isfull() const{
    return (top == size);
}

bool Stack::push(const Item &item){
    if(isfull()) return false;
    pitems[top] = item;
    top++;
    return true;
}

bool Stack::pop(Item &item){
    if(isempty()) return false;
    item = pitems[top-1];
    top--;
    return true;
}

Stack & Stack::operator=(const Stack &st){
    if (this == &st) return *this;
    delete [] pitems;
    pitems = new Item[st.size];
    size = st.size;
    top = st.top;
    for (int i = 0; i < top; i++){
        pitems[i] = st.pitems[i];
    }
    return *this;
}

void Stack::show(){
    for(int i = 0; i < top; i++){
        cout << pitems[i] << " ";
    }
    cout << endl;
}