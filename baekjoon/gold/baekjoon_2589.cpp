#include <memory.h>
#include <queue>
#include <iostream>

using namespace std;

int R, C;
char land[50][50];
bool isVisited[50][50];

int dr[4] = {-1, 1, 0 ,0};
int dc[4] = {0, 0, -1, 1};

int findJewelDist(int r, int c) {
    int dist = 0;

    memset(isVisited, false, sizeof(isVisited));
    queue<pair<pair<int, int>, int> > q;

    q.push({{r, c}, 0});
    isVisited[r][c] = true;

    while(!q.empty()) {
        int curR = q.front().first.first;
        int curC = q.front().first.second;
        int cnt = q.front().second;
        q.pop();

        if(dist < cnt) dist = cnt;

        for(int i = 0; i < 4; i++) {
            int nr = curR + dr[i];
            int nc = curC + dc[i];

            if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            if(isVisited[nr][nc] || land[nr][nc] != 'L') continue;

            isVisited[nr][nc] = true;
            q.push({{nr, nc}, cnt + 1});
        }
    }
    
    return dist;
}

int main() {
    cin >> R >> C;

    for(int r = 0; r < R; r++)
        for(int c = 0; c < C; c++)
            cin >> land[r][c];

    int result = 0;    
    for(int r = 0; r < R; r++) 
        for(int c = 0; c < C; c++) {
            if(land[r][c] == 'W') continue;

            int maxDist = findJewelDist(r, c);
            if(result < maxDist) 
                result = maxDist;
        }

    cout << result << "\n";

    return 0;
}