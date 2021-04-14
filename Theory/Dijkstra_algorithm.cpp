#include <vector>
#include <queue>
#include <iostream>

using namespace std;

const int MAX_VALUE = 9999999999;
const int SIZE = 6;

//Graph
const vector<vector<int>> graph1 = {
	{0, 2, 5, 1, MAX_VALUE, MAX_VALUE},
	{2, 0, 3, 2, MAX_VALUE, MAX_VALUE},
	{5, 3, 0, 3, 1, 5},
	{1, 2, 3, 0, 1,MAX_VALUE},
	{MAX_VALUE, MAX_VALUE, 1, 1, 0, 2},
	{MAX_VALUE, MAX_VALUE, 5, MAX_VALUE, 2,0}
};

const vector<vector<pair<int, int>> > graph2 = {
	{{1, 2}, {2, 5}, {3, 1}},
	{{0, 2}, {2, 3}, {3, 2}},
	{{0, 5}, {1, 3}, {3, 3}, {4, 1}, {5, 5}},
	{{0, 1}, {1, 2}, {2, 3}, {4, 1}},
	{{2, 1}, {3, 1}, {5, 2}},
	{{2, 5}, {4, 2}}
};


///print distance from start to each node
void print_dist(int start, const vector<int>& distance)
{
	cout << "start(" << start << ") to " << endl;
	for (int i = 0; i < distance.size(); i++)
		cout << i << ": " << distance[i] << endl;
}

///return node that have the least cost
int getSmallIndex(const vector<int>& distance, const vector<bool>& isVisited)
{
	int min = MAX_VALUE;
	int idx = 0;

	for (int i = 0; i < SIZE; i++)
		if (distance[i] < min && !isVisited[i]) {
			min = distance[i];
			idx = i;
		}

	return idx;
}

///using DP_O(n^2)
void dijkstra_1(int start) {
	vector<bool> isVisited(SIZE, false);
	vector<int> distance(SIZE);

	//init distance from start to each node
	for (int i = 0; i < SIZE; i++)
		distance[i] = graph1[start][i];

	isVisited[start] = true;

	//for each node, check small distance
	for (int i = 0; i < SIZE - 2; i++)
	{
		int cur_node = getSmallIndex(distance, isVisited);
		isVisited[cur_node] = true;

		for (int j = 0; j < SIZE; j++)
			if (!isVisited[j])
				if (distance[cur_node] + graph1[cur_node][j] < distance[j])
					distance[j] = distance[cur_node] + graph1[cur_node][j];
	}

	print_dist(start, distance);
}

///using heap(priority_queue)_O(nlogn)
void dijkstra_2(int start) {
	vector<int> distance(SIZE, MAX_VALUE);
	priority_queue<pair<int, int>> pq; //node, cost

	distance[start] = 0;
	pq.push({ start, 0 });

	while (!pq.empty())
	{
		int cur_node = pq.top().first;
		int dist = pq.top().second;
		pq.pop();

		//no need to update distance
		if (distance[cur_node] < dist) continue;

		for (pair<int, int> node_info : graph2[cur_node]) {
			int next_node = node_info.first;
			int next_dist = dist + node_info.second;

			if (distance[next_node] > next_dist) {
				distance[next_node] = next_dist;
				pq.push({ next_node, next_dist });
			}
		}
	}

	print_dist(start, distance);
}

int main() {
	int start = 0;
	dijkstra_1(start);
	dijkstra_2(start);

	return 0;
}
