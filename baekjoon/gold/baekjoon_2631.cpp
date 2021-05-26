#include <iostream>
#include <algorithm>

using namespace std;

int n;
int line[201];
int dp[201];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    
    for(int i = 1; i <= n; i++)
        cin >> line[i];
    
    //가장 길이가 긴 증가하는 부분 수열
    int maxArrSize = 0; 
    for(int i = 1; i <= n; i++) {
        dp[i] = 1;
        
        for(int j = 1; j <= i; j++)
            if(line[j] < line[i] && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
        
        maxArrSize = max(maxArrSize, dp[i]);
    }
    
    cout<< n - maxArrSize <<"\n";
    
    return 0;
}