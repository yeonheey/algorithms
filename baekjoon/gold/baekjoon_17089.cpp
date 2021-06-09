#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int N, M;
int minCost = 999999999;
vector<int> edges[4000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        edges[a - 1].push_back(b - 1);
        edges[b - 1].push_back(a - 1);
    }

    for(int i = 0; i < N; i++) {
        if(edges[i].size() < 2) continue;
        
        int Size = edges[i].size();
        for(int j = 0; j < Size; j++) {
            int node1 = edges[i][j];

            for(int k = j + 1; k < Size; k++) {
                int node2 = edges[i][k];

                if( find(edges[node1].begin(), edges[node1].end(), node2) == edges[node1].end() ) continue;

                int sumCost = edges[i].size() + edges[node1].size() + edges[node2].size() - 6;
                minCost = min(minCost, sumCost);
            }
        }
    }

    if(minCost == 999999999)
        cout <<"-1\n";
    else
        cout << minCost << "\n";

    return 0;
}