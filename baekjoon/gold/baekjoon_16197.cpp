#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAX = 99999999;

int N, M, result = MAX;
char board[21][21];
bool isVisted[21][21][21][21] = {false, };
pair<int, int> coins[2];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void dropCoin(int r1, int c1, int r2, int c2, int count) {
    if(count > 10 || result < count) return;

    for(int i = 0; i < 4; i++) {
        int nr1 = r1 + dr[i];
        int nc1 = c1 + dc[i];
        int nr2 = r2 + dr[i];
        int nc2 = c2 + dc[i];

        bool drop1 = false, drop2 = false;
        if(nr1 < 0 || nr1 >= N || nc1 < 0 || nc1 >= M) drop1 = true;
        if(nr2 < 0 || nr2 >= N || nc2 < 0 || nc2 >= M) drop2 = true;

        if(drop1 && drop2) continue;
        else if(drop1 || drop2) {
            result = min(result, count);
            return;
        }

        if(board[nr1][nc1] == '#') {
            nr1 = r1; nc1 = c1;
        }
        if(board[nr2][nc2] == '#') {
            nr2 = r2; nc2 = c2;
        }

        dropCoin(nr1, nc1, nr2, nc2, count + 1);
    }
}

int main() {
    cin >> N >> M;

    for(int i = 0, loc = 0; i < N; i++) {
        string temp;
        cin >> temp;

        for(int j = 0; j < M; j++) {
            if(temp[j] == 'o') 
                coins[loc++] = {i, j};
            else 
                board[i][j] = temp[j];
        }
    }

    dropCoin(coins[0].first, coins[0].second, coins[1].first, coins[1].second, 1);

    if(result == MAX) result = -1;
    cout << result << "\n";

    return 0;
}