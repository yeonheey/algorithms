#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

const int SIZE = 801;
const int MAX = 800001;

int N, E;
int v1, v2;
bool flag1 = false, flag2 = false;
vector<vector<pair<int, int>> > edges(SIZE);
int dist[SIZE];


void dijkstra(int start) {
    for(int i = 1; i <= N; i++)
        dist[i] = MAX;

    priority_queue<pair<int, int>> pq;
    pq.push({start, 0});
    dist[start] = 0;

    while (!pq.empty()) {
        int cur = pq.top().first;
        int curDist = pq.top().second;
        pq.pop();

        if(dist[cur] < curDist) continue;

        for(int i = 0; i < edges[cur].size(); i++) {
            int next = edges[cur][i].first;
            int nextDist = curDist + edges[cur][i].second;

            if(nextDist < dist[next]) {
                dist[next] = nextDist;
                pq.push({next, nextDist});
            }
        }
    }
}

void findShortest() {
    int result1 = 0, result2 = 0;

    dijkstra(v1);
    if(dist[v2] == MAX) {
        cout <<"-1\n";
        return;
    }

    result1 += dist[v2];
    result2 += dist[N];

    dijkstra(1);
    result1 += dist[v1];
    result2 += dist[v2];

    dijkstra(v2);
    result1 += dist[N];
    result2 += dist[v1];

    result1 = min(result1, result2);

    if(result1 >= MAX)
        cout << "-1\n";
    else 
        cout << result1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N>> E;
    for(int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        edges[a].push_back( {b, c} );
        edges[b].push_back( {a, c} );
    }

    cin >> v1 >> v2;

    findShortest();

    return 0;
}