#ifndef DLIST_H
#define DLIST_H

#include<iostream>

using std::cerr;
using std::cout;

class Item{
    public:
        Item *_previous;
        Item *_next;
        int _value;
        
        Item(Item * p = nullptr, int i = 0, Item * n = nullptr){
            _previous = p;
            _value = i;
            _next = n;
        }
        void link(Item *next_i){ _next = next_i; }
};

class DList{
    public:
        DList(int c){
            _start = _last = nullptr;
            _size = 0;
            _capacity = c;
        }

        ~DList(){
            if (_size != 0){
                Item * ptr = _start;
                Item * next = ptr->_next;
                while(next)
                {
                    delete ptr;
                    ptr = next;
                    next = ptr->_next;
                }
                delete ptr;
            }
        }

        bool isempty(){ return (_size == 0); }
        bool isfull(){ return (_size == _capacity); }

        void addnode(int value){
            cout << "Trying to add new item (" << value <<") to the list...\n";  
            if(!isfull()){
                Item * i = new Item(_last, value);
                if(_size == 0) _start = i;
                else _last->link(i);
                _last = i;
                _size++;
            }
            else cout << "Error: the list is full!\n\n";
        }

        int size(){ return _size; }

        void visit( void (*pf)(Item *) ){
            Item * ptr = _start;
            while(ptr){ 
                pf(ptr);
                ptr = ptr->_next;
            }
        }

    private:
        Item * _start;
        Item * _last;
        int _size;
        int _capacity;
};

#endif
