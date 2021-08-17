#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> edge[1000001];
int dp[1000001][2]; // not, early -> min
bool isVisited[1000001] = {false, };


void check(int cur) {
    isVisited[cur] = true;
    dp[cur][0] = 0;
    dp[cur][1] = 1;

    for(int i = 0; i < edge[cur].size(); i++) {
        int next = edge[cur][i];

        if(isVisited[next]) continue;

        check(next);

        dp[cur][0] += dp[next][1];
        dp[cur][1] += min(dp[next][0], dp[next][1]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    int root = 1;
    check(root);
    
    cout << min(dp[root][0], dp[root][1]) << "\n";

    return 0;
}