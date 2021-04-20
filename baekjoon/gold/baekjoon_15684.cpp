#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 999999999;
int N, M, H;
int total_count = MAX;

bool is_connected[32][11]; // 가로-세로선위치

bool check_ladder()
{
	for (int i = 1; i <= N; i++)
	{
		int loc = i;

		for (int j = 1; j <= H; j++)
		{
			if (is_connected[j][loc])
				loc++;

			else if (is_connected[j][loc - 1])
				loc--;
		}

		if (i != loc) return false;
	}

	return true;
}

void add_line(int idx, int cnt)
{
	if (cnt > 3) return;

	if (check_ladder())
	{
		total_count = min(total_count, cnt);
		return;
	}

	for (int i = idx; i <= H; i++)
		for (int j = 1; j <= N; j++)
		{
			if (is_connected[i][j - 1] || is_connected[i][j] || is_connected[i][j + 1])
				continue;

			is_connected[i][j] = true;
			add_line(i, cnt + 1);
			is_connected[i][j] = false;
		}
}

int main()
{
	scanf("%d %d %d", &N, &M, &H);
	
	for (int i = 0; i < M; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		is_connected[a][b] = true;
	}

	//add horizontal line
	add_line(0, 0);
	
	if (total_count != MAX)
		printf("%d\n", total_count);
	else
		printf("-1\n");
	
	return 0;
}
