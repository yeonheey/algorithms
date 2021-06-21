#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>
#include <iostream>

using namespace std;

const int MAX = 99999999;

int N, M, Dist, start;
vector<int> road[300001];
vector<int> result;

void find_minDistance(int s) {
    vector<int> dist(N + 1, MAX);

    priority_queue<pair<int, int> > pq;
    pq.push({s, 0});
    dist[s] = 0;

    while(!pq.empty()) {
        int cur_node = pq.top().first;
        int cur_dist = pq.top().second;
        pq.pop();

        if(dist[cur_node] < cur_dist) continue;

        for(int next_node: road[cur_node]) {
            int next_dist = cur_dist + 1;

            if(dist[next_node] > next_dist) {
                dist[next_node] = next_dist;
                pq.push({next_node, next_dist});
            }
        }
    }

    for(int i = 1; i <= N; i++) 
        if(dist[i] == Dist)
            result.push_back(i);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> Dist >> start;

    for(int i = 0, a, b; i < M; i++) {
        cin >> a >> b;
        road[a].push_back(b);
    }

    //start에서 모든 노드까지의 최소 거리 저장
    find_minDistance(start);
    
    if(result.empty())
        cout << "-1\n";
    else {
        sort(result.begin(), result.end());
        for(int i = 0; i < result.size(); i++)
            cout << result[i] << "\n";
    }

    return 0;
}