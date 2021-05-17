#include <vector>
#include <algorithm>
using namespace std;
int solution(vector<int> sticker)
{
    int sum = 0;
    int size = sticker.size();
    vector<int> dp(size);
    
    if(size == 1) return sticker[0];
    
    //1. 첫번째 스티커를 뜯은 경우
    dp[0] = sticker[0];
    dp[1] = dp[0];
    
    for (int i = 2; i < size - 1; i++)
        dp[i] = max(dp[i - 1], dp[i - 2] + sticker[i]);
    
    sum  = max(sum, dp[size - 2]);
    
    //2. 첫번째 스티커를 뜯지 않은 경우
    dp[0] = 0;
    dp[1] = sticker[1];
    
    for(int i = 2; i < size; i++)
        dp[i] = max(dp[i - 1], dp[i - 2] + sticker[i]);
    
    sum = max(sum, dp[size - 1]);
    return sum;
}