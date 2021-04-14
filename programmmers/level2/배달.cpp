#include <limits.h>
#include <queue>
#include <vector>

using namespace std;

int solution(int N, vector<vector<int> > road, int K) {
	int count = 0, start = 1;

	vector< vector<pair<int, int>> > roads(N + 1);
	vector<int> dist(N + 1, INT_MAX); //start~ N : min_distance

	for (vector<int> way : road) {
		roads[way[0]].push_back({ way[1], way[2] });
		roads[way[1]].push_back({ way[0], way[2] });
	}

	//dijkstra
	dist[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
	pq.push({ start, 0 });

	while (!pq.empty()) {
		int village = pq.top().first;
		int time = pq.top().second;
		pq.pop();

		if (dist[village] < time) continue;

		for (pair<int, int> way_info : roads[village]) {
			int next_village = way_info.first;
			int next_time = time + way_info.second;

			if (next_time < dist[next_village]) {
				dist[next_village] = next_time;
				pq.push({ next_village, next_time });
			}
		}
	}

	for (int i = 1; i <= N; i++)
		if (dist[i] <= K)
			count++;

	return count;
}
