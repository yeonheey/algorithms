#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 99999999;

int start, dst;
vector<int> edge[101];
bool isVisited[101] = {false, };

int main() {
    int n, m;

    scanf("%d", &n);
    scanf("%d %d", &start, &dst);
    scanf("%d", &m);
    
    for(int i = 0, a, b; i < m; i++) {
        scanf("%d %d", &a, &b);
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    
    queue<pair<int, int>> q;
    q.push({start, 0});
    
    int answer = -1;
    
    while(!q.empty()) {
        int node = q.front().first;
        int d = q.front().second; q.pop();
        
        if(node == dst) {
            answer = d; break;
        }
        
        for(int i = 0; i < edge[node].size(); i++) {
            int next = edge[node][i];
            int nextDist = d + 1;
            
            if(isVisited[next]) continue;
            
            isVisited[next] = true;
            q.push({next, nextDist});
        }
    }
    
    printf("%d\n", answer);
    
    return 0;
}