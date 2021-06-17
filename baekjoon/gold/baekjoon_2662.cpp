#include <vector>
#include <memory.h>
#include <algorithm>
#include <iostream>

using namespace std;

int N, M;
int cost[21][301];
int dp[22][301];
int cache[22][301];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for(int i = 1, c; i <= N; i++) {
        cin >> c;
        for(int j = 1; j <= M; j++) cin >> cost[j][c];
    }
    
    for(int i = 1; i <= M; i++) 
        for(int money = 1; money <= N; money++) 
            for(int j = 0; j <= money; j++) {
                int value = dp[i - 1][money - j] + cost[i][j];

                if(value > dp[i][money]) {
                    dp[i][money] = value;
                    cache[i][money] = j;
                }
            }

    cout << dp[M][N] <<"\n";
    
    vector<int> ans; 
    for(int i = M, cost = N; i > 0; i--) {
        int now_invest = cache[i][cost];
	    ans.push_back(now_invest);

	    cost -= now_invest;
    }

    reverse(ans.begin(), ans.end());
    for (auto it : ans) cout << it << ' ';

    return 0; 
}