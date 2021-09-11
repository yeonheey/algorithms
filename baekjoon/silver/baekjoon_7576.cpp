#include <queue>
#include <iostream>

using namespace std;

int R, C;
int tomato[1001][1001];
bool isVisited[1001][1001];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int main() {
    cin >> C >> R;

    queue<pair<int,int>> q;

    for(int r = 0; r < R; r++)
        for(int c = 0; c < C; c++) {
            cin >> tomato[r][c];

            if(tomato[r][c] == 1) 
                q.push({r, c});
        }
    
    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        isVisited[r][c] = true;

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            if(!isVisited[nr][nc] && tomato[nr][nc] == 0) {
                q.push({nr, nc});
                tomato[nr][nc] = tomato[r][c] + 1;
            }
        }
    }

    int maxDay = -1;
    for(int r = 0; r < R; r++)
        for(int c = 0; c < C; c++) {
            if(tomato[r][c] == 0) {
                cout << "-1\n";
                return 0;
            }

            if (maxDay < tomato[r][c]) 
                maxDay = tomato[r][c];
        }
    
    cout << maxDay - 1 << "\n";

    return 0;
}