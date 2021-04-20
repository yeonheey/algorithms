#include <cstdio>
#include <utility>
#include <memory.h>

using namespace std;

int R, C, T;
int board[51][51];
int temp_board[51][51];
pair<int, int> robot;

int dir_r[4] = { -1, 1, 0, 0 };
int dir_c[4] = { 0, 0, -1, 1 };

void dust_increase()
{
	for (int r = 0; r < R; r++)
		for (int c = 0; c < C; c++)
		{
			if (board[r][c] == 0) continue;

			int dust = board[r][c], count = 0;

			for (int i = 0; i < 4; i++)
			{
				int next_r = r + dir_r[i];
				int next_c = c + dir_c[i];

				//boundary
				if (next_r < 0 || next_c < 0 || next_r >= R || next_c >= C) continue;

				//check robot
				if (next_c == 0 && (next_r == robot.first || next_r == robot.second)) continue;

				count++;
				temp_board[next_r][next_c] += dust / 5;
			}

			temp_board[r][c] += (dust - (dust / 5) * count);
		}

	for (int r = 0; r < R; r++)
		for (int c = 0; c < C; c++)
			board[r][c] = temp_board[r][c];
}

void robot_cleaning()
{
	int up_r = robot.first, down_r = robot.second;
	int c = 0;

	int prev = 0;
	while (true)
	{
		//blow wind counterclockwise
		if (up_r == robot.first)
		{
			if (c < C - 1) c++;
			else up_r--;
		}
		else if (up_r == 0)
		{
			if (c > 0) c--;
			else up_r++;
		}
		else
		{
			if (c == C - 1) up_r--;
			else up_r++;
		}

		if (up_r == robot.first && c == 0) break;

		//change the location of dust by wind
		int temp = board[up_r][c];
		board[up_r][c] = prev;
		prev = temp;
	}

	prev = 0;
	while (true)
	{
		//blow wind counterclockwise
		if (down_r == robot.second)
		{
			if (c < C - 1) c++;
			else down_r++;
		}
		else if (down_r == R - 1)
		{
			if (c > 0) c--;
			else down_r--;
		}
		else
		{
			if (c == 0) down_r--;
			else down_r++;
		}

		if (down_r == robot.second && c == 0) break;

		//change the location of dust by wind
		int temp = board[down_r][c];
		board[down_r][c] = prev;
		prev = temp;
	}
}

int main()
{
	//input
	scanf_s("%d %d %d", &R, &C, &T);

	for (int r = 0; r < R; r++)
		for (int c = 0; c < C; c++)
			scanf_s("%d", &board[r][c]);

	for (int r = 0; r < R; r++)
		if (board[r][0] == -1)
		{
			robot.first = r;
			robot.second = r + 1;

			board[r][0] = 0, board[r + 1][0] = 0;
			break;
		}

	while (T-- > 0)
	{
		memset(temp_board, 0, sizeof(temp_board));

		//dust increase
		dust_increase();

		//robot operation
		robot_cleaning();
	}

	int sum = 0;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			sum += board[i][j];

	printf("%d\n", sum);

	return 0;
}