#include <iostream>

using namespace std;

const int MOD = 1000000000;
int dp[101][10];

int main() {
    int N;
    cin >> N;

    for(int i = 1; i < 10; i++) dp[1][i] = 1;

    for(int n = 2; n <= N; n++)
        for(int i = 0; i < 10; i++) {
            if(i == 0) 
                dp[n][i] = dp[n - 1][i + 1] % MOD;
            else if(i == 9) 
                dp[n][i] = dp[n - 1][i - 1] % MOD;
            else 
                dp[n][i] = (dp[n - 1][i - 1] + dp[n - 1][i + 1]) % MOD;
        }

    int sum = 0;
    for(int i = 0; i < 10; i++)
        sum = (sum + dp[N][i]) % MOD;

    cout << sum << "\n";

    return 0;
}