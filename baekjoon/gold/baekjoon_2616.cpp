#include <memory.h>
#include <iostream>

using namespace std;

int N, trainCount;
int passenger[50001];
int dp[50001][3];

int getMaxPassenger(int depth, int idx) {
    if(depth == 3 || idx >= N) return 0;
    
    int& value = dp[idx][depth];
    if(value != -1) return value;

    value = 0;
    if(idx + trainCount - 1 <= N) 
        value = max(getMaxPassenger(depth, idx + 1), 
        getMaxPassenger(depth + 1, idx + trainCount) + passenger[idx + trainCount -1] - passenger[idx - 1]);
    
    cout << depth << ", "<< idx << ": "<<value << endl;
    return value;
}

int main() {
    cin >> N;

    for(int i = 1, cnt; i <= N; i++) {
        cin >> cnt;
        passenger[i] = passenger[i - 1] + cnt;
    }
    
    cin >> trainCount;

    memset(dp, -1, sizeof(dp));

    cout << getMaxPassenger(0, 1) <<"\n";

    for (int i = 0; i < 3; i++)
    {
        for (int  j = 0; j < N; j++)
        {
            cout << dp[j][i] <<" ";
        }
        cout << endl;
        
    }
    

    return 0;
}