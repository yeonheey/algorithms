#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	stack<int> basket;
	int delCount = 0;

	int moveIdx = 0, boardIdx = 0, i;
	while (moveIdx < moves.size())
	{
		boardIdx = moves[moveIdx] - 1;
		i = 0;
		while (i < board.size() && 0 == board[i][boardIdx])
			i++;

		if (i < board.size())
		{
			if (!basket.empty() && board[i][boardIdx] == basket.top())
			{
				basket.pop();
				delCount += 2;
			}
			else
				basket.push(board[i][boardIdx]);

			board[i][boardIdx] = 0;
		}

		moveIdx++;
	}

	return delCount;
}