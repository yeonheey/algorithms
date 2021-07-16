#include <memory.h>
#include <iostream>

using namespace std;

int arr[101][101];
long long dp[101][101];

int main() {
    int N;
    cin >> N;

    for(int i = 0; i < N; i++) 
        for(int j = 0; j < N; j++)
            cin >> arr[i][j];
    
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;

    for(int r = 0; r < N; r++) 
        for(int c = 0; c < N; c++) {
            if(dp[r][c] == 0 || arr[r][c] == 0) continue;

            if(r + arr[r][c] < N) 
                dp[r + arr[r][c] ][c] += dp[r][c];
            if(c + arr[r][c] < N)
                dp[r][c+ arr[r][c] ] += dp[r][c];
        }          

    cout << dp[N - 1][N - 1] << "\n";

    return 0;
}