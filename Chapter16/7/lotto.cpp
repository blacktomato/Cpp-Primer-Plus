#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <algorithm> //random_shuffle()

using namespace std;

vector<int> lotto(const int &range = 51, const int &n = 6);

int main(){
    srand(time(NULL));

    vector<int> winner = lotto(51, 6);
    cout << "The winner will be:\n";
    for ( const auto & i:winner ) cout << i << " ";
    cout << endl;

    winner = lotto(60, 10);
    cout << "\nTry again:\n";
    cout << "The winner will be:\n";
    for ( const auto & i:winner ) cout << i << " ";
    cout << endl;

    return 0;
}

vector<int> lotto(const int &range, const int &n){
    vector<int> base(range);
    for(int i = 0; i < range; i++) base[i] = i+1;
    random_shuffle(base.begin(), base.end());
    
    vector<int> winner(base.begin(), base.begin()+n);
    sort(winner.begin(), winner.end());
    return winner;
}