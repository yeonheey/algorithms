#include <map>
#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    map<long long, int> card;
    for(int i = 0; i < N; i++) {
        long long number;
        cin >> number;
        
        card[number]++;
    }
    
    long long number;
    int cnt = 0;
    for(map<long long, int>::iterator iter = card.begin(); iter != card.end(); iter++) {
        if(cnt < iter->second || (cnt == iter->second && number > iter->first)) {
            number = iter->first;
            cnt = iter->second;
        } 
    }

    cout << number << "\n";
    
    return 0;
}