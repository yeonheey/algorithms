#include <algorithm>
#include <iostream>

using namespace std;

const int MAX = 99999999;

int N;
int weight[16][16];
int dp[16][1 << 16]; //도시 방문 여부를 bitmasking으로

int tsp(int current, int visited) {
    //모든 도시 방문
    if(visited == (1 << N) - 1) {
        //현재 도시에서 출발도시로 갈 수 있는지
        if(weight[current][0] == 0)
            return MAX;
        
        return weight[current][0];
    }

    //이미 방문
    if(dp[current][visited] != 0) 
        return dp[current][visited];

    dp[current][visited] = MAX;

    for(int i = 0; i < N; i++) {
        int next = 1 << i;
        //갈 수 없는 경우 || 이미 방문
        if(weight[current][i] == 0 || (visited & next) > 0) 
            continue;

        dp[current][visited] = min(dp[current][visited], tsp(i, (visited | next)) + weight[current][i]);
    }

    return dp[current][visited];
}

int main() {
    cin >> N;

    for(int i = 0; i < N; i++) 
        for(int j = 0; j < N; j++) 
            cin >> weight[i][j];
    
    //완전탐색 > DP + bitmasking(방문했던 도시들 집합 관리 및 시간초과문제 해결)
    //dp[cur][visited] = min(dp[cur][visited], tsp(next, visited + next) + weight[cur][next])

    int minWeight = tsp(0, 1);
    cout << minWeight <<"\n";

    return 0;
}