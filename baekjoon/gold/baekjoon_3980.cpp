#include <memory.h>
#include <algorithm>
#include <iostream>

using namespace std;

int T;
int player[11][11];
bool isVisited[11];
int maxSum;

void dfs(int cnt, int sum) {
    if(cnt == 11) {
        maxSum = max(maxSum, sum);
        return;
    }

    for(int pos = 0; pos < 11; pos++) {
        if(isVisited[pos] || player[cnt][pos] == 0) continue;

        isVisited[pos] = true;
        dfs(cnt + 1, sum + player[cnt][pos]);
        isVisited[pos] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;

    for(int t = 0; t < T; t++) {
        memset(isVisited, false, sizeof(isVisited));
        maxSum = -1;

        for(int i = 0; i < 11; i++) 
            for(int j = 0; j < 11; j++) 
                cin >> player[i][j];

        for(int pos = 0; pos < 11; pos++)
            if(player[0][pos] != 0) {
                isVisited[pos] = true;
                dfs(1, player[0][pos]);
                isVisited[pos] = false;
            }

        cout << maxSum <<"\n";
    }

    return 0;
}