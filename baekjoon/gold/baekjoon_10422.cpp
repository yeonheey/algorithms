#include <iostream>

using namespace std;

const int SIZE = 5000;
const int MOD = 1000000007;

int T, L;
long long dp[SIZE + 1] = {0, };

int main() {
    cin >> T;
    
    dp[0] = 1;
    for (int i = 0; i <= SIZE; i += 2) {
        for(int j = 0; j <= i - 2; j += 2) {
            dp[i] += dp[j] * dp[i - 2 - j];
            dp[i] %= MOD;
        }
    }
    
    while(T-- > 0) {
        cin >> L;
        
        cout << dp[L] <<"\n";
    }
    
    return 0;
}