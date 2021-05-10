#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int N, M;
int f1, f2; //factory location
int maxWeight = 0;

vector<vector<pair<int, int>> > edges;

bool bfs(int cost)
{
    vector<bool> isVisted(N + 1, false);
    queue<int> q;
    q.push(f1);
    isVisted[f1] = true;
    
    while(!q.empty())
    {
        int curNode = q.front(); q.pop();
        
        if(curNode == f2) return true;
        
        for(int i = 0; i < edges[curNode].size(); i++)
        {
            int nextNode = edges[curNode][i].first;
            int nextCost = edges[curNode][i].second;
            
            if(!isVisted[nextNode] && nextCost >= cost)
            {
                isVisted[nextNode] = true;
                q.push(nextNode);
            }
        }
    }
    
    return false;
}

int main() {
    scanf("%d %d", &N, &M);
    edges.resize(N + 1);
    
    for(int i = 0, a, b, c; i < M; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        
        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
        maxWeight = max(maxWeight, c);
    }
    
    scanf("%d %d", &f1, &f2);
    
    int left = 0, right = maxWeight;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        
        if(bfs(mid))
            left = mid + 1;
        else
            right = mid - 1;
    }
    
    printf("%d\n", right);
    
    return 0;
}
