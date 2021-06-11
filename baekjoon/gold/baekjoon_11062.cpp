#include <memory.h>
#include <algorithm>
#include <iostream>

using namespace std;

const int SIZE = 1001;

int T, N;
int cards[SIZE];
int dp[SIZE][SIZE][2]; //left index, right index, turn

void input() {
    memset(dp, -1, sizeof(dp));

    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> cards[i];
}

int check(int l, int r, int turn) {
    int& curSum = dp[l][r][turn];

    if(curSum != -1) return curSum;
    
    if(l >= r) {
        if(turn == 0) curSum = cards[l];
        else curSum = 0;
        
        return curSum;
    }

    if(turn == 0) 
        curSum = max( (check(l + 1, r, 1) + cards[l]), (check(l, r - 1, 1) + cards[r]) );
    else 
        curSum = min( check(l + 1, r, 0) , check(l, r- 1, 0) );

    //cout << turn <<"-"<< l << "," << r << ": "<< curSum << endl;
    return curSum;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;

    while (T-- > 0) {
        input();

        if(N == 1) 
            cout << cards[0] << "\n";
        else
            cout << check(0, N - 1, 0) <<"\n";
    }
    
    return 0;
}