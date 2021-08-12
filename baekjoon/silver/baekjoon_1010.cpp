#include <iostream>

using namespace std;

const int Size = 31;
int dp[Size][Size] = {0, };

void makeTable() {
    for(int i = 1; i < Size; i++)
        for(int j = i; j < Size; j++) {
            if (i == 1) 
                dp[i][j] = j;
            else if(i == j)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
        }
}

int main() {
    int T; cin >> T;

    makeTable();

    while (T--) {
        int w, e;
        cin >> w >> e;

        cout << dp[w][e] << "\n";
    }

    return 0;
}