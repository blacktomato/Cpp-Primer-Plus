#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <set>
#include <algorithm> //set_union

using namespace std;


int main(){
    set<string> mat_friend;
    set<string> pat_friend;
    set<string> matnpat_friend;
    ifstream fin;
    ofstream fout;
    ostream_iterator<string, char> out(cout, " ");
    fout.open("./matnpat.dat");
    
    string f;

    fin.open("./Mat.dat");
    while(fin >> f && !fin.eof()){
        mat_friend.insert(f);
    }
    fin.close();

    fin.open("./Pat.dat");
    while(fin >> f && !fin.eof()){
        pat_friend.insert(f);
    }
    fin.close();

    //print out friends
    set_union(mat_friend.begin(), mat_friend.end(), pat_friend.begin(), pat_friend.end(), 
        insert_iterator<set<string>>(matnpat_friend, matnpat_friend.begin()));
    copy(mat_friend.begin(), mat_friend.end(), out);
    cout << endl;
    copy(pat_friend.begin(), pat_friend.end(), out);
    cout << endl;

    copy(matnpat_friend.begin(), matnpat_friend.end(), out);
    cout << endl;
    for(auto i:matnpat_friend){ fout << i << endl;}

    fout.close();
    return 0;
}