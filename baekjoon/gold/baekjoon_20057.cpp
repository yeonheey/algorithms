#include <cstdio>

using namespace std;

const int SPREAD_SIZE = 9;
const int DIR_SIZE = 4;

int N, Left_Sand = 0;
int board[500][500];

char direction[DIR_SIZE] = { 'L', 'D', 'R', 'U' };
int dir_r[DIR_SIZE] = { 0, 1, 0, -1 };
int dir_c[DIR_SIZE] = { -1, 0, 1, 0 };

int ratio[SPREAD_SIZE] = { 1, 1, 7, 7, 10, 10, 2, 2, 5 };

int wind_r[4][10] = {
	{ -1, 1, -1, 1, -1, 1, -2, 2, 0, 0 },
	{ 0, 0, 1, 1, 2, 2, 1, 1, 3, 2},
	{ -1, 1, -1, 1, -1, 1, -2, 2, 0, 0 },
	{ 0, 0, -1, -1, -2, -2, -1, -1, -3, -2} };

int wind_c[4][10] = {
	{ 0, 0, -1, -1, -2, -2, -1, -1, -3, -2},
	{ -1, 1, -1, 1, -1, 1, -2, 2, 0, 0},
	{ 0, 0, 1, 1, 2, 2, 1, 1, 3, 2},
	{-1, 1, -1, 1, -1, 1, -2, 2, 0, 0} };


bool Is_In_Bound(int r, int c)
{
	if (r < 0 || c < 0 || r >= N || c >= N) return false;
	return true;
}

void Change_Direction(int& dir_idx)
{
	dir_idx = (dir_idx + 1) % DIR_SIZE;
}

void Blow_Sand(int r, int c, int dir_idx)
{
	int next_r = r + dir_r[dir_idx];
	int next_c = c + dir_c[dir_idx];

	if (!Is_In_Bound(next_r, next_c)) return;

	if (board[next_r][next_c] == 0) return;

	int init_sand = board[next_r][next_c];

	int sand = board[next_r][next_c];

	for (int i = 0; i < SPREAD_SIZE; i++)
	{
		int spread_r = r + wind_r[dir_idx][i];
		int spread_c = c + wind_c[dir_idx][i];

		int spread_sand = (sand * ratio[i]) / 100;

		if (!Is_In_Bound(spread_r, spread_c))
			Left_Sand += spread_sand;

		else
			board[spread_r][spread_c] += spread_sand;

		init_sand -= spread_sand;
	}

	int spread_r = r + wind_r[dir_idx][9];
	int spread_c = c + wind_c[dir_idx][9];

	if (!Is_In_Bound(spread_r, spread_c))
		Left_Sand += init_sand;
	else
		board[spread_r][spread_c] += init_sand;

	board[next_r][next_c] = 0;
}

int main()
{
	//input
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &board[i][j]);

	//start wind blow
	int move_cnt = 1;
	int cur_r = N / 2, cur_c = N / 2;
	int dir_idx = 0;
	while (move_cnt < N)
	{
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < move_cnt; j++)
			{
				Blow_Sand(cur_r, cur_c, dir_idx);

				cur_r += dir_r[dir_idx];
				cur_c += dir_c[dir_idx];
			}

			Change_Direction(dir_idx);
		}

		move_cnt++;
	}

	for (int j = 0; j < move_cnt; j++)
	{
		Blow_Sand(cur_r, cur_c, dir_idx);

		cur_r += dir_r[dir_idx];
		cur_c += dir_c[dir_idx];
	}

	printf("%d\n", Left_Sand);

	return 0;
}
