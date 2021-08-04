#include <iostream>

using namespace std;

const int MOD = 15746;

int dp[1000001][2];

int main() {
    int N;
    cin >> N;

    dp[0][0] = dp[0][1] = dp[1][1] = 0;
    dp[1][0] = dp[2][0] = dp[2][1] = 1;

    for(int i = 3; i <= N; i++) {
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
        dp[i][1] = (dp[i - 2][0] + dp[i - 2][1]) % MOD;
    }

    int result = 0;
    for(int i = 0; i < 2; i++)
        result += dp[N][i];
    
    cout << result % MOD << "\n";

    return 0;
}