#include <iostream>

using namespace std;

const int MOD = 10007;

int dp[1001][10];

int main() {
    int N;
    cin >> N;

    for(int i = 0; i < 10; i++) dp[1][i] = 1;

    for(int i = 2; i <= N; i++) 
        for(int j = 0; j < 10; j++) 
            for(int k = j; k < 10; k++)
                dp[i][j] =(dp[i][j] + dp[i - 1][k]) % MOD;
        
    int sum = 0;
    for(int i = 0; i < 10; i++)
        sum += dp[N][i];
    
    cout << sum % MOD << "\n";

    return 0;
}