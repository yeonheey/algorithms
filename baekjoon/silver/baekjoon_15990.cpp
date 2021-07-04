#include <iostream>

using namespace std;

const int MAXSIZE = 100001;
const int MOD = 1000000009;

long long dp[MAXSIZE][4];

int main() {
    int T, N;
    cin >> T;

    dp[1][1] = dp[2][2] = 1;
    dp[3][1] = dp[3][2] = dp[3][3] = 1;

    for(int i = 4; i < MAXSIZE; i++) {
        dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % MOD;
        dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % MOD;
        dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % MOD;
    }
    
    while (T-- > 0) {
        cin >> N;

        int sum = (dp[N][1] + dp[N][2] + dp[N][3]) % MOD;
        cout << sum << "\n";
    }

    return 0;
}