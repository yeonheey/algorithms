#include <memory.h>
#include <cmath>
#include <iostream>

using namespace std;

const int MAXJEWEL = 13;

int N, M, C;
int jewel[MAXJEWEL + 1];
int dp[11][1 << MAXJEWEL][21]; // 가방번호, 챙긴 보석, 남은 무게

int check(int bagNum, int visitedJewel, int capacity) {
    if(bagNum == M) 
        return 0;
    if(dp[bagNum][visitedJewel][capacity] != 0)
        return dp[bagNum][visitedJewel][capacity];

    for(int i = 0; i < N; i++) {
        if(visitedJewel & (1 << i)) continue;

        if(capacity < jewel[i]) {
            dp[bagNum][visitedJewel][capacity] = 
            max(dp[bagNum][visitedJewel][capacity], check(bagNum + 1, visitedJewel, C));
        }
        else {
            dp[bagNum][visitedJewel][capacity] = 
            max(dp[bagNum][visitedJewel][capacity], check(bagNum, visitedJewel | (1 << i), capacity - jewel[i]) + 1);
        }
    }

    return dp[bagNum][visitedJewel][capacity];
}

int main() {
    cin >> N >> M >> C;

    for(int i = 0; i < N; i++) cin >> jewel[i];

    memset(dp, 0, sizeof(dp));

    cout << check(0, 0, C) << "\n";

    return 0;
}