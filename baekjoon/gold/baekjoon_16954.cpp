#include <queue>
#include <memory.h>
#include <iostream>

using namespace std;

const int SIZE = 8;
char board[SIZE][SIZE];
bool isVisited[SIZE][SIZE];

queue<pair<int,int>> q; // character loc

int dr[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
int dc[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

bool characterMove() {
    memset(isVisited, false, sizeof(isVisited));
        
        int qSize = q.size();

        while(qSize--) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            if(board[r][c] == '#') continue;

            if(r == 0 && c == SIZE - 1) return true;

            for(int i = 0; i < 9; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr < 0 || nr >= SIZE || nc < 0 || nc >= SIZE) continue;
                if(isVisited[nr][nc] || board[nr][nc] == '#') continue;

                isVisited[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    
    return false;
}

int main() {
    for(int r = 0; r < SIZE; r++)
        for(int c = 0; c < SIZE; c++) 
            cin >> board[r][c];
    
    q.push({SIZE - 1, 0});

    while(true) 
    {
        if(q.size() == 0) {
            cout << "0\n";
            break;
        }
        if(characterMove()) {
            cout << "1\n";
            break;
        }

        // move wall
        for(int c = 0; c < SIZE; c++)
        board[SIZE - 1][c] = '.';
    
        for(int r = SIZE - 2; r >= 0; r--) 
            for(int c = 0; c < SIZE - 1; c++) 
                if(board[r][c] == '#') {
                    board[r][c] = '.';
                    board[r + 1][c] = '#';
                }   
    }

    return 0;
}