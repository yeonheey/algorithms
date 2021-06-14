class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        goalWord = word;
        
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++) {
                vector<vector<bool>> isVisited(m, vector<bool>(n, false));
                if(findTheWord(board, i, j, 0, isVisited))
                    return true;
            }
        
        return false;
    }
    
private:
    int m, n;
    string goalWord;
    
    bool findTheWord(vector<vector<char>>& board, int r, int c, int idx, vector<vector<bool>>& isVisited) {
        if(idx == goalWord.size()) return true;
        if(r < 0 || r >= m || c < 0 || c >= n || isVisited[r][c]) return false;
        
        if(goalWord[idx] == board[r][c]) {
            //board[r][c] = '.';
            isVisited[r][c] = true;
            
            if(findTheWord(board, r + 1, c, idx + 1, isVisited) ||
               findTheWord(board, r - 1, c, idx + 1, isVisited) ||
               findTheWord(board, r, c - 1, idx + 1, isVisited) ||
               findTheWord(board, r, c + 1, idx + 1, isVisited) ) return true;
            
            //board[r][c] = goalWord[idx];
            isVisited[r][c] = false;
        }
        
        return false;
    }
};