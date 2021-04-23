#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int MAX_NUM = 999999999;
int N, M;

void dijkstra(vector<vector<pair<int, int>> >& graph, int start)
{
	vector<int> dist(N + 1, MAX_NUM);
	priority_queue<pair<int, int>> pq;
	pq.push({ start, 0 });
	dist[start] = 0;

	while (!pq.empty())
	{
		int node = pq.top().first;
		int cost = pq.top().second;
		pq.pop();

		if (dist[node] < cost) continue;

		for (pair<int, int> node_info : graph[node])
		{
			int next_node = node_info.first;
			int next_cost = cost + node_info.second;

			if (dist[next_node] > next_cost)
			{
				dist[next_node] = next_cost;
				pq.push({ next_node, next_cost });
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		if (dist[i] == MAX_NUM)
			printf("0 ");
		else
			printf("%d ", dist[i]);
	}
	printf("\n");
}

int main()
{
	scanf("%d\n%d", &N, &M);

	vector<vector<pair<int, int>> > graph(N + 1);
	for (int i = 0, src, dst, cost; i < M; i++)
	{
		scanf("%d %d %d", &src, &dst, &cost);
		graph[src].push_back({ dst, cost });
	}

	for (int i = 1; i <= N; i++)
		dijkstra(graph, i);

	return 0;
}