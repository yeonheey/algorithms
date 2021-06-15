#include <iostream>

using namespace std;

const int SIZE = 501;

int N;
int matrix[SIZE][2]; // r, c
int dp[SIZE][SIZE];

int main() {
    cin >> N;

    for(int i = 1; i <= N; i++) 
        cin >> matrix[i][0] >> matrix[i][1];
    
    for(int i = 1; i < N; i++)
        dp[i][i + 1] = matrix[i][0] * matrix[i][1] * matrix[i + 1][1];
    
    for(int gap = 2; gap <= N; gap++) //i-th행렬에서 j-th행렬까지의 거리
        for(int i = 1; i <= N - gap; i++) {
            int j = i + gap;

            for(int k = i; k < j; k++) { //묶는 위치
                int count = dp[i][k] + dp[k + 1][j] + matrix[i][0] * matrix[k][1] * matrix[j][1];
                
                if(dp[i][j] == 0 || dp[i][j] > count)
                    dp[i][j] = count;
            }
        }

    cout << dp[1][N] << "\n";

    return 0;
}