#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

int alphaDigit[26] = {0, };

int main() {
    int N;
    cin >> N;

    // input
    for(int i = 0; i < N; i++) {
        string str; cin >> str;

        for(int j = 0; j < str.size(); j++) 
            alphaDigit[str[j] - 'A'] += pow(10, str.size() - 1 - j);
    }

    sort(alphaDigit, alphaDigit + 26, greater<int>());

    int sum = 0, digit = 9;
    for(int i = 0; i < 26; i++) {
        if(alphaDigit[i] == 0) continue;

        sum += alphaDigit[i] * (digit--);
    }
    
    cout << sum << "\n";

    return 0;
}