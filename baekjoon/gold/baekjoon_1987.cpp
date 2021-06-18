#include <cmath>
#include <iostream>

using namespace std;

int R, C;
char board[21][21];
bool isVisited[26];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int maxCount = 0;

void dfs(int r, int c, int cnt) {
    maxCount = max(maxCount, cnt);

    for(int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
        if(isVisited[board[nr][nc] - 'A']) continue;

        isVisited[board[nr][nc] - 'A'] = true;
        dfs(nr, nc, cnt + 1);
        isVisited[board[nr][nc] - 'A'] = false;
    }
}


int main() {
    cin >> R >> C;

    string str;
    for(int i = 0; i < R; i++) 
        for(int j = 0; j < C; j++)
            cin >> board[i][j];

    isVisited[board[0][0] - 'A'] = true;
    dfs(0, 0, 1);

    cout << maxCount << "\n";

    return 0;
}