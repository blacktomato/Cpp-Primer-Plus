#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <algorithm>
#include <ctime>

using namespace std;

double get_progarm_time(const clock_t &start){
    return (double)(clock() - start)/ CLOCKS_PER_SEC; 
};

int main(){
    srand(time(NULL));

    int n;
    cout << "Enter a number to specify how many number need sorting: (<= 0 to stop program)\n";
    while(cin >> n && n > 0){
        vector<int> vi0(n);
        for(auto &i:vi0) i = rand();

        vector<int> vi(vi0);
        list<int> li(vi0.begin(), vi0.end());

        //sort vi
        clock_t start = clock();
        sort(vi.begin(), vi.end());
        cout  << "Sorting a " << setw(6) << "vector" << " with " << n << " elements takes: " 
            << setw(6) << setprecision(4) << get_progarm_time(start) << " seconds" << endl;

        //sort li
        start = clock();
        li.sort();
        cout  << "Sorting a " << setw(6) << "list" << " with " << n << " elements takes: " 
            << setw(6) << setprecision(4) << get_progarm_time(start) << " seconds" << endl;


        //sort li through a vector
        li = list<int>(vi0.begin(), vi0.end()); //restore the value
        start = clock();
        vector<int> v_temp(li.begin(), li.end());
        sort(v_temp.begin(), v_temp.end());
        li = list<int>(v_temp.begin(), v_temp.end()); //restore the value
        cout  << "Sorting a " << setw(6) << "list" << " with " << n << " elements through a vector takes: " 
            << setw(6) << setprecision(4) << get_progarm_time(start) << " seconds" << endl;

        cout << "Enter a number to specify how many number need sorting: (<= 0 to stop program)\n";
    }
    cout << "Bye!" << endl;
}