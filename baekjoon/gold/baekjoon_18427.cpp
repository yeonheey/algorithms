#include <vector>
#include <iostream>

using namespace std;

const int MOD = 10007;

int N, M, H;
vector<int> blocks[51];
int dp[51][1001] = {0, }; // x명이 h를 만들 수 있는 경우의 수

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M >> H;
    cin.ignore(); //\n를 버려준다(맨앞의 한 글자만 무시)
    
    for(int i = 1; i <= N; i++) {
        string line;
        getline(cin, line);
        
        int num = 0;
        for(char ch: line) {
            if(ch == ' ') {
                blocks[i].push_back(num);
                num = 0;
            }
            else
                num = num * 10 + (ch - '0');
        }
        
        if(num != 0)
            blocks[i].push_back(num);
    }
}

int main() {
    input();
    
    for(int i = 0; i <= N; i++) 
        dp[i][0] = 1;
    
    for(int i = 1; i <= N; i++)
        for(int h = 1; h <= H; h++) {
            for(int block : blocks[i]) {
                if(h - block >= 0) {
                    dp[i][h] += dp[i - 1][h - block];
                    dp[i][h] %= MOD;
                }
            }
            dp[i][h] += dp[i - 1][h];
            dp[i][h] %= MOD;
        }
    
    cout << dp[N][H] <<"\n";

    return 0;
}