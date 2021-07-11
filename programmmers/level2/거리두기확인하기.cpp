#include <memory.h>
#include <cmath>
#include <string>
#include <queue>
#include <vector>

using namespace std;

const int SIZE = 5;

bool isVisited[SIZE][SIZE];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

bool check(int r, int c, vector<string>& place) {
    memset(isVisited, false, sizeof(isVisited));
    queue<pair<pair<int,int>, int> > q;
    
    isVisited[r][c] = true;
    q.push({{r, c}, 0});
    
    while(!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second;
        q.pop();
        
        if(cnt >= 2) continue;
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dr[i];
            int ny = y + dc[i];
            
            if(nx < 0 || nx >= SIZE || ny < 0 || ny >= SIZE || isVisited[nx][ny] || place[nx][ny] == 'X') 
                continue;
            
            if(place[nx][ny] == 'P') return false;
            
            isVisited[nx][ny] = true;
            q.push({{nx, ny}, cnt + 1});
        }
    }
    
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(vector<string> place: places) {
        bool allKeep = true;
        
        for(int r = 0; r < SIZE; r++) {
            for(int c = 0; c < SIZE; c++) {
                if(place[r][c] != 'P') continue;
                
                if(check(r, c, place)) continue;
                
                allKeep = false;
                break;
            }
        }
        
        if(allKeep) answer.push_back(1);
        else        answer.push_back(0);
    }
    
    return answer;
}