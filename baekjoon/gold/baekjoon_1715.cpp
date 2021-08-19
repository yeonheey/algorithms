#include <queue>
#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < N; i++) {
        int card; cin >> card;
        pq.push(card);
    }
    
    int cnt = 0;
    while (!pq.empty())
    {
        int cur = pq.top(); pq.pop();

        if(pq.empty()) break;

        int next = pq.top(); pq.pop();
        pq.push(cur + next);
        cnt += cur + next;
    }
    
    cout << cnt << "\n";

    return 0;
}