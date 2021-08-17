#include <vector>
#include <queue>
#include <iostream>

using namespace std;

const int SIZE = 9;

int N, M;
int board[SIZE][SIZE];
int temp[SIZE][SIZE];

vector<pair<int,int>> virus;
int safeArea = 0;

int dr[4] {-1, 1, 0, 0};
int dc[4] {0, 0, -1, 1};

void spread() {
    for(int r = 0; r < N; r++)
        for(int c = 0; c < M; c++)
            temp[r][c] = board[r][c];
    
    queue<pair<int,int>> q;
    for(int i = 0; i < virus.size(); i++) q.push(virus[i]);

    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
            if(temp[nr][nc] == 0) {
                temp[nr][nc] = 2;
                q.push({nr, nc});
            }
        }
    }

    // check safe area
    int area = 0;
    for(int r = 0; r < N; r++) 
        for(int c = 0; c < M; c++)
            if(temp[r][c] == 0) 
                area++;

    if(area > safeArea) safeArea = area;
}

void makeWallAndCheck(int cnt) {
    if(cnt == 3) {
        spread();
        return;
    }

    for(int r = 0; r < N; r++)
        for(int c = 0; c < M; c++) 
            if(board[r][c] == 0) {
                board[r][c] = 1;
                makeWallAndCheck(cnt + 1);
                board[r][c] = 0;
            }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++) {
            cin >> board[i][j];

            if(board[i][j] == 2)
                virus.push_back({i, j});
        }

    makeWallAndCheck(0);

    cout << safeArea << "\n";

    return 0;
}