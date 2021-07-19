#include <queue>
#include <iostream>

using namespace std;

int R, C;
char field[251][251];
bool isVisited[251][251] = {false, };

int sheep = 0, wolf = 0;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void checkArea(int r, int c) {
    queue<pair<int,int> > q;
    
    q.push({r, c});
    isVisited[r][c] = true;

    int areaSheep = 0, areaWolf = 0;
    while (!q.empty()) {
        int curR = q.front().first;
        int curC = q.front().second;
        q.pop();

        if(field[curR][curC] == 'o') areaSheep++;
        else if(field[curR][curC] == 'v') areaWolf++;

        for(int i = 0; i < 4; i++) {
            int nr = curR + dr[i];
            int nc = curC + dc[i];

            if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            if(isVisited[nr][nc] || field[nr][nc] == '#') continue;
            
            isVisited[nr][nc] = true;
            q.push({nr, nc});
        }
    }

    if(areaSheep == 0 && areaWolf == 0) return;

    if (areaSheep > areaWolf) sheep += areaSheep;
    else wolf += areaWolf;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C;

    for(int r = 0; r < R; r++)
        for(int c = 0; c < C; c++) 
            cin >> field[r][c];

    for(int r = 0; r < R; r++) 
        for(int c = 0; c < C; c++) {
            if(!isVisited[r][c] && field[r][c] != '#') 
                checkArea(r, c);
        }
    
    cout << sheep << " " << wolf << "\n";

    return 0;
}