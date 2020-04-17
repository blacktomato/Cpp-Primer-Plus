#ifndef MOVE_H
#define MOVE_H
#include <iostream>

using std::cout;
using std::endl;

class Move
{
    private:
        double x;
        double y;
    public:
        Move(double a = 0, double b = 0){ x = a; y = b;}       // sets x, y to a, b
        void showmove() const{                  // shows current x, y values
            cout << "x = " << x << "\ty = " << y << endl;
        }

        // this function adds x of m to x of invoking object to get new x,
        // adds y of m to y of invoking object to get new y, creates a new
        // move object initialized to new x, y values and returns it
        Move add(const Move & m) const{
            return Move(x+m.x, y+m.y);
        }
        void reset(double a = 0, double b = 0){  // resets x,y to a, b
            x = a;
            y = b;
        }
};

#endif