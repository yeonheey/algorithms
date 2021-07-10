#include <algorithm>
#include <iostream>

using namespace std;

const int SIZE = 3;

int turn;
int board[SIZE][SIZE];

bool isGameOver(int turn) {
    //horizon
    for(int r = 0; r < SIZE; r++) {
        bool check = true;

        for(int c = 0; c < SIZE; c++) 
            if(turn != board[r][c]) {
                check = false; break;
            }
        
        if(check) return true;
    }

    //vetical
    for(int c = 0; c < SIZE; c++) {
        bool check = true;

        for(int r = 0; r < SIZE; r++) 
            if(turn != board[r][c]) {
                check = false; break;
            }
        
        if(check) return true;
    }

    // diagonal
    if(turn == board[0][0] && turn == board[1][1] && turn == board[2][2]) return true;
    if(turn == board[0][2] && turn == board[1][1] && turn == board[2][0]) return true;

    return false;
}

int game(int cur) {
    if(isGameOver(3 - cur)) return -1;

    int best = 2;

    for(int i = 0; i < SIZE; i++) 
        for(int j = 0; j < SIZE; j++) {
            if(0 != board[i][j]) continue;

            board[i][j] = cur;
            best = min(best, game(3 - cur));
            board[i][j] = 0;
        }
    
    if(best == -2 || best == 0) return 0;
    
    return -best;
}

int main() {
    int cnt = 0;
    for(int i = 0; i < SIZE; i++)
        for(int j = 0; j < SIZE; j++) {
            cin >> board[i][j];

            if(board[i][j] != 0) cnt++;
        }
    
    if(cnt % 2 == 0) turn = 1;
    else turn = 2;

    int result = game(turn);

    if(result == -1) cout << "L\n";
    else if(result == 0) cout << "D\n";
    else cout << "W\n";
    
    return 0;
}