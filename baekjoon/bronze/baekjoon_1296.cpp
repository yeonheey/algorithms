#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

const int MOD = 100;

int N;
string man, woman;

void check(string name, int& L, int& O, int& V, int& E) {
    for(char ch: name) {
        if(ch == 'L') L++;
        else if(ch == 'O') O++;
        else if(ch == 'V') V++;
        else if(ch == 'E') E++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> man;
    cin >> N;

    int L = 0, O = 0, V = 0, E = 0;
    //check(man, L, O, V, E);
    for(char ch: man) {
        if(ch == 'L') L++;
        else if(ch == 'O') O++;
        else if(ch == 'V') V++;
        else if(ch == 'E') E++;
    }
    
    int maxValue = -1;

    for(int i = 0; i < N; i++) {
        string name;
        cin >> name;

        int l = L, o = O, v = V, e = E;
        for(char ch: name) {
            if(ch == 'L') l++;
            else if(ch == 'O') o++;
            else if(ch == 'V') v++;
            else if(ch == 'E') e++;
        }
        
        int value = ((l + o) * (l + v) * (l + e) * (o + v) * (o + e) * (v + e)) % MOD;

        if(value > maxValue) {
            maxValue = value;
            woman = name;
        }
        else if(value == maxValue) {
            if(name < woman) woman = name;
        }
    }

    cout << woman <<"\n";
    
    return 0;
}