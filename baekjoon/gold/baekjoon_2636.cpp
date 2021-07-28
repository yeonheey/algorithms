#include <queue>
#include <memory.h>
#include <iostream>

using namespace std;

int R, C;
int cheese[101][101]; //2: 외부, 1: cheese, 0: hole
bool isVisited[101][101];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void checkAir() {
    queue<pair<int,int> > q;
    q.push({0, 0});
    isVisited[0][0] = true;

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr < 0 || nr >= R || nc < 0 || nc >= C || 
            isVisited[nr][nc] || cheese[nr][nc] == 1) continue; 
            
            q.push({nr, nc});
            isVisited[nr][nc] = true;
            cheese[nr][nc] = 2;
        }
    }
}

int main() {
    cin >> R >> C;

    queue<pair<int, int>> loc;
    for(int r = 0; r < R; r++)
        for(int c = 0; c < C; c++) {
            cin >> cheese[r][c];

            if(cheese[r][c] == 1)
                loc.push({r, c});
        }
    
    int time = 0;

    while (true) {
        time++;

        memset(isVisited, false, sizeof(isVisited));
        checkAir();

        queue<pair<int,int> > melt;

        int Size = loc.size();
        for(int s = 0; s < Size; s++) {
            int r = loc.front().first;
            int c = loc.front().second;
            loc.pop();

            bool isMelt = false;
            for(int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr < 0 || nr >= R || nc < 0 || nc >= C || cheese[nr][nc] == 2) {
                    isMelt = true;
                    break;
                }
            }

            if(isMelt)
                melt.push({r, c});
            else
                loc.push({r, c});
        }
        
        if(loc.empty()) {
            cout << time <<"\n";
            cout << Size <<"\n";
            break;
        }

        while (!melt.empty()) {
            cheese[melt.front().first][melt.front().second] = 0;
            melt.pop();
        }   
    }
    
    return 0;
}