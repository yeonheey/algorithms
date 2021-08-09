#include <iostream>

using namespace std;

const int MOD = 9901;

int dp[100001][3];

int main() {
    int N;
    cin >> N;

    dp[1][0] = dp[1][1] = dp[1][2] = 1;

    for(int i = 2; i <= N; i++){
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % MOD;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
        dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
    }

    int result = 0;
    for (int i = 0; i < 3; i++)
        result += dp[N][i];

    cout << result % MOD << "\n";

    return 0;
}