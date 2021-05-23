#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>

using namespace std;

const int MAXSIZE = 10001;
int n, maxDist;
int last = 0;

vector<pair<int, int>> edges[MAXSIZE];
bool isVisited[MAXSIZE] = {false, };

void dfs(int node, int weight) {
    if(isVisited[node]) return;
    
    isVisited[node] = true;
    if(maxDist < weight) {
        last = node;
        maxDist = weight;
    }
    
    for(pair<int, int> edge: edges[node]) 
        dfs(edge.first, weight + edge.second);
}

int main() {
    scanf("%d", &n);
    maxDist = 0;
    
    for(int i = 1, a, b, c; i < n; i++) {
        scanf("%d %d %d", &a, &b, &c);
        edges[a - 1].push_back({b - 1, c});
        edges[b - 1].push_back({a - 1, c});
    }
    
    dfs(0, 0);
    
    maxDist = 0;
    memset(isVisited, false, sizeof(isVisited));
    
    dfs(last, 0);
    
    printf("%d\n", maxDist);
    
    return 0;
}