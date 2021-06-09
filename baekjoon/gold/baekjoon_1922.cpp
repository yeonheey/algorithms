#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct Edge {
    int node1, node2, weight;

    Edge(int _node1, int _node2, int _weight) {
        node1 = _node1;
        node2 = _node2;
        weight = _weight;
    }
};

const int MAXSIZE = 1001;
int root[MAXSIZE];
int N,M, sum = 0;
vector<Edge> edges;

bool cmp(Edge& e1, Edge& e2) {
    return (e1.weight < e2.weight);
}

int GetParent(int node) {
    if (root[node] == node) return node;
    return (root[node] = GetParent(root[node]));
}

void Union(int node1, int node2) {
    node1 = GetParent(node1);
    node2 = GetParent(node2);

    if(node1 < node2) 
        root[node2] = node1;
    else 
        root[node1] = node2;

}

bool Find(int node1, int node2) {
    node1 = GetParent(node1);
    node2 = GetParent(node2);

    if(node1 == node2) 
        return true;
    else 
        return false;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b>> c;

        edges.push_back(Edge(a, b, c));
    }
    

    sort(edges.begin(), edges.end(), cmp);

    for(int i = 1; i <= N; i++) 
        root[i] = i;

    for(Edge edge: edges) {
        if(Find(edge.node1 , edge.node2 )) continue;

        sum += edge.weight;
        Union(edge.node1 , edge.node2);
    }

    cout << sum <<"\n";
    
    return 0;
}