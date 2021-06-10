#include <cmath>
#include <queue>
#include <memory.h>
#include <iostream>

using namespace std;

int N, L, R;
int world[50][50];
bool isVisited[50][50];

int moveCount = 0;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> L >> R;

    for(int i = 0; i < N; i++) 
        for(int j = 0; j < N; j++) 
            cin >> world[i][j];
    
    bool isMoved = true;

    while(isMoved) {
        moveCount++;

        isMoved = false;
        memset(isVisited, false, sizeof(isVisited));
        
        queue<pair<int, int>> coord; // same boundary coord
        queue<pair<int, int> > q;
        
        //1. 같은 연합 찾기
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++) {
                if(isVisited[i][j]) continue;

                int sum = world[i][j];
                isVisited[i][j] = true;

                coord.push({i, j});
                q.push({i, j});

                while(!q.empty()) {
                    int r = q.front().first;
                    int c = q.front().second;
                    q.pop();

                    for(int k = 0; k < 4; k++) {
                        int nr = r + dr[k];
                        int nc = c + dc[k];

                        if(nr < 0 || nr >= N || nc < 0 || nc >= N || isVisited[nr][nc]) continue;
                        if(abs(world[r][c] - world[nr][nc]) > R || abs(world[r][c] - world[nr][nc]) < L) continue;

                        isVisited[nr][nc] = true;
                        isMoved = true;
                        
                        coord.push({nr, nc});
                        q.push({nr, nc});
                        sum += world[nr][nc];
                    }
                }

                //2. 민족 이동
                int avg = sum / coord.size();
                while(!coord.empty()) {
                    int r = coord.front().first, c = coord.front().second;
                    coord.pop();

                    world[r][c] = avg;
                }
            }
    }

    cout << moveCount - 1 <<"\n";

    return 0;
}