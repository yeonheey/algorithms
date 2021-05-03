#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge
{
    int n1, n2, w; //node, node, weight
    Edge(int _n1, int _n2, int _w)
    {
        n1 = _n1, n2 = _n2, w = _w;
    }
};

int V, E;
int parent[10001];
vector<Edge> graph;

int Find(int node)
{
    if(node == parent[node]) return node;
    
    return parent[node] = Find(parent[node]);
}

void Union(int a, int b)
{
    a = Find(a), b = Find(b);
    if(a == b) return;
    
    parent[b] = a;
}

bool SameParent(int a, int b)
{
    a = Find(a), b = Find(b);
    if(a == b) return true;
    
    return false;
}

bool cmp(const Edge e1, const Edge e2)
{
    return (e1.w < e2.w);
}

int main()
{
    scanf("%d %d", &V, &E);
    
    for(int i = 0, a, b, c; i < E; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        graph.push_back(Edge(a, b, c));
    }
    
    for(int i = 1; i <= V; i++)
        parent[i] = i;
    
    sort(graph.begin(), graph.end(), cmp);
    
    int minCost = 0;
    for(int i = 0; i < E; i++)
    {
        if(SameParent(graph[i].n1, graph[i].n2)) continue;
        
        Union(graph[i].n1, graph[i].n2);
        minCost += graph[i].w;
    }
    
    printf("%d\n", minCost);
    
    return 0;
}