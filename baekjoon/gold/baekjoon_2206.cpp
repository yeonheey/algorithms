#include <queue>
#include <iostream>

using namespace std;

struct Coord {
    int x, y, block;
    Coord(int _x, int _y, int _b) {x = _x, y = _y, block = _b;}
};

const int MAX = 1001;

int n, m;
char arr[MAX][MAX];
int isVisited[MAX][MAX][2];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) 
        cin >> arr[i];

    queue<Coord> q;
    q.push(Coord(0, 0, 0));
    int shortest = -1;
    
    while(!q.empty()) {
        Coord cur = q.front(); q.pop();
        
        if(cur.x == n - 1 && cur.y == m - 1) {
            shortest = isVisited[n - 1][m - 1][cur.block] + 1;
            break;
        }
        
        for(int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            
            if(arr[nx][ny] == '0' && isVisited[nx][ny][cur.block] == 0) { //갈수있고, 방문x
                isVisited[nx][ny][cur.block] = isVisited[cur.x][cur.y][cur.block] + 1;
                q.push(Coord(nx, ny, cur.block));
            }
            else if(arr[nx][ny] == '1' && cur.block == 0) { //벽이고 한번 돌파가능
                isVisited[nx][ny][cur.block + 1] = isVisited[cur.x][cur.y][cur.block] + 1;
                q.push(Coord(nx, ny, cur.block + 1));
            }
        }
    }
    
    cout << shortest <<"\n";
    
    return 0;
}