#include <iostream>

using namespace std;

int N, M;
int root[500001];

int getParent(int x) {
    if(root[x] == x) return x;

    return ( root[x] = getParent(root[x]) );
}

void Union(int x, int y) {
    x = getParent(x), y = getParent(y);
    if(x < y) root[y] = x;
    else root[x] = y;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for(int i = 1; i <= N; i++) 
        root[i] = i;

    int node1, node2, result = 0;
    bool isFound = false;

    for(int m = 0; m < M; m++) {
        cin >> node1 >> node2;

        if(isFound) continue;

        if(getParent(node1) == getParent(node2)) {
            isFound = true;
            result = m + 1;
        }
        else
            Union(node1, node2);
    }

    cout << result <<"\n";

    return 0;
}