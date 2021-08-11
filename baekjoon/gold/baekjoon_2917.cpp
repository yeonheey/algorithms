#include <queue>
#include <vector>
#include <memory.h>
#include <algorithm>
#include <iostream>

using namespace std;

struct Info {
    int r, c, minCost, cost;
    Info(int _r, int _c, int _min, int _cost) {r = _r, c = _c, minCost = _min, cost = _cost;}
};

struct Cmp
{
    bool operator()(Info& a, Info& b) {
        if(a.cost < b.cost) return true;

        return false;
    }
};


char map[501][501];
int dist[501][501] = {0, };

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

pair<int, int> start;
pair<int, int> dst;

int main() {
    int N, M;
    cin >> N >> M;

    queue<pair<int,int>> tree;
    memset(dist, -1, sizeof(dist));

    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++) {
            cin >> map[i][j];
            
            if(map[i][j] == 'V')
                start = {i, j};
            else if(map[i][j] == 'J')
                dst = {i, j};
            else if(map[i][j] == '+') {
                tree.push({i, j});
                dist[i][j] = 0;
            }
        }
    
    while(!tree.empty()) {
        int r = tree.front().first;
        int c = tree.front().second;
        tree.pop();

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
            if(dist[nr][nc] != -1) continue;

            dist[nr][nc] = dist[r][c] + 1;
            tree.push({nr, nc});
        }
    }

    priority_queue<Info, vector<Info>, Cmp> pq;
    pq.push(Info(start.first, start.second, dist[start.first][start.second], dist[start.first][start.second]));

    while (!pq.empty())
    {
        Info cur = pq.top();
        pq.pop();

        if(dist[cur.r][cur.c] == -1) continue;
        
        dist[cur.r][cur.c] = -1;

        if(cur.r == dst.first && cur.c == dst.second) {
            cout << cur.minCost << "\n";
            return 0;
        }

        for(int i = 0; i < 4; i++) {
            int nr = cur.r + dr[i];
            int nc = cur.c + dc[i];

            if(nr < 0 || nr >= N || nc < 0 || nc >= M || dist[nr][nc] == -1) continue;

            pq.push(Info(nr, nc, min(cur.minCost, dist[nr][nc]), dist[nr][nc]));
        }
    }
    
    return 0;
}