#include <algorithm>
#include <iostream>

using namespace std;

int C, N;
pair<int,int> city[21]; //cost, count
int dp[1001];

int findMincost(int cnt, int idx) { //customer, city
    int minCost = 100000;

    if(cnt <= 0) return 0;
    if(dp[cnt] > 0) return dp[cnt];

    for(int i = 0; i < idx; i++) {
        int cost = findMincost(cnt - city[i].second, idx) + city[i].first;
        minCost = min(minCost, cost);
    }

    dp[cnt] = minCost;
    return minCost;
}

int main() {
    cin >> C >> N;

    for(int i = 0; i < N; i++) 
        cin >> city[i].first >> city[i].second;

    cout << findMincost(C, N) << "\n";

    return 0;
}