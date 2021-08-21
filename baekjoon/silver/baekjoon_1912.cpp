#include <algorithm>
#include <iostream>

using namespace std;

int arr[100001];
int dp[100001];

int main() {
    int N;
    cin >> N;
   
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
        dp[i] = arr[i];
    }
    
    int maxResult = arr[0];
    for(int i = 1; i < N; i++) {
        dp[i] = max(dp[i], dp[i - 1] + arr[i]);
        
        maxResult = max(maxResult, dp[i]);
    }
        
    cout << maxResult << "\n";
    
    return 0;
}