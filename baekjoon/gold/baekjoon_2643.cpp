#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int N;
vector<pair<int, int>> rect(100);

int main() {
    cin >> N;
    
    for(int i = 0, a, b; i < N; i++) {
        cin >> a >> b;
        if(a > b) rect[i] = {a, b};
        else rect[i] = {b, a};
    }
    
    sort(rect.begin(), rect.end(), greater<pair<int,int>>());
    
    vector<int> dp(N, -1);
    
    dp[0] = 1;
    for(int i = 1; i < N; i++) {
        for(int j = 0; j < i; j++)
            if(rect[j].first >= rect[i].first && rect[j].second >= rect[i].second)
                dp[i] = max(dp[i], dp[j]);
        
        dp[i]++;
    }
    
    cout << *max_element(dp.begin(), dp.end()) << "\n";
    
    return 0;
}