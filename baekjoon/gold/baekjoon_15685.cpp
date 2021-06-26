#include <stack>
#include <iostream>

using namespace std;

const int SIZE = 101;

int N;
bool board[SIZE][SIZE];

stack<int> dir_info;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

void make_generation(int& nx, int& ny) {
    stack<int> temp = dir_info;

    while (!temp.empty())
    {
        int dir = (temp.top() + 1) % 4; temp.pop();

        nx = nx + dx[dir];
        ny = ny + dy[dir];

        board[nx][ny] = true;
        
        dir_info.push(dir);
    }
}

int main() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        int x, y, d, g; 
        cin >> x >> y >> d >> g;

        while (!dir_info.empty()) dir_info.pop();
        
        dir_info.push(d);

        //0 generation
        int nx = x + dx[d];
        int ny = y + dy[d];

        board[x][y] = true;
        board[nx][ny] = true;

        for(int j = 0; j < g; j++) //1~ generation
            make_generation(nx, ny);
    }

    int rect = 0;
    for(int i = 0; i < SIZE - 1; i++) 
        for(int j = 0; j < SIZE - 1; j++) 
            if(board[i][j] && board[i + 1][j] && board[i][j + 1] && board[i + 1][j + 1])
                rect++;
    
    cout << rect << "\n";

    return 0;
}