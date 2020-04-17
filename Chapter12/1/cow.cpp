#include <iostream>
#include <string.h>
#include "cow.h"

using std::cout;
using std::endl;

Cow::Cow(){
    name[0] = '\0';
    hobby = nullptr;
    weight = 0.0;
}

Cow::Cow(const char * nm, const char * ho, double wt){
   strcpy(name, nm);
   hobby = new char[strlen(ho) + 1];
   strcpy(hobby, ho);
   weight = wt;
}

Cow::Cow(const Cow & c){
   strcpy(name, c.name);
   hobby = new char[strlen(c.hobby) + 1];
   strcpy(hobby, c.hobby);
   weight = c.weight;
}

Cow::~Cow(){
    delete [] hobby;
}

Cow & Cow::operator=(const Cow & c){
    if (this == &c)
        return *this;
    delete [] hobby;

    strcpy(name, c.name);
    hobby = new char[strlen(c.hobby) + 1];
    strcpy(hobby, c.hobby);
    weight = c.weight;
    return *this;
}
void Cow::ShowCow() const{
    cout << "name: " << name
         << "\thobby: " << hobby
         << "\tweight: " << weight << " kg"<< endl;
}
