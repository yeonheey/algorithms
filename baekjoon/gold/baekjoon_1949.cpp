#include <vector>
#include <memory.h>
#include <iostream>

using namespace std;

int N;
int people[10001];
vector<int> road[10001];

int dp[10001][2]; //node, state

int checkBest(int cur, int pre, bool stat) {
    int& value = dp[cur][stat];

    if(value != -1) return value;

    int result = 0;
    
    if(true == stat) {
        for(int next: road[cur]) {
            if(next == pre) continue;

            result += checkBest(next, cur, 0);
        }

        return (value = people[cur] + result);
    }

    if(false == stat) {
        for(int next: road[cur]) {
            if(next == pre) continue;
            
            int result1 = checkBest(next, cur, 0);
            int result2 = checkBest(next, cur, 1);

            result += max(result1, result2);
        }
        return (value = result);
    }

    return -1;
}

int main() {
    cin >> N;

    memset(dp, -1, sizeof(dp));

    for(int i = 1; i <= N; i++) cin >> people[i];

    for(int i = 1; i < N; i++) {
        int a, b;
        cin >> a >> b;

        road[a].push_back(b);
        road[b].push_back(a);
    }

    int result = max(checkBest(1, 0, 0), checkBest(1, 0, 1));

    cout << result << "\n";

    return 0;
}