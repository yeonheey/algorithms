#include <algorithm>
#include <iostream>

using namespace std;

const int SIZE = 1001;
int house[SIZE][3];
int dp[SIZE][3];

int main() {
    int N;
    cin >> N;

    for(int i = 1; i <= N; i++) 
        for(int j = 0; j < 3; j++)
            cin >> house[i][j];

    int value = SIZE * SIZE + 1;
    for(int j = 0; j < 3; j++) { // 첫번째 집 고정
        for(int i = 0; i < 3; i++) {
            if(i == j) dp[1][i] = house[1][j];
            else dp[1][i] = SIZE * SIZE + 1;
        }

        for(int i = 2; i <= N; i++) {
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + house[i][0];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + house[i][1];
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + house[i][2];
        }

        for(int i = 0; i < 3; i++) {
            if (i == j) continue;
            value = min(value, dp[N][i]);
        }
    }

    cout << value << "\n";

    return 0;
}