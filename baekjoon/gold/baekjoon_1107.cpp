#include <cmath>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

const int curChannel = 100;

bool broken[10] = {false, };

int main() {
    int number;
    int M;
    cin >> number >> M;

    for(int i = 0, num; i < M; i++) {
        cin >> num;
        broken[num] = true;
    }

    int minCnt = abs(number - 100);

    for(int channel = 0; channel < 1000001; channel++) {
        int cnt = abs(number - curChannel);

        bool possibleClick = true;
        for(char ch: to_string(channel)) 
            if(broken[ch - '0']) {
                possibleClick = false;
                break;
            }
        
        if(possibleClick)
            cnt = min(cnt, (int)to_string(channel).size() + abs(number - channel));
        
        minCnt = min(minCnt, cnt);
    }
    
    cout << minCnt << "\n";

    return 0;
}