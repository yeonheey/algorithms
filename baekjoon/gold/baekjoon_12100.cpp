//2048(Easy)
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int SIZE = 20;

int n;
vector<vector<int>> board;

int max_num = 0;

void swipe(int dir) {
	queue<int> q;

	if (0 == dir) { //위
		for (int c = 0; c < n; c++) {
			//열 별로 값들 확인
			for (int r = 0; r < n; r++)
			{
				if (board[r][c] != 0)
					q.push(board[r][c]);
				
				board[r][c] = 0; //init to zero
			}

			int i = 0; //0 ~ n - 1
			
			while (!q.empty())
			{
				int val = q.front(); q.pop();
			
				if (board[i][c] == 0)
					board[i][c] = val;
				else if (val == board[i][c]) {
					board[i][c] *= 2;
					i++;
				}
				else {
					i++;
					board[i][c] = val;
				}
			}
		}
	}
	else if (1 == dir) { //아래
		for (int c = 0; c < n; c++)
		{
			for (int r = n - 1; r >= 0; r--)
			{
				if (board[r][c] != 0)
					q.push(board[r][c]);
				
				board[r][c] = 0;
			}

			int i = n - 1; //n - 1 ~ 0
			
			while (!q.empty())
			{
				int val = q.front(); q.pop();
			
				if (board[i][c] == 0)
					board[i][c] = val;
				else if (val == board[i][c]) {
					board[i][c] *= 2;
					i--;
				}
				else {
					i--;
					board[i][c] = val;
				}
			}
		}
	}
	else if (2 == dir) {//좌
		for (int r = 0; r < n; r++)
		{
			for (int c = 0; c < n; c++)
			{
				if (board[r][c] != 0)
					q.push(board[r][c]);
				
				board[r][c] = 0;
			}

			int i = 0; //0 ~ 
			
			while (!q.empty())
			{
				int val = q.front(); q.pop();
				
				if (board[r][i] == 0)
					board[r][i] = val;
				else if (val == board[r][i]) {
					board[r][i] *= 2;
					i++;
				}
				else {
					i++;
					board[r][i] = val;
				}
			}
		}
	}
	else if (3 == dir) {//우
		for (int r = 0; r < n; r++)
		{
			for (int c = n - 1; c >= 0; c--)
			{
				if (board[r][c] != 0)
					q.push(board[r][c]);
				
				board[r][c] = 0;
			}
			
			int i = n - 1;
			
			while (!q.empty())
			{
				int val = q.front(); q.pop();

				if (board[r][i] == 0)
					board[r][i] = val;
				else if (val == board[r][i]) {
					board[r][i] *= 2;
					i--;
				}
				else {
					i--;
					board[r][i] = val;
				}
			}
		}
	}
}

void copy_arr(vector<vector<int>>& src, vector<vector<int>>& dst) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			dst[i][j] = src[i][j];
}

void dfs(int count) {
	if (count == 5) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				max_num = max(max_num, board[i][j]);

		return;
	}

	vector<vector<int>> temp_board(n, vector<int>(n));
	copy_arr(board, temp_board);

	//swiping
	for (int i = 0; i < 4; i++) //위, 아래, 좌, 우
	{
		swipe(i);
		dfs(count + 1);

		copy_arr(temp_board, board);
	}
}
int main() {
	//input
	scanf("%d", &n);

	board = vector<vector<int>>(n, vector<int>(n));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &board[i][j]);

	dfs(0);

	printf("%d\n", max_num);

	return 0;
}
