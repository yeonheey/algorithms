#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int N;
int work[10001];
int dp[10001];
vector<int> edges[10001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; i++) {
        int cnt, pre;

        cin >> work[i] >> cnt;
        for(int j = 0; j < cnt; j++) {
            cin >> pre;
            edges[i].push_back(pre - 1);
        }
    }

    for (int i = 0; i < N; i++) {
        int taken = 0;

        for(int prev: edges[i]) 
            taken = max(taken, dp[prev]);
        
        dp[i] = taken + work[i];
    }

    int result = 0;
    for(int i = 0; i < N; i++) 
        result = max(result, dp[i]);
    
    cout << result << "\n";

    return 0;
}