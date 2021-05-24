#include <iostream>

using namespace std;

const int MOD = 1000000000;

int n;
//n자리, 0~9, 10가지경우 이진수
int dp[101][10][1 << 10];
int answer = 0;

int main() {
    cin >> n;
    
    for(int i = 1; i < 10; i++) //0은 시작숫자가 될 수 없음
        dp[1][i][1 << i] = 1;
    
    int maxBinary = (1 << 10);
    
    for(int i = 2; i <= n; i++) 
        for(int j = 0; j < 10; j++) 
            for(int k = 0; k < maxBinary; k++) {
                if(j >= 0 && j < 9)
                    dp[i][j][k | (1 << j)] = 
                    (dp[i][j][k | (1 << j)] + dp[i - 1][j + 1][k]) % MOD;
                if(j > 0 && j <= 9)
                    dp[i][j][k | (1 << j)] = 
                    (dp[i][j][k | (1 << j)] + dp[i - 1][j - 1][k]) % MOD;
            }
    
    for(int i = 0; i < 10; i++) //0~9를 전체사용한 경우
        answer = (answer + dp[n][i][maxBinary - 1]) % MOD;
    
    cout<<answer<<"\n";
    
    return 0;
}