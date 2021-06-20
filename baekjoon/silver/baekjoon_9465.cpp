#include <memory.h>
#include <cmath>
#include <iostream>

using namespace std;

int arr[2][100001];
int score[2][100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, N;
    cin >> T;
    
    while(T-- > 0) {
        cin >> N;

        for(int i = 0; i < 2; i++) 
            for(int j = 1; j <= N; j++)
                cin >> arr[i][j];
        
        memset(score, 0, sizeof(score));
        score[0][1] = arr[0][1], score[1][1] = arr[1][1];

        for(int i = 2; i <= N; i++) {
            score[0][i] = max(score[1][i - 1], score[1][i -2]) + arr[0][i];
            score[1][i] = max(score[0][i - 1], score[0][i -2]) + arr[1][i];
        }

        cout << max(score[0][N], score[1][N]) << "\n";
    }

    return 0;
}