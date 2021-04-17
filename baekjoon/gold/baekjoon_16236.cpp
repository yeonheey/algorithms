#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int SIZE = 20;
int N;
int board[SIZE][SIZE];

int dir_r[4] = { -1, 1, 0, 0 }; //up down left right
int dir_c[4] = { 0, 0, -1, 1 };

struct Fish
{
	int r, c, dist;
	Fish(int _r, int _c, int _dist)
	{
		r = _r, c = _c, dist = _dist;
	}
};

struct Shark
{
	int r, c;
	int measure = 2, eat_count = 0, time = 0;
};

Shark shark;

bool cmp(Fish a, Fish b)
{
	if (a.dist < b.dist) return true;
	else if (a.dist == b.dist)
	{
		if (a.r < b.r) return true;
		else if (a.r == b.r)
		{
			if (a.c < b.c) return true;
			return false;
		}
		return false;
	}
	return false;
}

void find_eatable_fish(vector<Fish>& eat_fish)
{
	vector<vector<bool>> is_visited(N, vector<bool>(N, false));
	queue<pair<pair<int, int>, int>> q; //coord, dist

	q.push({ {shark.r, shark.c}, 0 });
	is_visited[shark.r][shark.c] = true;

	while (!q.empty())
	{
		int r = q.front().first.first;
		int c = q.front().first.second;
		int dist = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int next_r = r + dir_r[i];
			int next_c = c + dir_c[i];

			if (next_r < 0 || next_c < 0 || next_r >= N || next_c >= N) continue;

			if (is_visited[next_r][next_c]) continue;

			//just pass
			if (0 == board[next_r][next_c] || shark.measure == board[next_r][next_c])
			{
				is_visited[next_r][next_c] = true;
				q.push({ {next_r, next_c}, dist + 1 });
			}

			//can eat
			else if (board[next_r][next_c] < shark.measure)
			{
				eat_fish.push_back(Fish(next_r, next_c, dist + 1));

				is_visited[next_r][next_c] = true;
				q.push({ {next_r, next_c}, dist + 1 });
			}
		}
	}
}
int main()
{
	//input
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &board[i][j]);

			if (board[i][j] == 9)
			{
				board[i][j] = 0;
				shark.r = i, shark.c = j;
			}
		}

	//find fishes that shark can eat
	while (true)
	{
		vector<Fish> eat_fish;
		find_eatable_fish(eat_fish);

		if (eat_fish.size() == 0)
			break;
		
		sort(eat_fish.begin(), eat_fish.end(), cmp);

		Fish eatenFish = eat_fish[0];
		board[eatenFish.r][eatenFish.c] = 0;
		
		shark.r = eatenFish.r;
		shark.c = eatenFish.c;
		shark.time += eatenFish.dist;
		
		shark.eat_count++;
		
		if (shark.eat_count == shark.measure)
		{
			shark.measure++;
			shark.eat_count = 0;
		}
	}

	printf("%d\n", shark.time);
	
	return 0;
}
