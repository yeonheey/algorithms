#include <iostream>

using namespace std;

long long dp[65][10];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, N;
    for(int i = 0; i < 10; i++)
            dp[1][i] = 1;
        
        for(int pos = 2; pos <= 64; pos++)
            for(int i = 0; i < 10; i++)
                for(int j = i; j < 10; j++) 
                    dp[pos][i] += dp[pos - 1][j];
    cin >> T;

    while(T-- > 0) {
        cin >> N;

        long long result = 0;

        for(int i = 0; i < 10; i++)
            result += dp[N][i];

        cout << result <<"\n";
    }

    return 0;
}