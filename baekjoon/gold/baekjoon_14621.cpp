#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

const int SIZE = 1001;

struct Edge
{
    int u, v, dist;
    Edge(int _u, int _v, int _d) {u = _u, v = _v, dist = _d;}
};


vector<Edge> edges;
vector<char> gender(SIZE);

int root[SIZE];

int getParent(int x) {
    if(root[x] == x) return x;

    return ( root[x] = getParent(root[x]) );
}

void Union(int x, int y) {
    x = getParent(x), y = getParent(y);

    if(x < y) root[y] = x;
    else root[x] = y;
}

bool cmp(const Edge& a, const Edge& b) {
    return (a.dist < b.dist);
}

void printDistance(int N, int minDist) {
    for(int i = 2; i <= N; i++) {
        if(getParent(root[i]) == getParent(1)) continue;
        
        cout << "-1\n";
        return;
    }

    cout << minDist <<"\n";
}

void input(int N, int M) {
    for(int i = 1; i <= N; i++)
        cin >> gender[i];
    
    for(int i = 0; i < M; i++) {
        int u, v, d;
        cin >> u >> v >> d;

        edges.push_back(Edge(u, v, d));
    }

    for(int i = 1; i <= N; i++) root[i] = i;
}

int main() {
    int N, M;
    cin >> N >> M;

    input(N, M);
    
    //MST
    sort(edges.begin(), edges.end(), cmp);

    int minDist = 0;
    for(int i = 0; i < M; i++) {
        int node1 = edges[i].u, node2 = edges[i].v;

        if(gender[node1] == gender[node2]) continue;
        if(getParent(edges[i].u) == getParent(edges[i].v) ) continue;
        
        minDist += edges[i].dist;
        Union(node1, node2);
    }
    
    printDistance(N, minDist);

    return 0;
}