#include <deque>
#include <iostream>

using namespace std;

int main() {
    int N; 
    cin >> N;

    deque<pair<int, int> > dq;
    for(int i = 0, num; i < N; i++) {
        cin >> num;
        dq.push_back({i + 1, num});
    }

    int idx = 0, checkN = N;
    for(int i = 0; i < N; i++) {
        cout << dq[idx].first <<" ";

        int step  = dq[idx].second;
        if(step > 0) step--;

        dq.erase(dq.begin() + idx);
        if(--checkN == 0) break;

        idx += step;

        if(idx < 0) idx = (checkN + idx % checkN);
        idx %= checkN;
    }
    cout << "\n";

    return 0;
}