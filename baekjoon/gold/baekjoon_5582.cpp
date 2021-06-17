#include <cmath>
#include <iostream>

using namespace std;

const int SIZE = 4001;

string str1, str2;
int dp[SIZE][SIZE];
int maxCount = 0;

int main() {
    cin >> str1 >> str2;

    int str1Size = str1.size(), str2Size = str2.size();
    
    for(int i = 1; i <= str1Size; i++)
        for(int j = 1; j <= str2Size; j++) {
            if(str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            
            maxCount = max(maxCount , dp[i][j]);
        }

    cout << maxCount <<"\n";

    return 0;
}