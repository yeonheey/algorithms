#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int dp[101];

int main() {
    int N;
    cin >> N;

    vector<pair<int,int> > edges;
    for(int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;

        edges.push_back({a, b});
    }

    sort(edges.begin(), edges.end());

    int maxMeet = 0;

    dp[0] = 1;
    for(int i = 1; i < N; i++) {
        dp[i] = 1;

        for(int j = 0; j < i; j++) {
            if(edges[i].second > edges[j].second)
                dp[i] = max(dp[i], dp[j] + 1);
        }
        maxMeet = max(maxMeet, dp[i]);
    }

    cout << N - maxMeet << "\n";

    return 0;
}