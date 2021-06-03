#include <algorithm>
#include <iostream>

using namespace std;

int n, t, p;
int time[16];
int payment[16];
int dp[16] = {0, };

int main() {
    cin >> n;
    
    for(int i = 0; i < n; i++)
        cin >> time[i] >> payment[i];
    
    for(int i = 0; i < n; i++) {
        int nextTime = i + time[i];
        
        if(nextTime > n) continue;
        
        if(dp[nextTime] <dp[i] + payment[i]) {
            dp[nextTime] = dp[i] + payment[i];
            
            for(int j = nextTime; j <= n; j++)
                dp[j] = max(dp[j], dp[nextTime]);
        }
    }
    
    cout << dp[n] << "\n";
    
    return 0;
}