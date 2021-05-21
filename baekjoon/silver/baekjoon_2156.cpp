#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int wine[10001];
int dp[10001] = {0, };

int main() {
    scanf("%d", &n);
    
    for(int i = 1; i <= n; i++)
        scanf("%d", &wine[i]);
    
    dp[1] = wine[1];
    if(n > 1)
        dp[2] = wine[1] + wine[2];
    if(n > 2)
        for(int i = 3; i <= n; i++)
            dp[i] = max(dp[i - 1], max(wine[i] + dp[i - 2], wine[i] + wine[i - 1] + dp[i - 3]) );
    
    printf("%d\n", dp[n]);
    
    return 0;
}