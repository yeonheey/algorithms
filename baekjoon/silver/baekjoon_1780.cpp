#include <iostream>

using namespace std;

int N;
int paper[2188][2188];
int cnt[3] = {0, };

void checkPaper(int r, int c, int len) {
    if(r < 0 || r >= N || c < 0 || c >= N) return;

    if(len == 1) {
        cnt[paper[r][c]]++;
        return;
    }

    int digit = paper[r][c];
    for(int i = 0; i < len; i++) 
        for(int j = 0; j < len; j++) {
            if(digit == paper[r + i][c + j]) continue;

            int nextLen = len / 3;

            for(int i = 0; i < 3; i++)
                for(int j = 0; j < 3; j++) 
                    checkPaper(r + i * nextLen, c + j * nextLen, nextLen);

            return;
        }
    
    cnt[paper[r][c]]++;
}

int main() {
    cin >> N;
    for(int r = 0; r < N; r++)
        for(int c = 0; c < N; c++) {
            cin >> paper[r][c];
            paper[r][c]++;
        }
    
    checkPaper(0, 0, N);

    for(int i = 0; i < 3; i++)
        cout << cnt[i] <<"\n";

    return 0;
}