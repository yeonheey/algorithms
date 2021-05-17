#include <string>
#include <vector>

using namespace std;

int dp[20000];

int solution(vector<string> strs, string t) {
    int answer = 0;
    int size = t.size();
    dp[0] = size + 1;
    
    for (int i = 0; i < size; i++) {
        dp[i] = size + 1;
        
        for (string str: strs) {
            if (str.size() > i + 1) continue;
            
            int j = 0;
            for (j = 0; j < str.size(); j++) {
                if ( i >= j && (t[i - j] == str[str.size() - 1 - j]) )
                    continue;
                else
                    break;
            }
            
            if (j == str.size()) { //부분문자열을 포함하는 경우
                if (i >= j)
                    dp[i] = min(dp[i], 1 + dp[i - j]);
                else
                    dp[i] = 1;
            }
        }
    }

    answer = dp[size - 1];
    
    if(answer == size + 1) answer = -1;
    return answer;
}