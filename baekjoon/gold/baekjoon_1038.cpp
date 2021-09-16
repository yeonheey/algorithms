#include <string>
#include <iostream>

using namespace std;

int N; 
long long dp[1000001];

int main() {
    cin >> N;

    for(int i = 0; i < 10; i++) dp[i] = i;

    int cnt = 10;
    for(int i = 1; i <= N; i++) 
        for(int j = 0; j < (dp[i] % 10); j++) 
            dp[cnt++] = dp[i] * 10 + j;

    if(N > 1022) cout << "-1\n";
    else cout << dp[N] << "\n";

    return 0;
}