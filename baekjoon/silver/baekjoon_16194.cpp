#include <algorithm>
#include <iostream>

using namespace std;

int price[1001];
int dp[1001];

int main() {
    int N;
    cin >> N;
    for(int i = 1; i <= N; i++) 
        cin >> price[i];
    
    dp[0]= 999999999;
    for(int n = 1; n <= N; n++) {
        dp[n] = price[n];

        for(int i = 0; i <= n; i++) 
            dp[n] = min(dp[n], dp[i] + dp[n - i]);
    }

    cout << dp[N] << "\n";

    return 0;
}