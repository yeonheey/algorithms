#include <memory.h>
#include <iostream>

using namespace std;

int vip[41] = {0, };
int dp[41];

int main() {
    int N, M;
    cin >> N >> M;

    for(int i = 1; i <= M; i++) cin >> vip[i];

    memset(dp, 0, sizeof(dp));
    dp[0] = dp[1] = 1;
    
    for(int i = 2; i <= N; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    int result = 1;
    for(int i = 1; i <= M; i++) 
        result *= dp[vip[i] - 1 - vip[i - 1]];
    
    result *= dp[N - vip[M]];

    cout << result << "\n";

    return 0;
}