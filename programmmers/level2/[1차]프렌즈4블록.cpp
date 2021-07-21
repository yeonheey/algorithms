#include <string>
#include <set>
#include <vector>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    while(true) {
        //1. find 4 blocks and count
        set<pair<int, int>> loc;
        vector<string> tempBoard = board;
        
        for(int i = 0; i < m - 1; i++)
            for(int j = 0; j < n - 1; j++) {
                if (board[i][j] == '0') continue;
                
                if(board[i][j] == board[i][j + 1] && board[i][j] == board[i + 1][j] && board[i][j] == board[i + 1][j + 1]) {
                    loc.insert({i, j});
                    loc.insert({i, j + 1});
                    loc.insert({i + 1, j + 1});
                    loc.insert({i + 1, j});
                }
            }
        
        if(loc.size() == 0) break;
        
        //2. del all blocks can del
        for(auto& iter: loc) 
            tempBoard[iter.first][iter.second] = '0';
        
        //3. blocks down
        for(int i = m - 2; i >= 0; i--) 
            for(int j = 0; j < n; j++) {
                if(tempBoard[i][j] == '0') continue;
                
                int r = i, c = j;
                while(r + 1 < m && tempBoard[r + 1][c] == '0') {
                    tempBoard[r + 1][c] = tempBoard[r][c];
                    tempBoard[r][c] = '0';
                    
                    r++;
                }
            }
        
        board = tempBoard;
        answer += loc.size();
    }
    
    return answer;
}