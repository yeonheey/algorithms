#include <memory.h>
#include <queue>
#include <iostream>

using namespace std;

int Cols, Rows, K;
int ground[51][51];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int check() {
    int cnt = 0;

    for(int r = 0; r < Rows; r++) 
        for(int c = 0; c < Cols; c++) {
            if(ground[r][c] != 1) continue;

            cnt++;
            
            queue<pair<int,int>> q;
            q.push({r, c});
            ground[r][c] = 2;

            while (!q.empty()) {
                int curR = q.front().first;
                int curC = q.front().second;
                q.pop();

                for(int i = 0; i < 4; i++) {
                    int nr = curR + dr[i];
                    int nc = curC + dc[i];

                    if(nr < 0 || nr >= Rows || nc < 0 || nc >= Cols) continue;
                    if(ground[nr][nc] != 1) continue;

                    q.push({nr, nc});
                    ground[nr][nc] = 2;
                }
            }
        }
    
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        memset(ground, 0, sizeof(ground));

        cin >> Cols >> Rows >> K;
        for(int k = 0, r, c; k < K; k++) {
            cin >> c >> r;
            ground[r][c] = 1;
        }

        cout << check() << "\n";
    }
    
    return 0;
}