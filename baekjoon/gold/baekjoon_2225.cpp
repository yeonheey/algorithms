#include <iostream>

using namespace std;

const int MOD = 1000000000;

long long dp[201][201];

int main() {
    int N, K;
    cin >> N >> K;

    for(int i = 0; i <= N; i++)
        dp[1][i] = 1;

    
    for(int k = 1; k <= K; k++) {
        for(int n = 1; n <= N; n++) {
            for(int i = 0; i <= n; i++)
                dp[k][n] += (dp[k - 1][n - i] % MOD);
        }
    }

    cout << dp[K][N] << "\n";

    return 0;
}