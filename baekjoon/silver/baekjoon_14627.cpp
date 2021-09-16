#include <algorithm>
#include <iostream>

using namespace std;

long long len[1000001];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int S, N;
    cin >> S >> N;

    long long left = 1, right = -1;
    for(int i = 0; i < S; i++) {
        cin >> len[i];
        
        if(right < len[i]) right = len[i];
    }

    while (left <= right)
    {
        long long mid = (left + right) / 2;

        long long cnt = 0;
        for(int i = 0; i < S; i++) 
            cnt += (len[i] / mid);
        
        if(cnt >= N) left = mid + 1;
        else right = mid - 1;
    }

    long long remain = 0;
    long long leftcnt = 0;
    for(int i = 0 ; i < S; i++) {
        remain += (len[i] % right);
        leftcnt += (len[i] / right);
    }

    cout << remain + right * (leftcnt - N) << "\n";

    return 0;
}