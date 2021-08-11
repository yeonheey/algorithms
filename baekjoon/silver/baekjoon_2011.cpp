#include <string>
#include <iostream>

using namespace std;

const int MOD = 1000000;

int digits[5001];
int dp[5001];

int main() {
    string str;
    cin >> str;

    int len = str.size();
    for(int i = 1; i <= len; i++) 
        digits[i] = str[i - 1] - '0';
    
    if(len < 1 || str[0] == '0') {
        cout << "0\n";
        return 0;
    }
    
    dp[0] = dp[1] = 1;
    for(int i = 2; i <= len; i++) {
        if(digits[i] < 10 && digits[i] > 0)
            dp[i] = (dp[i] + dp[i - 1]) % MOD;
        
        int number = digits[i - 1] * 10 + digits[i];
        if(number >= 10 && number <= 26)
            dp[i] = (dp[i] + dp[i - 2]) % MOD;
    }

    cout << dp[len] << "\n";

    return 0;
}