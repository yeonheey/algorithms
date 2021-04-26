#include <vector>
#include <cmath>

using namespace std;

int solution(vector<vector<int>> board)
{
	int answer = board[0][0];

	int rows = board.size();
	int cols = board[0].size();

	vector<vector<int>> length(rows, vector<int>(cols));

	for (int i = 1; i < rows; i++)
		for (int j = 1; j < cols; j++)
		{
			if (board[i][j] == 0) continue;

			board[i][j] = min(min(board[i - 1][j], board[i][j - 1]), board[i - 1][j - 1]) + 1;
			answer = max(answer, board[i][j]);
		}

	answer *= answer;
	return answer;
}