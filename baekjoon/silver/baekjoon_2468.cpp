#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
int area[100][100];
bool visited[100][100];
int maxHeight = 0, minHeight = 999999999;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void getZones(int r, int c, int height) 
{
    for(int i = 0; i < 4; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];
        
        if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
        if(visited[nr][nc] || area[nr][nc] <= height) continue;
        
        visited[nr][nc] = true;
        getZones(nr, nc, height);
    }
}

int main(){
    scanf("%d", &N);
    
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
        {
            scanf("%d", &area[i][j]);
            maxHeight = max(maxHeight, area[i][j]);
            minHeight = min(minHeight, area[i][j]);
        }
    
    int cnt = 1;
    for(int height = minHeight; height < maxHeight; height++)
    {
        memset(visited, false, sizeof(visited));
        
        int tempCnt = 0;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                if(!visited[i][j] && area[i][j] > height) 
                {
                    tempCnt++;
                    visited[i][j] = true;
                    getZones(i, j, height);
                }
        
        cnt = max(cnt, tempCnt);
    }
    
    printf("%d\n", cnt);
    
    return 0;
}