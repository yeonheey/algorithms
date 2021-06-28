#include <iostream>

using namespace std;

int N, K;
int value[101];
int dp[100001];// 0~K원

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    for(int i = 1; i <= N; i++) 
        cin >> value[i];
    
    dp[0] = 1;
    for(int i = 1; i <= N; i++)
        for(int j = value[i]; j <= K; j++) 
            dp[j] = dp[j] + dp[j - value[i]];

    cout << dp[K] <<"\n";

    return 0;
}