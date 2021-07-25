#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct Edge
{
    int node1, node2, length;
    Edge(int n1, int n2, int l) {node1 = n1, node2 = n2, length = l;}
};

int N, M;
int map[11][11];
bool isVisited[11][11] = {false, };

vector<Edge> bridge;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int root[7];

void divideIsland(int r, int c, int cnt) {
    if(map[r][c] == 0 || isVisited[r][c]) return;
    
    isVisited[r][c] = true;
    map[r][c] = cnt;

    for(int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
        divideIsland(nr, nc, cnt);
    }
}

void findBridge(int r, int c) {
    int number = map[r][c];

    for(int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        int cnt = 0;
        while (true) {
            if(nr < 0 || nr >= N || nc < 0 || nc >= M) break;
            
            if(map[nr][nc] == number) break;
            else if(map[nr][nc] == 0) {
                nr += dr[i];
                nc += dc[i];
                cnt++;
            }
            else if(map[nr][nc] != number) {
                if(cnt < 2) break;
        
                bridge.push_back(Edge(number, map[nr][nc], cnt));
                break;
            }
        }
    }
}

int getParent(int x) {
    if(root[x] == x) return x;

    return ( root[x] = getParent(root[x]) );
}

void Union(int a, int b) {
    a = getParent(a), b = getParent(b);

    if(a < b) root[b] = a;
    else root[a] = b;
}

bool cmp(const Edge& a, const Edge& b) {
    return (a.length < b.length);
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for(int j = 0; j < M; j++) {
            cin >> map[i][j];
            if(map[i][j] == 1) map[i][j] = -1;
        }
    
    // 1. 섬 구분하기
    int islandCount = 0;
    for(int r = 0; r < N; r++)
        for(int c = 0; c < M; c++)
            if(map[r][c] == -1 && !isVisited[r][c])
                divideIsland(r, c, ++islandCount);
    
    // 2. 섬 별로 다리 찾기
    for (int r = 0; r < N; r++) 
        for(int c = 0; c < M; c++)
            if(map[r][c] != 0)
                findBridge(r, c);

    // 3. MST 찾기
    sort(bridge.begin(), bridge.end(), cmp);

    for(int i = 1; i <= islandCount; i++) root[i] = i;

    int totalLength = 0;

    for(Edge edge: bridge) {
        if(getParent(edge.node1) == getParent(edge.node2) ) continue;

        totalLength += edge.length;
        Union(edge.node1, edge.node2);
    }

    if(bridge.empty()) totalLength = -1;

    int checkParent = getParent(1);
    for(int i = 1; i <= islandCount; i++)
        if(checkParent != getParent(i)) {
            totalLength = -1;
            break;
        }

    cout << totalLength << "\n";

    return 0;
}