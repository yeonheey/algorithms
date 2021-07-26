#include <vector>
#include <iostream>

using namespace std;

int R, C, Time;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int main() {
    cin >> R >> C >> Time;

    vector<vector<int> > board(R, vector<int>(C));

    for(int r = 0; r < R; r++)
        for(int c = 0; c < C; c++) {
            char ch; cin >> ch;
            
            if(ch == '.') board[r][c] = 0;
            else board[r][c] = 3;
        }
    
    int time = 1;
    while(time < Time) {
        ++time;

        // 폭탄 설치되지 않은 곳에 설치
        if(time % 2 == 0) {
            for(int r = 0; r < R; r++)
                for(int c = 0; c < C; c++)
                    if(board[r][c] == 0)
                        board[r][c] = time + 3;
        }

        // boom!
        else {
            vector<vector<int> > temp = board;

            for(int r = 0; r < R; r++)
                for(int c = 0; c < C; c++)
                    if(board[r][c] == time) {
                        temp[r][c] = 0;

                        for(int i = 0; i < 4; i++) {
                            int nr = r + dr[i];
                            int nc = c + dc[i];

                            if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
                            temp[nr][nc] = 0;
                        }
                    }
            
            board = temp;
        }
    }

    for (int r = 0; r < R; r++) {
        for(int c = 0; c < C; c++) {
            if(board[r][c] == 0) cout << ".";
            else cout << "O"; 
        }
        cout << "\n";
    }

    return 0;
}