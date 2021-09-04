#include <vector>
#include <iostream>

using namespace std;

int line[100001];
vector<int> dp;

int binarySearch(int l, int r, int target) {
    while (l < r)
    {
        int mid = (l + r) / 2;
        if(dp[mid] < target) l = mid + 1;
        else r = mid;
    }

    return r;
}

int main() {
    int N;
    cin >> N;
    
    for(int i = 0; i < N; i++)
        cin >> line[i];
    
    dp.push_back(-1);

    for(int i = 0; i < N; i++) {
        if (line[i] > dp.back())
            dp.push_back(line[i]);
        else {
            int idx = binarySearch(0, dp.size() - 1, line[i]);
            dp[idx] = line[i];
        }
    }

    cout << N - dp.size() + 1 << "\n";

    return 0;
}