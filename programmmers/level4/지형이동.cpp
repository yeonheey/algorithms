#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Edge {
    int dist, zone1, zone2;
    Edge(int _d, int _z1, int _z2) {dist = _d, zone1 = _z1, zone2 = _z2;}
};

int dir_r[4] = {-1, 1, 0, 0};
int dir_c[4] = {0, 0, -1, 1};

int n;
vector<Edge> edges;
int zones[301][301];
vector<int> parents;
int zoneCnt;

//divide zone that can move without ladder
void getZone(vector<vector<int> >& land, int r, int c, int height) 
{
    zones[r][c] = zoneCnt;
    
    for(int i = 0; i < 4; i++)
        {
            int nr = r + dir_r[i];
            int nc = c + dir_c[i];
            
            if(nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
            
            if(zones[nr][nc] == 0 && abs(land[nr][nc] - land[r][c]) <= height)
                getZone(land, nr, nc, height);
        }
}

//get edges that locate among different zoneNumber
void getNeighborEdge(vector<vector<int> >& land)
{
    for(int r = 0; r < n; r++)
        for(int c = 0; c < n; c++)
            for(int i = 0; i < 4; i++)
            {
                int nr = r + dir_r[i];
                int nc = c + dir_c[i];
                
                if(nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
                if(zones[r][c] == zones[nr][nc]) continue;
                
                edges.push_back( Edge(abs(land[r][c] - land[nr][nc]), zones[r][c], zones[nr][nc]) );
            }
}

//using kruskal algorithm
int getParent(int x) 
{
    if(parents[x] == x) return x;
    return parents[x] = getParent(parents[x]);
}

void Union(int a, int b)
{
    a = getParent(a), b = getParent(b);
    if (b < a)
        parents[a] = b;
    else
        parents[b] = a;
}

bool cmp(const Edge& a, const Edge& b) //for sort algorithm
{
    if(a.dist < b.dist) return true;
    return false;
}

int findMinCost()
{
    int minCost = 0;
    parents.resize(zoneCnt + 1);
    
    sort(edges.begin(), edges.end(), cmp);
    
    for(int i = 1; i <= zoneCnt; i++) parents[i] = i;
    
    for(int i = 0; i < edges.size(); i++)
    {
        if(getParent(edges[i].zone1) != getParent(edges[i].zone2))
        {
            Union(edges[i].zone1, edges[i].zone2);
            minCost += edges[i].dist;
        }
    }
    
    return minCost;
}

int solution(vector<vector<int> > land, int height) {
    n = land.size();
    zoneCnt = 0;
    
    //사다리 없이 이동할 수 있는 지역 나누기
    for(int r = 0; r < n; r++)
        for(int c = 0; c < n; c++)
            if(zones[r][c] == 0) 
            {
                zoneCnt++;
                getZone(land, r, c, height);
            }
    
    //인접한 지역들을 edge
    getNeighborEdge(land);
    
    int cost = findMinCost();
    
    return cost;
}