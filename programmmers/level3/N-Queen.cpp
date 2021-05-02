#include <vector>
#include <cmath>

using namespace std;

bool isPossible(vector<int>& board, int row)
{
    for(int r = 0; r < row; r++)
    {
        if(board[r] == board[row]) return false;
        if(abs(board[row] - board[r]) == (row - r)) return false;
    }
    
    return true;
}

void checkQueen(vector<int>& board, int& answer, int row)
{
    if(row == board.size())
    {
        answer++; return;
    }
    
    for(int c = 0; c < board.size(); c++)
    {
        board[row] = c;
        
        if(isPossible(board, row)) 
            checkQueen(board, answer, row + 1);
    }
}

int solution(int n) {
    int answer = 0;
    vector<int> board(n, 0);
    
    checkQueen(board, answer, 0);
    
    return answer;
}