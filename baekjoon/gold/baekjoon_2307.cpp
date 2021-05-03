#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 999999999;

int N, M;
vector<vector<pair<int, int> > > graph;
int dist[1001];
int prevNode[1001];
bool isFirst = true;

void dijkstra(int node1, int node2) //edge에 연결된 노드
{
    for(int i = 0; i <= N; i++) dist[i] = MAX;
    
    priority_queue<pair<int, int> > pq; //cost, node
    pq.push({0, 1});
    dist[1] = 0;
    
    while(!pq.empty())
    {
        int curNode = pq.top().second;
        int curDist = -pq.top().first;
        pq.pop();
        
        if(dist[curNode] < curDist) continue;
        if(curNode == N) return;
        
        for(int i = 0; i < graph[curNode].size(); i++)
        {
            int nextNode = graph[curNode][i].first;
            int nextDist = curDist + graph[curNode][i].second;
            
            if((nextNode == node1 && curNode == node2) || (nextNode == node2 && curNode == node1))
                continue;
            if(dist[nextNode] <= nextDist) continue;
            
            if(isFirst) prevNode[nextNode] = curNode;
            dist[nextNode] = nextDist;
            pq.push({-nextDist, nextNode});
        }
    }
}

int main()
{
    scanf("%d %d", &N, &M);
    
    graph.resize(N + 1);
    
    for(int i = 0, a, b, c; i < M; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    
    dijkstra(1, N);
    int shortest = dist[N];
    int block = -1;
    
    isFirst = false;
    for(int p = N; p != prevNode[p]; p = prevNode[p])
    {
        int node1 = p, node2 = prevNode[p];
        dijkstra(node1, node2);
        
        if(dist[N] == MAX)
        {
            block = -1;
            break;
        }
        
        block = max(block, dist[N] - shortest);
    }
    
    printf("%d\n", block);
    
    return 0;
}