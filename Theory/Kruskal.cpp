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

const int MAXSIZE = 100;
int root[MAXSIZE];

bool cmp(Edge& e1, Edge& e2) {
    return (e1.weight < e2.weight);
}

//check cycle (using union-find algorithm)
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
    int n = 11, sum = 0;
    vector<Edge> edges;

    edges.push_back(Edge(1, 7, 12));
    edges.push_back(Edge(1, 4, 28));
    edges.push_back(Edge(1, 2, 67));
    edges.push_back(Edge(1, 5, 17));
    edges.push_back(Edge(2, 4, 24));
    edges.push_back(Edge(2, 5, 62));
    edges.push_back(Edge(3, 5, 20));
    edges.push_back(Edge(3, 6, 37));
    edges.push_back(Edge(4, 7, 13));
    edges.push_back(Edge(5, 6, 45));
    edges.push_back(Edge(5, 7, 73));

    //Minimum Spanning Tree
    //sort wieght asc (for select edge for greedy algorithm)
    sort(edges.begin(), edges.end(), cmp);

    for(int i = 0; i < n; i++) 
        root[i] = i;

    for(Edge edge: edges) {
        if(Find(edge.node1 - 1, edge.node2 - 1)) continue;

        sum += edge.weight;
        Union(edge.node1 - 1, edge.node2 - 1);
    }

    cout << sum <<"\n";
    
    return 0;
}