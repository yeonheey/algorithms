#include <vector>
#include <queue>

using namespace std;

struct Player {
    int r, c, step;
    Player(int _r, int _c, int _s) {r = _r, c = _c, step = _s;}
};

int dr[4] = {0, 0, 1, -1}; //동서남북
int dc[4] = {1, -1, 0, 0};

int solution(vector<vector<int> > maps)
{
    int answer = -1;
    int n = maps.size(), m = maps[0].size();
    
    queue<Player> q;
    vector<vector<bool>> isVisited(n, vector<bool>(m, false));
    q.push(Player(0, 0, 1));
    isVisited[0][0] = true;
    
    while (!q.empty()) {
        Player player = q.front(); q.pop();
        
        if(player.r == n - 1 && player.c == m - 1) {
            answer = player.step;
            break;
        }
        
        for(int i = 0; i < 4; i ++) {
            int nr = player.r + dr[i];
            int nc = player.c + dc[i];
            
            if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if(isVisited[nr][nc] || maps[nr][nc] == 0) continue;
            
            isVisited[nr][nc] = true;
            q.push(Player(nr, nc, player.step + 1));
        }
    }
    
    return answer;
}