#ifndef STACK_H
#define STACK_H

#include <iostream>

using namespace std;

struct customer{
    char fullname[35];
    double payment;
};

typedef customer Item;

class Stack{
    public:
        Stack(Item i){
            cout << "Customer -> " << i.fullname << " enter the shop...\n";
            _item = new Item(i);
            _capacity = 1;
            _size = 1;
            _totalpayment = 0;
        }
        ~Stack(){
            if (_capacity > 1) delete [] _item;  
            else delete _item;
        }

        bool isempty() const {return (_size == 0);}
        bool isfull() const { return (_size == _capacity);}

        // Return the last element
        Item top() const {
            if (!isempty()) return _item[_size-1];
            return (Item){"", 0}; //dummy
        }

        double totalpayment() const { return _totalpayment;}

        //Add new customer
        void push(Item i){
            cout << "Customer -> " << i.fullname << " enter the shop...\n";
            if(!isfull()){
                _item[_size] = i;
                _size++;
            }
            else{
                Item * temp = _item; // restore the old address in Pointer temp
                _item = new Item[2*_capacity];
                for (int j = 0; j < _size; j++)
                    _item[j] = temp[j];
                _item[_size] = i;
                _size++;
                
                //return the old memory
                if (_capacity > 1) delete [] temp;  
                else delete temp;

                _capacity *= 2;
            }
        }

        //Remove customer
        void pop(){
            //add the payment of the removed customer to _TotalPayment;
            if(!isempty()){
                cout << "Customer -> " << top().fullname << " left...\n";
                _totalpayment += this->top().payment;
                _size--;
                cout << "The total payment: " << _totalpayment << "\n\n";
            }
            else{
                cout << "No one is in the shop...\n";
                cout << "The total payment: " << _totalpayment << "\n\n";
            }
        }

    private:
        Item *_item;
        unsigned int _capacity;
        unsigned int _size;
        double _totalpayment;
};

#endif